//
// Created by hdelval on 20/03/16.
//

#ifndef LUT_E5_H
#define LUT_E5_H


#include "DefaultState.h"

class E5: public DefaultState
{
public:
    E5();
    virtual bool transitionSemicolon(Automaton * a, Symbol * s);
    virtual bool transitionDefault(Automaton *automaton, Symbol *unknown);
};


#endif //LUT_E5_H
