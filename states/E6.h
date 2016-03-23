//
// Created by hdelval on 22/03/16.
//

#ifndef LUT_E6_H
#define LUT_E6_H


#include "DefaultState.h"

class E6 : public DefaultState
{
public:
    E6();
    virtual bool transitionId(Automaton * automaton, Symbol * s);
};


#endif //LUT_E6_H
