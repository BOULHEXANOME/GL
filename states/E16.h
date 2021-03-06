//
// Created by hdelval on 22/03/16.
//

#ifndef LUT_E16_H
#define LUT_E16_H


#include "DefaultState.h"

class E16 : public DefaultState
{
public:
    E16();
    virtual bool transitionAffectDeclare(Automaton * automaton, Symbol * equalSign);
    virtual bool transitionDefault(Automaton * automaton, Symbol * unknown);
};


#endif //LUT_E16_H
