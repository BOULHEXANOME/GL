//
// Created by hdelval on 08/03/16.
//

#include "AffectInstruct.h"

std::string AffectInstruct::print() const
{
    return variableToChange->print() + " := " + expressionToAffect->print();
}
