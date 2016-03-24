//
// Created by hdelval on 22/03/16.
//

#ifndef LUT_E16_H
#define LUT_E16_H


#include "DefaultState.h"

class E16 : public DefaultState
{
protected:
	std::string expectedSymbols = "=";
	
public:
    E16();
    virtual bool transitionAffectDeclare(Automaton * automaton, Symbol * equalSign);
};


#endif //LUT_E16_H
