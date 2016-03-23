//
// Created by hdelval on 20/03/16.
//

#ifndef LUT_E37_H
#define LUT_E37_H


#include "DefaultState.h"

class E37 : public DefaultState
{
public:
    E37();
    ~E37(){};
   
    virtual bool transitionPlus(Automaton * automaton, Symbol * plus);
    virtual bool transitionCloseParenthesis(Automaton * automaton, Symbol * closeParenthesis);
    virtual bool transitionMinus(Automaton * automaton, Symbol * minus);
    virtual bool transitionOpA(Automaton * automaton, Symbol * opA);
};


#endif //LUT_E37_H
