//
// Created by hdelval on 20/03/16.
//

#ifndef LUT_E9_H
#define LUT_E9_H


#include "DefaultState.h"

class E9 : public DefaultState
{
protected:
	std::string expectedSymbols = "id, val, (, expression, term, factor";
	
public:
    E9();
    ~E9(){};
    virtual bool transitionT(Automaton * automaton, Symbol * s);
    virtual bool transitionF(Automaton * automaton, Symbol * s);
    virtual bool transitionVal(Automaton * automaton, Symbol * s);
    virtual bool transitionE(Automaton * automaton, Symbol * s);
    virtual bool transitionId(Automaton * automaton, Symbol * s);
    /*virtual bool transitionOpenParenthesis(Automaton * automaton, Symbol * s);*/


};


#endif //LUT_E9_H
