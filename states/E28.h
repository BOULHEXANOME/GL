//
// Created by hdelval on 22/03/16.
//

#ifndef LUT_E28_H
#define LUT_E28_H


#include "DefaultState.h"

class E28 : public DefaultState
{
public:
    E28();
    virtual bool transitionComma(Automaton * automaton, Symbol * comma);
    virtual bool transitionSemicolon(Automaton * automaton, Symbol * semicolon);
    virtual bool transitionDefault(Automaton * automaton, Symbol * unknown);
};


#endif //LUT_E28_H
 
