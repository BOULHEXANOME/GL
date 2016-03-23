#ifndef E11_H
#define E11_H

#include "DefaultState.h"

class E11 : public DefaultState
{
	protected:
		std::string expectedSymbols = ":=";
    public:
		E11();
		~E11(){};
		bool transitionAffectInstruct(Automaton * automaton, Symbol * s);
};

#endif
