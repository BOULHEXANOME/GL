//
// Created by hdelval on 08/03/16.
//

#ifndef GL_BINARYEXPRESSION_H
#define GL_BINARYEXPRESSION_H


#include "Expression.h"

class BinaryExpression : public Expression{
protected:
    Expression leftExpr;
    Expression rigthExpr;

    BinaryExpression(const Expression &leftExpr, const Expression &rigthExpr) : rigthExpr(rigthExpr),
                                                                                leftExpr(leftExpr) { }

public:

    /***********************/
    /*** Getters/Setters ***/
    /***********************/
    const Expression & getRigthExpr() const
    {
        return rigthExpr;
    }

    void setRigthExpr(const Expression & rigthExpr)
    {
        BinaryExpression::rigthExpr = rigthExpr;
    }

    const Expression & getLeftExpr() const
    {
        return leftExpr;
    }

    void setLeftExpr(const Expression & leftExpr)
    {
        BinaryExpression::leftExpr = leftExpr;
    }
    /***********************/
    /* End Getters/Setters */
    /***********************/

};


#endif //GL_BINARYEXPRESSION_H
