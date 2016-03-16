//
// Created by hdelval on 08/03/16.
//

#include "MinusExpression.h"

std::string MinusExpression::print() const
{
    return leftExpr->print() + " - " + rigthExpr->print();
}
