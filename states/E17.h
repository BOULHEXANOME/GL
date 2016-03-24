#ifndef E17_H
#define E17_H

#include "DefaultState.h"

class E17 : public DefaultState
{
	protected:
		std::string expectedSymbols = "id";
	
    public:
		E17();
		~E17(){};
		virtual bool transitionId(Automaton * automaton, Symbol * s);
};

#endif
