#ifndef E20_H
#define E20_H

#include "DefaultState.h"

class E20 : public DefaultState
{
	protected:
		std::string expectedSymbols = "comma,;";
	
    public:
		E20();
		~E20(){};
		virtual bool transitionSemicolon(Automaton * automaton, Symbol * s);
		virtual bool transitionComma(Automaton * automaton, Symbol * s);
};

#endif
