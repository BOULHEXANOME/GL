#ifndef E30_H
#define E30_H

#include "DefaultState.h"

class E30 : public DefaultState
{
    public:
        E30();
		~E30(){};
		virtual bool transitionId(Automaton * automaton, Symbol * s);
		virtual bool transitionVal(Automaton * automaton, Symbol * s);
		virtual bool transitionOpeningParenthesis(Automaton * automaton, Symbol * s);
		virtual bool transitionF(Automaton * automaton, Symbol * s);
};

#endif
