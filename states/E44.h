#ifndef E44_H
#define E44_H

#include "DefaultState.h"

class E44 : public DefaultState
{
public:
	E44();
	virtual bool transitionMultiply(Automaton * automaton, Symbol * s);
	virtual bool transitionDivide(Automaton * automaton, Symbol * s);
	virtual bool transitionCloseParenthesis(Automaton * automaton, Symbol * s);
	virtual bool transitionSemicolon(Automaton * automaton, Symbol * s);
	virtual bool transitionPlus(Automaton * automaton, Symbol * s);
	virtual bool transitionMinus(Automaton * automaton, Symbol * s);
	virtual bool transitionDefault(Automaton * automaton, Symbol * unknown);
};

#endif
