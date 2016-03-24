//
// Created by hdelval on 08/03/16.
//

#include "BinaryExpression.h"

Expression* BinaryExpression::optimizeExpression()
{
    std::cout <<  "binary opti"<< std::endl;

    if (this->getLeftExpr()->getType()==E || this->getLeftExpr()->getType()==CONST){
        std::cout << this->getRigthExpr()->getType()<< std::endl;
        if (this->getRigthExpr()->getType()==E || this->getRigthExpr()->getType()==CONST){
            std::cout << this->getLeftExpr()->getType()<< std::endl;
            std::cout << "number" << std::endl;
            return new Number(this->execute());
        } else {
            this->setRigthExpr(this->getRigthExpr()->optimizeExpression());
        }
    } else {
        this->setLeftExpr(this->getLeftExpr()->optimizeExpression());
    }
}
