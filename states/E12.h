//
// Created by hdelval on 22/03/16.
//

#ifndef LUT_E12_H
#define LUT_E12_H


#include "DefaultState.h"

class E12 : public DefaultState
{
protected:
	std::string expectedSymbols = "comma, ;";
	
public:
    E12();
    virtual bool transitionSemicolon(Automaton * automaton, Symbol * semicolon);
};


#endif //LUT_E12_H
