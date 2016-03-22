#ifndef E14_H
#define E14_H

#include "DefaultState.h"

class E14 : public DefaultState
{
    public:
		E14();
		~E14(){};
		bool transitionVal(Automaton * automaton, Symbol * s);
		bool transitionF(Automaton * automaton, Symbol * s);
		bool transitionT(Automaton * automaton, Symbol * s);
		bool transitionE(Automaton * automaton, Symbol * s);
		bool transitionId(Automaton * automaton, Symbol * s);
		bool transitionOpenParenthesis(Automaton * automaton, Symbol * s);
};

#endif
