//
// Created by hdelval on 22/03/16.
//

#ifndef LUT_E8_H
#define LUT_E8_H


#include "DefaultState.h"

class E8 : public DefaultState
{
protected:
	std::string expectedSymbols = "write, read, id, endOfProgram";
	
public:
    E8();
    ~E8(){};
    virtual bool transitionSemicolon(Automaton * automaton, Symbol * s);
};


#endif //LUT_E8_H
