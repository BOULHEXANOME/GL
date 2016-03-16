#ifndef DEFAULTSTATE_H
#define DEFAULTSTATE_H

#include "State.h"

class DefaultState : public State
{
    public:
        DefaultState();
        ~DefaultState();
        
        bool transition(Automaton * automaton, Symbol * s);
        bool transitionPlus(Automaton * automaton, Symbol * s);
        bool transitionMinus(Automaton * automaton, Symbol * s);
        bool transitionMultiply(Automaton * automaton, Symbol * s);
        bool transitionDivide(Automaton * automaton, Symbol * s);
        bool transitionWrite(Automaton * automaton, Symbol * s);
        bool transitionRead(Automaton * automaton, Symbol * s);
        bool transitionAffectDeclare(Automaton * automaton, Symbol * s);
        bool transitionAffectInstruct(Automaton * automaton, Symbol * s);
        bool transitionOpenParenthesis(Automaton * automaton, Symbol * s);
        bool transitionCloseParenthesis(Automaton * automaton, Symbol * s);
        bool transitionVar(Automaton * automaton, Symbol * s);
        bool transitionVal(Automaton * automaton, Symbol * s);
        bool transitionDollar(Automaton * automaton, Symbol * s);
        bool transitionConst(Automaton * automaton, Symbol * s);
        bool transitionComma(Automaton * automaton, Symbol * s);
        bool transitionSemicolon(Automaton * automaton, Symbol * s);
        bool transitionId(Automaton * automaton, Symbol * s);
        
        bool transitionError(Automaton * automaton, Symbol * s);
        
        bool transitionP(Automaton * automaton, Symbol * s);
        bool transitionD(Automaton * automaton, Symbol * s);
        bool transitionD_Prime(Automaton * automaton, Symbol * s);
        bool transitionId_Liste(Automaton * automaton, Symbol * s);
        bool transitionAff(Automaton * automaton, Symbol * s);
        bool transitionI(Automaton * automaton, Symbol * s);
        bool transitionI_Prime(Automaton * automaton, Symbol * s);
        bool transitionE(Automaton * automaton, Symbol * s);
        bool transitionT(Automaton * automaton, Symbol * s);
        bool transitionF(Automaton * automaton, Symbol * s);
        bool transitionOpA(Automaton * automaton, Symbol * s);
        bool transitionOpM(Automaton * automaton, Symbol * s);
};

#endif
