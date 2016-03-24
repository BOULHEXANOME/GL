//
// Created by hdelval on 08/03/16.
//

#include "PlusExpression.h"

std::string PlusExpression::print() const
{
    return leftExpr->print() + "+" + rigthExpr->print();
}

int PlusExpression::execute() const
{
    return leftExpr->execute() + rigthExpr->execute();
}

bool PlusExpression::analyse() const
{
    return leftExpr->analyse() && rigthExpr->analyse();
}
