//
// Created by hdelval on 08/03/16.
//

#ifndef GL_AFFECTINSTRUCT_H
#define GL_AFFECTINSTRUCT_H


#include "../Symbol.h"
#include "Expression.h"
#include "Variable.h"

class AffectInstruct : public Symbol
{
private:
    Expression* expressionToAffect;
    Variable* variableToChange;
public:
    AffectInstruct(Variable * variableToChange,
                   Expression * expressionToAffect) : expressionToAffect(expressionToAffect),
                                                      variableToChange(variableToChange) { }
    /***********************/
    /*** Getters/Setters ***/
    /***********************/

    Expression * getExpressionToAffect() const
    {
        return expressionToAffect;
    }

    void setExpressionToAffect(Expression * expressionToAffect)
    {
        AffectInstruct::expressionToAffect = expressionToAffect;
    }

    Variable * getVariableToChange() const
    {
        return variableToChange;
    }

    void setVariableToChange(Variable * variableToChange)
    {
        AffectInstruct::variableToChange = variableToChange;
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
    void optimize();
    /***********************/
    /****** End Methods ****/
    /***********************/
};


#endif //GL_AFFECTINSTRUCT_H
