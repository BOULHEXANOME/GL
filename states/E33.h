#ifndef E33_H
#define E33_H

#include "DefaultState.h"

class E33 : public DefaultState
{
    public:
        E33();
		~E33(){};
		virtual bool transitionId(Automaton * automaton, Symbol * s);
		virtual bool transitionVal(Automaton * automaton, Symbol * s);
		virtual bool transitionOpenParenthesis(Automaton * automaton, Symbol * s);
};

#endif
