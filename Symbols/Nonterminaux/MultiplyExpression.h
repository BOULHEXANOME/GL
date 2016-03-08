//
// Created by hdelval on 08/03/16.
//

#ifndef GL_MULTIPLYEXPRESSION_H
#define GL_MULTIPLYEXPRESSION_H


#include "BinaryExpression.h"

class MultiplyExpression : public BinaryExpression{

public:
    /***********************/
    /***** Contructors *****/
    /***********************/
    MultiplyExpression(const Expression & leftExpr, const Expression & rigthExpr) : BinaryExpression(leftExpr,rigthExpr){  }
    /***********************/
    /*** End Contructors ***/
    /***********************/


};

#endif //GL_MULTIPLYEXPRESSION_H
