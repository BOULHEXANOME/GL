//
// Created by hdelval on 08/03/16.
//

#ifndef GL_MULTIPLYEXPRESSION_H
#define GL_MULTIPLYEXPRESSION_H


#include "BinaryExpression.h"

class MultiplyExpression : public BinaryExpression
{

public:
    /***********************/
    /***** Contructors *****/
    /***********************/
    MultiplyExpression(Expression * leftExpr, Expression * rigthExpr) : BinaryExpression(leftExpr,rigthExpr){  }
    /***********************/
    /*** End Contructors ***/
    /***********************/


    /***********************/
    /******** Methods ******/
    /***********************/
    virtual std::string print() const;
    virtual int execute() const;
    virtual bool analyse();
    virtual Expression* optimizeExpression();
    /***********************/
    /****** End Methods ****/
    /***********************/
};

#endif //GL_MULTIPLYEXPRESSION_H
