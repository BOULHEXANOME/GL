#ifndef E34_H
#define E34_H

#include "DefaultState.h"

class E34 : public DefaultState
{
	protected:
		std::string expectedSymbols = "*, /, ;, +, -, )";
	
    public:
		E34();
		~E34(){};
		bool transitionSemicolon(Automaton * automaton, Symbol * s);/*
		bool transitionMultiply(Automaton * automaton, Symbol * s);
		bool transitionDivide(Automaton * automaton, Symbol * s);
		bool transitionClosingParenthesis(Automaton * automaton, Symbol * s);
		bool transitionPlus(Automaton * automaton, Symbol * s);
		bool transitionMinus(Automaton * automaton, Symbol * s);*/
};

#endif
