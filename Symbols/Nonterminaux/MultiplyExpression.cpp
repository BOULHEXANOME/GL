//
// Created by hdelval on 08/03/16.
//

#include "MultiplyExpression.h"

std::string MultiplyExpression::print() const
{
    return leftExpr->print() + " * " + rigthExpr->print();
}

int MultiplyExpression::execute() const
{
    return leftExpr->execute() * rigthExpr->execute();
}
