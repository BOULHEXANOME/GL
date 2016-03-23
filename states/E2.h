#ifndef E2_H
#define E2_H

#include "DefaultState.h"

class E2 : public DefaultState
{
	
protected:
	std::string expectedSymbols = "one or many id";
	
public:
	E2();
	~E2(){};
	virtual bool transitionIdList(Automaton * automaton, Symbol * s);
	virtual bool transitionId(Automaton * automaton, Symbol * s);
};

#endif
