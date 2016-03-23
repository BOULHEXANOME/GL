#ifndef E38_H
#define E38_H

#include "DefaultState.h"

class E38 : public DefaultState
{
	protected:
		std::string expectedSymbols = "id, val, (";

    public:
		E38();
		~E38(){};
		virtual bool transitionId(Automaton * automaton, Symbol * s);
		virtual bool transitionVal(Automaton * automaton, Symbol * s);
		virtual bool transitionOpenParenthesis(Automaton * automaton, Symbol * s);
};

#endif
