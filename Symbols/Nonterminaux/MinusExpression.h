//
// Created by hdelval on 08/03/16.
//

#ifndef GL_MINUSEXPRESSION_H
#define GL_MINUSEXPRESSION_H


#include "BinaryExpression.h"

class MinusExpression : public BinaryExpression{

public:
    /***********************/
    /***** Contructors *****/
    /***********************/
    MinusExpression(const Expression & leftExpr, const Expression & rigthExpr) : BinaryExpression(leftExpr,rigthExpr){  }
    /***********************/
    /*** End Contructors ***/
    /***********************/


};


#endif //GL_MINUSEXPRESSION_H
