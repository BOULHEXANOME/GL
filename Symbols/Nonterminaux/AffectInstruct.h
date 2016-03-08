//
// Created by hdelval on 08/03/16.
//

#ifndef GL_AFFECTINSTRUCT_H
#define GL_AFFECTINSTRUCT_H


#include "../Symbol.h"
#include "Expression.h"
#include "Variable.h"

class AffectInstruct : public Symbol{
private:
    Expression expressionToAffect;
    Variable variableToChange;
public:

    /***********************/
    /*** Getters/Setters ***/
    AffectInstruct(const Variable & variableToChange,
                   const Expression & expressionToAffect) : expressionToAffect(expressionToAffect),
                                                            variableToChange(variableToChange) { }

/***********************/
    const Expression & getExpressionToAffect() const
    {
        return expressionToAffect;
    }

    void setExpressionToAffect(const Expression & expressionToAffect)
    {
        AffectInstruct::expressionToAffect = expressionToAffect;
    }

    const Variable & getVariableToChange() const
    {
        return variableToChange;
    }

    void setVariableToChange(const Variable & variableToChange)
    {
        AffectInstruct::variableToChange = variableToChange;
    }
    /***********************/
    /* End Getters/Setters */
    /***********************/
};


#endif //GL_AFFECTINSTRUCT_H
