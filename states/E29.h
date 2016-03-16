#ifndef E29_H
#define E29_H

#include "DefaultState.h"

class E29 : public DefaultState
{
    public:
        E29() : State(29) {};
		bool transitionMultiply(Automaton * automaton, Symbol * s);
		bool transitionDivide(Automaton * automaton, Symbol * s);
		bool transitionOpM(Automaton * automaton, Symbol * s);
		
		bool transitionPlus(Automaton * automaton, Symbol * s);
		bool transitionMinus(Automaton * automaton, Symbol * s);
		bool transitionClosingParenthesis(Automaton * automaton, Symbol * s);
		bool transitionSemicolon(Automaton * automaton, Symbol * s);
};

#endif
