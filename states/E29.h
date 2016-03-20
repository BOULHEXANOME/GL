//
// Created by hdelval on 20/03/16.
//

#ifndef LUT_E29_H
#define LUT_E29_H


#include "DefaultState.h"

class E29 : public DefaultState
{
public:
    E29();
    ~E29(){};
    // FIXME transitions
    virtual bool transitionSemicolon(Automaton * automaton, Symbol * s);

};


#endif //LUT_E29_H
