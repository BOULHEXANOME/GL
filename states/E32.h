#ifndef E32_H
#define E32_H

#include "DefaultState.h"

class E32 : public DefaultState
{
    public:
        E32();
		~E32(){};
		virtual bool transitionId(Automaton * automaton, Symbol * s);
		virtual bool transitionVal(Automaton * automaton, Symbol * s);
		virtual bool transitionOpeningParenthesis(Automaton * automaton, Symbol * s);
};

#endif
