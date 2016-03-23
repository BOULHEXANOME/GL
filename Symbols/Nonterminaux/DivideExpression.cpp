//
// Created by hdelval on 08/03/16.
//

#include "DivideExpression.h"

std::string DivideExpression::print() const
{
    return leftExpr->print() + " / " + rigthExpr->print();
}

int DivideExpression::execute() const
{
    return this->leftExpr->execute() / this->rigthExpr->execute();
}

bool DivideExpression::analyse() const {
    return leftExpr->analyse() && rigthExpr->analyse();
}
