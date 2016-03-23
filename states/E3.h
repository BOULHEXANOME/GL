#ifndef E3_H
#define E3_H

#include "DefaultState.h"

class E3 : public DefaultState
{
	protected:
		std::string expectedSymbols = "instructions paragraph, read, write, id, endOfProgramm";

    public:
        E3();
        ~E3(){};
		virtual bool transitionId(Automaton * automaton, Symbol * s);
		virtual bool transitionRead(Automaton * automaton, Symbol * s);
		virtual bool transitionDollar(Automaton * automaton, Symbol * s);
		virtual bool transitionWrite(Automaton * automaton, Symbol * s);
		virtual bool transitionI_Prime(Automaton * automaton, Symbol * s);
};

#endif
