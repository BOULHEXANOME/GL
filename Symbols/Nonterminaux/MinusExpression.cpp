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

bool MinusExpression::analyse()
{
    return leftExpr->analyse() && rigthExpr->analyse();
}

Expression *MinusExpression::optimizeExpression()
{
    leftExpr = leftExpr->optimizeExpression();
    rigthExpr = rigthExpr->optimizeExpression();
    if(leftExpr->getType() == VAL && rigthExpr->getType() == VAL)
    {
        return new Number(leftExpr->execute() - rigthExpr->execute());
    }
    else if(rigthExpr->getType() == VAL && rigthExpr->execute() == 0)
    {
        return leftExpr;
    }
    return this;
}
