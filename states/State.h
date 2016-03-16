#ifndef STATE_H
#define STATE_H

#include <string>
#include <ostream>
#include <memory>
#include "../ast/symbol.h"
#include "../statemachine.h"

class State {
    public:
        //State(int s) : state(s) {};
        //virtual ~State() {};

        virtual bool transition(Automaton & automaton, Symbol & s) = 0; // fction de transition entre les états
        int state() { return state; }
        virtual bool transitionPlus() = 0;
        virtual bool transitionMinus() = 0;
        virtual bool transitionMultiply() = 0;
        virtual bool transitionDivide() = 0;
        virtual bool transitionWrite() = 0;
        virtual bool transitionRead() = 0;
        virtual bool transitionAffectDeclare() = 0;
        virtual bool transitionAffectInstruct() = 0;
        virtual bool transitionOpenParenthesis() = 0;
        virtual bool transitionCloseParenthesis() = 0;
        virtual bool transitionVar() = 0;
        virtual bool transitionVal() = 0;
        virtual bool transitionDollar() = 0;
        virtual bool transitionConst() = 0;
        virtual bool transitionComma() = 0;
        virtual bool transitionSemilicon() = 0;
        virtual bool transitionId() = 0;
        virtual bool transitionError() = 0;

    protected:
        int state;
};

#endif
