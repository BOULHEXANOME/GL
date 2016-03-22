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
    ~E35(){};
    // FIXME transitions
    virtual bool transitionSemicolon(Automaton * automaton, Symbol * semicolon);
    virtual bool transitionCloseParenthesis(Automaton * automaton, Symbol * closeParenthesis);
};


#endif //LUT_E35_H
