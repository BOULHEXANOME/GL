//
// Created by hdelval on 08/03/16.
//

#include "MinusExpression.h"

std::string MinusExpression::print() const
{
    return leftExpr->print() + "-" + rigthExpr->print();
}

int MinusExpression::execute() const
{
    return leftExpr->execute() - rigthExpr->execute();;
}

bool MinusExpression::analyse() const
{
    return leftExpr->analyse() && rigthExpr->analyse();
}
