//
// Created by hdelval on 08/03/16.
//

#ifndef GL_DIVIDEEXPRESSION_H
#define GL_DIVIDEEXPRESSION_H

#include "BinaryExpression.h"

class DivideExpression : public BinaryExpression{

public:
    DivideExpression(const Expression & leftExpr, const Expression & rigthExpr) : BinaryExpression(leftExpr,rigthExpr){  }

};

#endif //GL_DIVIDEEXPRESSION_H
