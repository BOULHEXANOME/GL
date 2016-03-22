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
        // TODO
        std::cerr << "error declare ! print line number&column" << std::endl;
    }
    return 0;
}

