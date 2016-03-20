//
// Created by hdelval on 08/03/16.
//

#include "AffectVarDeclare.h"

std::string AffectVarDeclare::print() const
{
    return "var " + this->variableToDeclare->print() + " = " + this->numberToAffect->print();
}

int AffectVarDeclare::execute() const
{
    if(! Automaton::instance().declareVariable(this->variableToDeclare->getTheName()))
    {
        // TODO
        std::cerr << "error declare ! print line number&column" << std::endl;
    }
    if(!this->isEmpty)
    {
        if(! Automaton::instance().affectVariable(this->variableToDeclare->getTheName(), this->numberToAffect->getTheValue()))
        {
            // TODO
            std::cerr << "error affect ! print line number&column" << std::endl;
        }
    }
    return 0;
}

int AffectVarDeclare::getType() const
{
    return AFFECTDECLARE;
}
