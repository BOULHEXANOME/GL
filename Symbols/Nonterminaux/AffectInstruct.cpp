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
        Automaton::instance().printError(this);
    }

    return 0;
}

bool AffectInstruct::analyse()
{
    if(! Automaton::instance().analyseAffectVariable(this->variableToChange->getTheName()))
    {
        Automaton::instance().printError(this);
        return false;
    }
    return expressionToAffect->analyse();
}

bool AffectInstruct::optimize()
{
    expressionToAffect = expressionToAffect->optimizeExpression();
    if(expressionToAffect->getType() == VAL)
    {
        Automaton::instance().affectVariable(this->variableToChange->getTheName(), this->expressionToAffect->execute(), true);
    }
    return false;
}
