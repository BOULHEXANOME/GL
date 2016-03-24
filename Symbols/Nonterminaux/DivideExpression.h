//
// Created by hdelval on 08/03/16.
//

#ifndef GL_DIVIDEEXPRESSION_H
#define GL_DIVIDEEXPRESSION_H

#include "BinaryExpression.h"

class DivideExpression : public BinaryExpression
{

public:
    DivideExpression(Expression * leftExpr, Expression*& rigthExpr) : BinaryExpression(leftExpr,rigthExpr){  }

    /***********************/
    /******** Methods ******/
    /***********************/
    virtual std::string print() const;
    virtual int execute() const;
    virtual bool analyse() const;
    virtual Expression* optimizeExpression();
    /***********************/
    /****** End Methods ****/
    /***********************/
};

#endif //GL_DIVIDEEXPRESSION_H
