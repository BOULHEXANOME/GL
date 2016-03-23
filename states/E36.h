//
// Created by hdelval on 20/03/16.
//

#ifndef LUT_E36_H
#define LUT_E36_H


#include "DefaultState.h"

class E36 : public DefaultState
{
public:
    E36();
    ~E36(){};
   
    virtual bool transitionVal(Automaton * automaton, Symbol * val);
    virtual bool transitionF(Automaton * automaton, Symbol * F);
    virtual bool transitionT(Automaton * automaton, Symbol * T);
    virtual bool transitionE(Automaton * automaton, Symbol * E);
    virtual bool transitionOpenParenthesis(Automaton * automaton, Symbol * openParentheis);
};


#endif //LUT_E36_H
