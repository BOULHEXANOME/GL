//
// Created by hdelval on 22/03/16.
//

#ifndef LUT_E8_H
#define LUT_E8_H


#include "DefaultState.h"

class E8 : public DefaultState
{
	
public:
    E8();
    virtual bool transitionSemicolon(Automaton * automaton, Symbol * s);
    virtual bool transitionDefault(Automaton *automaton, Symbol *unknown);
};


#endif //LUT_E8_H
