//
// Created by hdelval on 08/03/16.
//

#include "BinaryExpression.h"

Expression* BinaryExpression::optimizeExpression()
{
    if (this->getLeftExpr()->getType()==VAL || this->getLeftExpr()->getType()==VAL){
        if (this->getRigthExpr()->getType()==VAL || this->getRigthExpr()->getType()==VAL){
            return new Number(this->execute());
        } else {
            this->setRigthExpr(this->getRigthExpr()->optimizeExpression());
        }
    } else {
        this->setLeftExpr(this->getLeftExpr()->optimizeExpression());
    }
}
