//
// Created by hdelval on 08/03/16.
//

#include "PlusExpression.h"

std::string PlusExpression::print() const
{
    return leftExpr->print() + " + " + rigthExpr->print();
}
