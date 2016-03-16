#ifndef E44_H
#define E44_H

#include "DefaultState.h"

class E44 : public DefaultState
{
    public:
        E44() : State(44) {};
		bool transitionMultiply(Automaton * automaton, Symbol * s);
		bool transitionDivide(Automaton * automaton, Symbol * s);
		bool transitionOpeningParenthesis(Automaton * automaton, Symbol * s);
		bool transitionSemicolon(Automaton * automaton, Symbol * s);
		bool transitionPlus(Automaton * automaton, Symbol * s);
		bool transitionMinus(Automaton * automaton, Symbol * s);
};

#endif
