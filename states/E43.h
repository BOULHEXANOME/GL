//
// Created by hdelval on 20/03/16.
//

#ifndef LUT_E43_H
#define LUT_E43_H


#include "DefaultState.h"

class E43 : public DefaultState
{
public:
    E43();
    virtual bool transitionDollar(Automaton * automaton, Symbol * dollar);
    virtual bool transitionWrite(Automaton * automaton, Symbol * write);
    virtual bool transitionRead(Automaton * automaton, Symbol * write);
    virtual bool transitionId(Automaton * automaton, Symbol * id);
    virtual bool transitionDefault(Automaton * automaton, Symbol * unknown);
};


#endif //LUT_E43_H
