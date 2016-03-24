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

Expression *PlusExpression::optimizeExpression()
{
    leftExpr = leftExpr->optimizeExpression();
    rigthExpr = rigthExpr->optimizeExpression();
    if(leftExpr->getType() == VAL && rigthExpr->getType() == VAL)
    {
        return new Number(leftExpr->execute() + rigthExpr->execute());
    }
    else if(rigthExpr->getType() == VAL && rigthExpr->execute() == 0)
    {
        return leftExpr;
    }
    else if(leftExpr->getType() == VAL && leftExpr->execute() == 0)
    {
        return rigthExpr;
    }
    return this;
}
