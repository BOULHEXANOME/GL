#ifndef E13_H
#define E13_H

#include "DefaultState.h"

class E13 : public DefaultState
{
    public:
        E13() : State(13) {};
        bool transitionPlus(Automaton * automaton, Symbol * s);
        bool transitionMinus(Automaton * automaton, Symbol * s);
        bool transitionMultiply(Automaton * automaton, Symbol * s);
        bool transitionDivide(Automaton * automaton, Symbol * s);
        bool transitionCloseParenthesis(Automaton * automaton, Symbol * s);
        bool transitionSemilocon(Automaton * automaton, Symbol * s);
        
};

#endif
