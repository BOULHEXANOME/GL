#ifndef DEFAULTSTATE_H
#define DEFAULTSTATE_H

#include "State.h"

class DefaultState : public State
{
    public:
        DefaultState() : State(-1) {};
        bool transition(Automaton & automaton, Symbol & s);
        bool transitionPlus();
        bool transitionMinus();
        bool transitionMultiply();
        bool transitionDivide();
        bool transitionWrite();
        bool transitionRead();
        bool transitionAffectDeclare();
        bool transitionAffectInstruct();
        bool transitionOpenParenthesis();
        bool transitionCloseParenthesis();
        bool transitionVar();
        bool transitionVal();
        bool transitionDollar();
        bool transitionConst();
        bool transitionComma();
        bool transitionSemilicon();
        bool transitionId();
        bool transitionError();
};

#endif
