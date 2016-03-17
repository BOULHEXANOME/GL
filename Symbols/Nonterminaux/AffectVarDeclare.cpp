//
// Created by hdelval on 08/03/16.
//

#include "AffectVarDeclare.h"

std::string AffectVarDeclare::print() const
{
    return "var " + this->variableToDeclare->print() + " = " + this->numberToAffect->print();
}
