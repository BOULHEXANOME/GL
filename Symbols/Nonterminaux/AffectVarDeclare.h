//
// Created by hdelval on 08/03/16.
//

#ifndef GL_AFFECTVARDECLARE_H
#define GL_AFFECTVARDECLARE_H


#include "../Symbol.h"
#include "Number.h"
#include "Variable.h"

class AffectVarDeclare: public Symbol {
private:
    Number numberToAffect;
    Variable variableToDeclare;
    bool isEmpty = true;
public:

    AffectVarDeclare(const Variable & variableToDeclare,
                     const Number & numberToAffect) : numberToAffect(numberToAffect),
                                                      variableToDeclare(variableToDeclare) { isEmpty = false; }
    AffectVarDeclare(const Variable & variableToDeclare) : numberToAffect(Number(0)),
                                                      variableToDeclare(variableToDeclare) { isEmpty = true; }

    /***********************/
    /*** Getters/Setters ***/
    /***********************/
    const Variable & getVariableToDeclare() const
    {
        return variableToDeclare;
    }

    void setVariableToDeclare(const Variable & variableToDeclare)
    {
        AffectVarDeclare::variableToDeclare = variableToDeclare;
    }

    const Number & getNumberToAffect() const
    {
        return numberToAffect;
    }

    void setNumberToAffect(const Number & numberToAffect)
    {
        AffectVarDeclare::numberToAffect = numberToAffect;
        isEmpty = false;
    }

    bool isIsEmpty() const {
        return isEmpty;
    }
    /***********************/
    /* End Getters/Setters */
    /***********************/
};


#endif //GL_AFFECTVARDECLARE_H
