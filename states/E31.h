#ifndef E31_H
#define E31_H

#include "DefaultState.h"

class E31 : public DefaultState
{
    public:
        E31() : State(31) {};
		bool transitionMultiply(Automaton * automaton, Symbol * s);
		bool transitionDivide(Automaton * automaton, Symbol * s);
		bool transitionClosingParenthesis(Automaton * automaton, Symbol * s);
		bool transitionSemicolon(Automaton * automaton, Symbol * s);
		bool transitionPlus(Automaton * automaton, Symbol * s);
		bool transitionMinus(Automaton * automaton, Symbol * s);
};

#endif
