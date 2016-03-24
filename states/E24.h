//
// Created by hdelval on 22/03/16.
//

#ifndef LUT_E24_H
#define LUT_E24_H


#include "DefaultState.h"

class E24 : public DefaultState
{
public:
    E24();
    virtual bool transitionVal(Automaton * automaton, Symbol * val);
    virtual bool transitionDefault(Automaton * automaton, Symbol * unknown);
};


#endif //LUT_E24_H
