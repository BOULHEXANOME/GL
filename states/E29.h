//
// Created by hdelval on 20/03/16.
//

#ifndef LUT_E29_H
#define LUT_E29_H


#include "DefaultState.h"

class E29 : public DefaultState
{
protected:
	std::string expectedSymbols = "*, /, ;, +, -, ), multiplicative or dividing operation";
	
public:
    E29();
    ~E29(){};
    virtual bool transitionSemicolon(Automaton * automaton, Symbol * s);
    virtual bool transitionCloseParenthesis(Automaton * automaton, Symbol * closeParenthesis);
    virtual bool transitionPlus(Automaton * automaton, Symbol * plus);
    virtual bool transitionMinus(Automaton * automaton, Symbol * minus);
    virtual bool transitionDivide(Automaton * automaton, Symbol * divide);
    virtual bool transitionMultiply(Automaton * automaton, Symbol * multiply);
    virtual bool transitionOpM(Automaton * automaton, Symbol * multiply);

};


#endif //LUT_E29_H
