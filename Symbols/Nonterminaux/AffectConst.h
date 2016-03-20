//
// Created by hdelval on 08/03/16.
//

#ifndef GL_AFFECTCONST_H
#define GL_AFFECTCONST_H


#include "../Symbol.h"
#include "Constant.h"
#include "Number.h"

class AffectConst : public Symbol
{
private:
    Constant * constToDeclare;
    Number * numberToAffect;
public:
    AffectConst(Constant * constToDeclare,
                Number * numberToAffect) : constToDeclare(constToDeclare),
                                           numberToAffect(numberToAffect) { }

    /***********************/
    /*** Getters/Setters ***/
    /***********************/
    Number * getNumberToAffect() const
    {
        return numberToAffect;
    }

    void setNumberToAffect(Number * numberToAffect)
    {
        AffectConst::numberToAffect = numberToAffect;
    }

    Constant * getConstToDeclare() const {
        return constToDeclare;
    }

    void setConstToDeclare(Constant * constToDeclare)
    {
        AffectConst::constToDeclare = constToDeclare;
    }
    /***********************/
    /* End Getters/Setters */
    /***********************/

    /***********************/
    /******** Methods ******/
    /***********************/
    virtual std::string print() const;
    virtual int execute() const;
    /***********************/
    /****** End Methods ****/
    /***********************/

};


#endif //GL_AFFECTCONST_H
