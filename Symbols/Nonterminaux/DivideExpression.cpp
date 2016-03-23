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
    int diviser = this->rigthExpr->execute();
    if(diviser == 0)
    {
        std::cerr << "Erreur, division par 0 impossible ";
        Automaton::instance().printError(this);
        return 0;
    }
    return this->leftExpr->execute() / diviser;
}

bool DivideExpression::analyse() const {
    return leftExpr->analyse() && rigthExpr->analyse();
}
