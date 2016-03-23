#ifndef E39_H
#define E39_H

#include "DefaultState.h"

class E39 : public DefaultState
{
	protected:
		std::string expectedSymbols = "id, val, (";

    public:
		E39();
		~E39(){};
		virtual bool transitionId(Automaton * automaton, Symbol * s);
		virtual bool transitionVal(Automaton * automaton, Symbol * s);
		virtual bool transitionOpeningParenthesis(Automaton * automaton, Symbol * s);
};

#endif
