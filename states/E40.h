//
// Created by hdelval on 20/03/16.
//

#ifndef LUT_E40_H
#define LUT_E40_H


#include "DefaultState.h"

class E40 : public DefaultState
{
public:
    E40();
    ~E40(){};
    virtual bool transitionRead(Automaton * a, Symbol * s);
    virtual bool transitionWrite(Automaton * a, Symbol * s);
    virtual bool transitionId(Automaton * a, Symbol * s);
    virtual bool transitionConst(Automaton * a, Symbol * s);
};


#endif //LUT_E40_H
