#ifndef E34_H
#define E34_H

#include "DefaultState.h"

class E34 : public DefaultState
{
    public:
		E34();
		~E34(){};
		virtual bool transitionSemicolon(Automaton * automaton, Symbol * s);
		virtual bool transitionMultiply(Automaton * automaton, Symbol * s);
		virtual bool transitionDivide(Automaton * automaton, Symbol * s);
		virtual bool transitionCloseParenthesis(Automaton * automaton, Symbol * s);
		virtual bool transitionPlus(Automaton * automaton, Symbol * s);
		virtual bool transitionMinus(Automaton * automaton, Symbol * s);
};

#endif
