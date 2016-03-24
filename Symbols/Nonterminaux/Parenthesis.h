//
// Created by hdelval on 08/03/16.
//

#ifndef GL_PARENTHESIS_H
#define GL_PARENTHESIS_H


#include "Expression.h"

class Parenthesis : public Expression
{
private:
    Expression * exprParenthesised;

public:

    /***********************/
    /***** Contructors *****/
    /***********************/
    Parenthesis(Expression *exprParenthesised) : exprParenthesised(exprParenthesised) { }
    /***********************/
    /*** End Contructors ***/
    /***********************/

    /***********************/
    /*** Getters/Setters ***/
    /***********************/
    Expression * getExprParenthesised() const
    {
        return exprParenthesised;
    }

    void setExprParenthesised(Expression * exprParenthesised)
    {
        Parenthesis::exprParenthesised = exprParenthesised;
    }
    /***********************/
    /* End Getters/Setters */
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


#endif //GL_PARENTHESIS_H
