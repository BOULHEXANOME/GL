//
// Created by hdelval on 08/03/16.
//

#ifndef GL_PARENTHESIS_H
#define GL_PARENTHESIS_H


#include "Expression.h"

class Parenthesis : public Expression{
private:
    Expression exprParenthesised;

public:

    /***********************/
    /***** Contructors *****/
    /***********************/
    Parenthesis(const Expression &exprParenthesised) : exprParenthesised(exprParenthesised) { }
    /***********************/
    /*** End Contructors ***/
    /***********************/

    /***********************/
    /*** Getters/Setters ***/
    /***********************/
    const Expression & getExprParenthesised() const
    {
        return exprParenthesised;
    }

    void setExprParenthesised(const Expression & exprParenthesised)
    {
        Parenthesis::exprParenthesised = exprParenthesised;
    }
    /***********************/
    /* End Getters/Setters */
    /***********************/
};


#endif //GL_PARENTHESIS_H
