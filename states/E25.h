//
// Created by hdelval on 22/03/16.
//

#ifndef LUT_E25_H
#define LUT_E25_H


#include "DefaultState.h"

class E25 : public DefaultState
{
protected:
	std::string expectedSymbols = "comma, ;";
	
public:
    E25();
    virtual bool transitionSemicolon(Automaton * automaton, Symbol* semicolon);
};


#endif //LUT_E25_H
