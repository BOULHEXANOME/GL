//
// Created by hdelval on 08/03/16.
//

#ifndef GL_PLUSEXPRESSION_H
#define GL_PLUSEXPRESSION_H


#include "BinaryExpression.h"

class PlusExpression : public BinaryExpression
{
public:
    PlusExpression(Expression * leftExpr, Expression * rigthExpr) : BinaryExpression(leftExpr,rigthExpr){  }

    /***********************/
    /******** Methods ******/
    /***********************/
    virtual std::string print() const;
    virtual int execute() const;
    virtual bool analyse() const;
    /***********************/
    /****** End Methods ****/
    /***********************/
};


#endif //GL_PLUSEXPRESSION_H
