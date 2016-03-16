#ifndef E3_H
#define E3_H

#include "DefaultState.h"

class E3 : public DefaultState
{
    public:
        E3();
        ~E3(){};
		/*bool transitionId(Automaton * automaton, Symbol * s);
		bool transitionRead(Automaton * automaton, Symbol * s);
		bool transitionWrite(Automaton * automaton, Symbol * s);*/
		bool transitionDollar(Automaton * automaton, Symbol * s);
		//bool transitionI_Prime(Automaton * automaton, Symbol * s);
};

#endif
