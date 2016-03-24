#ifndef E27_H
#define E27_H

#include "DefaultState.h"

class E27 : public DefaultState
{
	protected:
		std::string expectedSymbols = "*, /, +, -, ), ;, multiplicative or dividing operation";
	
    public:
		E27();
		~E27(){};/*
		bool transitionMultiply(Automaton * automaton, Symbol * s);
		bool transitionDivide(Automaton * automaton, Symbol * s);
		bool transitionOpM(Automaton * automaton, Symbol * s);*/
		
		bool transitionPlus(Automaton * automaton, Symbol * s);
		bool transitionMinus(Automaton * automaton, Symbol * s);
		bool transitionCloseParenthesis(Automaton * automaton, Symbol * s);
		bool transitionSemicolon(Automaton * automaton, Symbol * s);
};

#endif
