//
// Created by hdelval on 20/03/16.
//

#ifndef LUT_E31_H
#define LUT_E31_H


#include "DefaultState.h"

class E31 : public DefaultState
{
public:
    E31();
    ~E31(){};
    // FIXME transitions
    virtual bool transitionSemicolon(Automaton * automaton, Symbol * semicolon);
};


#endif //LUT_E31_H
