//
// Created by hdelval on 08/03/16.
//

#ifndef GL_AFFECTCONST_H
#define GL_AFFECTCONST_H


#include "../Symbol.h"
#include "Constant.h"
#include "Number.h"

class AffectConst : public Symbol {
private:
    Constant constToDeclare;
    Number numberToAffect;
public:
    AffectConst(const Constant & constToDeclare,
                const Number & numberToAffect) : constToDeclare(constToDeclare),
                                                 numberToAffect(numberToAffect) { }

    /***********************/
    /*** Getters/Setters ***/
    /***********************/
    const Number & getNumberToAffect() const
    {
        return numberToAffect;
    }

    void setNumberToAffect(const Number & numberToAffect)
    {
        AffectConst::numberToAffect = numberToAffect;
    }

    const Constant & getConstToDeclare() const {
        return constToDeclare;
    }

    void setConstToDeclare(const Constant & constToDeclare)
    {
        AffectConst::constToDeclare = constToDeclare;
    }
    /***********************/
    /* End Getters/Setters */
    /***********************/
};


#endif //GL_AFFECTCONST_H
