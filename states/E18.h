//
// Created by hdelval on 20/03/16.
//

#ifndef LUT_E18_H
#define LUT_E18_H


#include "DefaultState.h"

class E18 : public DefaultState
{
protected:
	std::string expectedSymbols = "+, -, ;, additive or subtractive operation";
	
public:
    E18();
    ~E18(){};
    // FIXME transitions
    virtual bool transitionSemicolon(Automaton * automaton, Symbol * semicolon);

};


#endif //LUT_E18_H
