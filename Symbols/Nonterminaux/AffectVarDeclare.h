//
// Created by hdelval on 08/03/16.
//

#ifndef GL_AFFECTVARDECLARE_H
#define GL_AFFECTVARDECLARE_H


#include "../Symbol.h"
#include "Number.h"
#include "Variable.h"

class AffectVarDeclare: public Symbol
{
private:
    Number *numberToAffect;
    Variable *variableToDeclare;
    bool isEmpty = true;
public:

    AffectVarDeclare(Variable * variableToDeclare,
                      Number * numberToAffect) : numberToAffect(numberToAffect),
                                                 variableToDeclare(variableToDeclare) { isEmpty = false; }
    AffectVarDeclare(Variable * variableToDeclare) : numberToAffect(new Number(0)),
                                                     variableToDeclare(variableToDeclare) { isEmpty = true; }

    /***********************/
    /*** Getters/Setters ***/
    /***********************/
    Variable * getVariableToDeclare() const
    {
        return variableToDeclare;
    }

    void setVariableToDeclare(Variable * variableToDeclare)
    {
        this->variableToDeclare = variableToDeclare;
    }

    Number * getNumberToAffect() const
    {
        return numberToAffect;
    }

    void setNumberToAffect(Number * numberToAffect)
    {
        AffectVarDeclare::numberToAffect = numberToAffect;
        isEmpty = false;
    }

    bool isIsEmpty() const
    {
        return isEmpty;
    }
    /***********************/
    /* End Getters/Setters */
    /***********************/

    /***********************/
    /******** Methods ******/
    /***********************/
    virtual std::string print() const;
    virtual int execute() const;
    virtual int getType() const;
    /***********************/
    /****** End Methods ****/
    /***********************/
};

#endif //GL_AFFECTVARDECLARE_H
