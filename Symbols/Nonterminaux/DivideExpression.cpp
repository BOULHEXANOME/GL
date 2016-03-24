//
// Created by hdelval on 08/03/16.
//

#include "DivideExpression.h"

std::string DivideExpression::print() const
{
    return leftExpr->print() + "/" + rigthExpr->print();
}

int DivideExpression::execute() const
{
    return this->leftExpr->execute() / this->rigthExpr->execute();
}

bool DivideExpression::analyse() const {
    return leftExpr->analyse() && rigthExpr->analyse();
}

Expression *DivideExpression::optimizeExpression()
{
    leftExpr = leftExpr->optimizeExpression();
    rigthExpr = rigthExpr->optimizeExpression();
    if(leftExpr->getType() == VAL && rigthExpr->getType() == VAL)
    {
        int divisor = rigthExpr->execute();
        if(divisor == 0)
        {
            std::cerr << "Erreur de division par 0" << std::endl;
            Automaton::instance().printError(this);
            return new Number(0);
        }
        else
        {
            return new Number(leftExpr->execute() / divisor);
        }
    }
    else if(rigthExpr->getType() == VAL && rigthExpr->execute() == 1)
    {
        return leftExpr;
    }
    return this;
}
