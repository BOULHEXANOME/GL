#ifndef E27_H
#define E27_H

#include "DefaultState.h"

class E27 : public DefaultState
{
public:
	E27();
	virtual bool transitionMultiply(Automaton * automaton, Symbol * s);
	virtual bool transitionDivide(Automaton * automaton, Symbol * s);
	virtual bool transitionOpM(Automaton * automaton, Symbol * s);

	virtual bool transitionPlus(Automaton * automaton, Symbol * s);
	virtual bool transitionMinus(Automaton * automaton, Symbol * s);
	virtual bool transitionCloseParenthesis(Automaton * automaton, Symbol * s);
	virtual bool transitionSemicolon(Automaton * automaton, Symbol * s);
};

#endif
