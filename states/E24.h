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
    virtual bool transitionId(Automaton * automaton, Symbol * val);
};


#endif //LUT_E24_H
