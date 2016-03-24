//
// Created by hdelval on 20/03/16.
//

#ifndef LUT_E18_H
#define LUT_E18_H


#include "DefaultState.h"

class E18 : public DefaultState
{
public:
    E18();
    virtual bool transitionSemicolon(Automaton * automaton, Symbol * semicolon);
    virtual bool transitionOpA(Automaton * automaton, Symbol * opa);
    virtual bool transitionPlus(Automaton * automaton, Symbol * plus);
    virtual bool transitionMinus(Automaton * automaton, Symbol * minus);
    virtual bool transitionDefault(Automaton * automaton, Symbol * unknown);

};


#endif //LUT_E18_H
