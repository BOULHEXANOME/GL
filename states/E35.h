//
// Created by hdelval on 20/03/16.
//

#ifndef LUT_E35_H
#define LUT_E35_H


#include "DefaultState.h"

class E35 : public DefaultState
{
public:
    E35();
    virtual bool transitionSemicolon(Automaton * automaton, Symbol * semicolon);
    virtual bool transitionCloseParenthesis(Automaton * automaton, Symbol * closeParenthesis);
    virtual bool transitionPlus(Automaton * automaton, Symbol * plus);
    virtual bool transitionMinus(Automaton * automaton, Symbol * minus);
    virtual bool transitionDivide(Automaton * automaton, Symbol * divide);
    virtual bool transitionMultiply(Automaton * automaton, Symbol * multiply);
    virtual bool transitionDefault(Automaton * automaton, Symbol * unknown);
};


#endif //LUT_E35_H
