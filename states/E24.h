//
// Created by hdelval on 22/03/16.
//

#ifndef LUT_E24_H
#define LUT_E24_H


#include "DefaultState.h"

class E24 : public DefaultState
{
protected:
	std::string expectedSymbols = "val";
	
public:
    E24();
    virtual bool transitionVal(Automaton * automaton, Symbol * val);
};


#endif //LUT_E24_H
