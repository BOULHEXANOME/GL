#ifndef E35_H
#define E35_H

#include "DefaultState.h"

class E35 : public DefaultState
{
    public:
        E35() : State(35) {};
		bool transitionMultiply(Automaton * automaton, Symbol * s);
		bool transitionDivide(Automaton * automaton, Symbol * s);
		bool transitionClosingParenthesis(Automaton * automaton, Symbol * s);
		bool transitionSemicolon(Automaton * automaton, Symbol * s);
		bool transitionPlus(Automaton * automaton, Symbol * s);
		bool transitionMinus(Automaton * automaton, Symbol * s);
};

#endif
