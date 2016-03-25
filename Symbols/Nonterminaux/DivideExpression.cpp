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
    int diviser = rigthExpr->execute();
    if(diviser == 0)
    {
        std::cerr << "Erreur d'execution, division par 0 impossible";
        Automaton::instance().printError(this);
        return 0;
    }
    return this->leftExpr->execute() / diviser;
}

bool DivideExpression::analyse() {
    rigthExpr->resetType();
    if(rigthExpr->getType()==VAL && rigthExpr->execute() == 0)
    {
        std::cerr << "Erreur, division par 0 impossible";
        Automaton::instance().printError(this);
    }
    return leftExpr->analyse() && rigthExpr->analyse();
}

Expression *DivideExpression::optimizeExpression()
{
    rigthExpr->resetType();
    leftExpr = leftExpr->optimizeExpression();
    rigthExpr = rigthExpr->optimizeExpression();
    if(leftExpr->getType() == VAL && rigthExpr->getType() == VAL)
    {
        int divisor = rigthExpr->execute();
        if(divisor == 0)
        {
            std::cerr << "Erreur lors de l'optimisation, division par 0 impossible" << std::endl;
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
