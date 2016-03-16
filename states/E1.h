#ifndef E1_H
#define E1_H

#include "DefaultState.h"

class E1 : public DefaultState
{
    public:
        E1();
        ~E1(){};
        /*bool transitionRead(Automaton * automaton, Symbol * s);
		bool transitionWrite(Automaton * automaton, Symbol * s);
		bool transitionId(Automaton * automaton, Symbol * s);
		bool transitionConst(Automaton * automaton, Symbol * s);
		bool transitionI_Prime(Automaton * automaton, Symbol * s);
		bool transitionD_Prime(Automaton * automaton, Symbol * s);
		bool transitionI(Automaton * automaton, Symbol * s);*/
		bool transitionVar(Automaton * automaton, Symbol * s);
};

#endif
