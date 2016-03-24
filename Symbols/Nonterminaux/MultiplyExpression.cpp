//
// Created by hdelval on 08/03/16.
//

#include "MultiplyExpression.h"

std::string MultiplyExpression::print() const
{
    return leftExpr->print() + "*" + rigthExpr->print();
}

int MultiplyExpression::execute() const
{
    return leftExpr->execute() * rigthExpr->execute();
}

bool MultiplyExpression::analyse() const {
    return leftExpr->analyse() && rigthExpr->analyse();
}

Expression *MultiplyExpression::optimizeExpression()
{
    leftExpr = leftExpr->optimizeExpression();
    rigthExpr = rigthExpr->optimizeExpression();
    if(leftExpr->getType() == VAL && rigthExpr->getType() == VAL)
    {
        return new Number(leftExpr->execute() * rigthExpr->execute());
    }
    else if(rigthExpr->getType() == VAL && rigthExpr->execute() == 1)
    {
        return leftExpr;
    }
    else if(leftExpr->getType() == VAL && leftExpr->execute() == 1)
    {
        return rigthExpr;
    }
    else if((rigthExpr->getType() == VAL && rigthExpr->execute() == 0) || (leftExpr->getType() == VAL && leftExpr->execute() == 0))
    {
        return new Number(0);
    }
    return this;
}
