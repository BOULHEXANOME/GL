//
// Created by hdelval on 22/03/16.
//

#ifndef LUT_E7_H
#define LUT_E7_H


#include "DefaultState.h"

class E7 : public DefaultState
{
public:
    E7();
    virtual bool transitionId(Automaton * automaton, Symbol * id);
};


#endif //LUT_E7_H
