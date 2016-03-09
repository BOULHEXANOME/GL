//
// Created by hdelval on 08/03/16.
//

#ifndef GL_PLUSEXPRESSION_H
#define GL_PLUSEXPRESSION_H


#include "BinaryExpression.h"

class PlusExpression : public BinaryExpression{
public:
    PlusExpression(const Expression & leftExpr, const Expression & rigthExpr) : BinaryExpression(leftExpr,rigthExpr){  }
};


#endif //GL_PLUSEXPRESSION_H
