//
// Created by hdelval on 08/03/16.
//

#include "AffectInstruct.h"

std::string AffectInstruct::print() const
{
    return variableToChange->print() + " := " + expressionToAffect->print();
}

int AffectInstruct::execute() const
{
    if(! Automaton::instance().affectVariable(this->variableToChange->getTheName(), this->expressionToAffect->execute()))
    {
        // TODO
        std::cerr << "error affect instruct ! print line number&column" << std::endl;
    }

    return 0;
}

bool AffectInstruct::analyse() const
{
    if(! Automaton::instance().analyseAffectVariable(this->variableToChange->getTheName()))
    {
        // TODO
        std::cerr << "error affect instruct ! print line number&column" << std::endl;
        return false;
    }
    return true;
}

void AffectInstruct::optimize()
{
    expressionToAffect = expressionToAffect->optimizeExpression();
}
