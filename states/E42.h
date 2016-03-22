#ifndef E42_H
#define E42_H

#include "DefaultState.h"

class E42 : public DefaultState
{
    public:
		E42();
		~E42(){};/*
		bool transitionRead(Automaton * automaton, Symbol * s);
		bool transitionWrite(Automaton * automaton, Symbol * s);
		bool transitionId(Automaton * automaton, Symbol * s);*/
		bool transitionDollar(Automaton * automaton, Symbol * s);
};

#endif
