//
// Created by hdelval on 08/03/16.
//

#include "VarDeclare.h"

std::string VarDeclare::print() const
{
    return "var " + this->variableToDeclare->print();
}

int VarDeclare::execute() const
{
    if(! Automaton::instance().declareVariable(this->variableToDeclare->getTheName()))
    {
        Automaton::instance().printError(this);
    }
    return 0;
}

bool VarDeclare::analyse() const
{
    if(! Automaton::instance().analyseDeclareVariable(this->variableToDeclare->getTheName()))
    {
        Automaton::instance().printError(this);
        return false;
    }
    return true;
}

bool VarDeclare::optimize()
{
    Automaton::instance().declareVariable(this->variableToDeclare->getTheName(), true);
    return false;
}
