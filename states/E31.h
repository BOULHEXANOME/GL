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
    virtual bool transitionSemicolon(Automaton * automaton, Symbol * semicolon);
    virtual bool transitionCloseParenthesis(Automaton * automaton, Symbol * closeParenthesis);
    virtual bool transitionPlus(Automaton * automaton, Symbol * plus);
    virtual bool transitionMinus(Automaton * automaton, Symbol * minus);
    virtual bool transitionDivide(Automaton * automaton, Symbol * divide);
    virtual bool transitionMultiply(Automaton * automaton, Symbol * multiply);
};


#endif //LUT_E31_H
