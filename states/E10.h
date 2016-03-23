#ifndef E10_H
#define E10_H

#include "DefaultState.h"

class E10 : public DefaultState
{
public:
	E10();
	~E10(){};
	virtual bool transitionComma(Automaton * automaton, Symbol * s);
		virtual bool transitionSemicolon(Automaton * automaton, Symbol * s);
};

#endif
