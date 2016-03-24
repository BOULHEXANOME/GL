//
// Created by hdelval on 08/03/16.
//

#ifndef GL_BINARYEXPRESSION_H
#define GL_BINARYEXPRESSION_H


#include "Expression.h"
#include "Number.h"

class BinaryExpression : public Expression
{
protected:
    Expression* leftExpr;
    Expression* rigthExpr;

    BinaryExpression(Expression *leftExpr, Expression *rigthExpr) : rigthExpr(rigthExpr),
                                                                    leftExpr(leftExpr) { }

public:

    /***********************/
    /*** Getters/Setters ***/
    /***********************/
    Expression * getRigthExpr() const
    {
        return rigthExpr;
    }

    void setRigthExpr(Expression * rigthExpr)
    {
        BinaryExpression::rigthExpr = rigthExpr;
    }

    Expression * getLeftExpr() const
    {
        return leftExpr;
    }

    void setLeftExpr(Expression * leftExpr)
    {
        BinaryExpression::leftExpr = leftExpr;
    }
    /***********************/
    /* End Getters/Setters */
    /***********************/

    /***********************/
    /******** Methods ******/
    /***********************/

    Expression* optimizeExpression();

    /***********************/
    /****** End Methods ****/
    /***********************/
};


#endif //GL_BINARYEXPRESSION_H
