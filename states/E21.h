#ifndef E21_H
#define E21_H

#include "DefaultState.h"

class E21 : public DefaultState
{
    public:
		E21();
		~E21(){};
		virtual bool transitionVal(Automaton * automaton, Symbol * s);
		virtual bool transitionF(Automaton * automaton, Symbol * s);
		virtual bool transitionT(Automaton * automaton, Symbol * s);
		//virtual bool transitionId(Automaton * automaton, Symbol * s);
		virtual bool transitionOpenParenthesis(Automaton * automaton, Symbol * s);
};

#endif
