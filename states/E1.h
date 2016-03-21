#ifndef E1_H
#define E1_H

#include "DefaultState.h"

class E1 : public DefaultState
{
public:
	E1();
	~E1(){};
	//virtual bool transitionRead(Automaton * automaton, Symbol * s);
	virtual bool transitionWrite(Automaton * automaton, Symbol * s);
	virtual bool transitionId(Automaton * automaton, Symbol * s);
	//virtual bool transitionConst(Automaton * automaton, Symbol * s);
	virtual bool transitionI_Prime(Automaton * automaton, Symbol * s);
	virtual bool transitionD_Prime(Automaton * automaton, Symbol * s);
	virtual bool transitionI(Automaton * automaton, Symbol * s);
	virtual bool transitionVar(Automaton * automaton, Symbol * s);
};

#endif
