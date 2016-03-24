//
// Created by hdelval on 08/03/16.
//

#ifndef GL_MINUSEXPRESSION_H
#define GL_MINUSEXPRESSION_H


#include "BinaryExpression.h"

class MinusExpression : public BinaryExpression
{

public:
    /***********************/
    /***** Contructors *****/
    /***********************/
    MinusExpression(Expression * leftExpr, Expression * rigthExpr) : BinaryExpression(leftExpr,rigthExpr){  }
    /***********************/
    /*** End Contructors ***/
    /***********************/


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


#endif //GL_MINUSEXPRESSION_H
