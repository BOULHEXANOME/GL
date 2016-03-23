//
// Created by hdelval on 20/03/16.
//

#ifndef LUT_E13_H
#define LUT_E13_H


#include "DefaultState.h"

class E13 : public DefaultState
{
public:
    E13();
    ~E13(){};
    
    virtual bool transitionSemicolon(Automaton * a, Symbol * s);
    virtual bool transitionCloseParenthesis(Automaton * a, Symbol * s);
    virtual bool transitionMinus(Automaton * a, Symbol * s);
    virtual bool transitionPlus(Automaton * a, Symbol * s);
    virtual bool transitionDivide(Automaton * a, Symbol * s);
    virtual bool transitionMultiply(Automaton * a, Symbol * s);
};


#endif //LUT_E13_H
