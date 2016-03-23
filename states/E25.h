//
// Created by hdelval on 22/03/16.
//

#ifndef LUT_E25_H
#define LUT_E25_H


#include "DefaultState.h"

class E25 : public DefaultState
{
public:
    E25();
    virtual bool transitionSemicolon(Automaton * automaton, Symbol* semicolon);
    virtual bool transitionComma(Automaton * automaton, Symbol* comma);
    virtual bool transitionDefault(Automaton * automaton, Symbol * unknown);
};


#endif //LUT_E25_H
