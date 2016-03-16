#ifndef STATE_H
#define STATE_H

#include "../Automaton.h"
class Automaton;

class State {
    public:
        //State(){};
        virtual ~State(){};
        int getState() { return state; }

		
        virtual bool transition(Automaton * automaton, Symbol * s) = 0; // fction de transition entre les états
        
        //Symboles Terminaux
        virtual bool transitionPlus(Automaton * automaton, Symbol * s) = 0;
        virtual bool transitionMinus(Automaton * automaton, Symbol * s) = 0;
        virtual bool transitionMultiply(Automaton * automaton, Symbol * s) = 0;
        virtual bool transitionDivide(Automaton * automaton, Symbol * s) = 0;
        virtual bool transitionWrite(Automaton * automaton, Symbol * s) = 0;
        virtual bool transitionRead(Automaton * automaton, Symbol * s) = 0;
        virtual bool transitionAffectDeclare(Automaton * automaton, Symbol * s) = 0;
        virtual bool transitionAffectInstruct(Automaton * automaton, Symbol * s) = 0;
        virtual bool transitionOpenParenthesis(Automaton * automaton, Symbol * s) = 0;
        virtual bool transitionCloseParenthesis(Automaton * automaton, Symbol * s) = 0;
        virtual bool transitionVar(Automaton * automaton, Symbol * s) = 0;
        virtual bool transitionVal(Automaton * automaton, Symbol * s) = 0;
        virtual bool transitionDollar(Automaton * automaton, Symbol * s) = 0;
        virtual bool transitionConst(Automaton * automaton, Symbol * s) = 0;
        virtual bool transitionComma(Automaton * automaton, Symbol * s) = 0;
        virtual bool transitionSemilicon(Automaton * automaton, Symbol * s) = 0;
        virtual bool transitionId(Automaton * automaton, Symbol * s) = 0;
        virtual bool transitionError(Automaton * automaton, Symbol * s) = 0;
        //Symboles non terminaux
        virtual bool transitionP(Automaton * automaton, Symbol * s) = 0;
        virtual bool transitionD(Automaton * automaton, Symbol * s) = 0;
        virtual bool transitionD_Prime(Automaton * automaton, Symbol * s) = 0;
        virtual bool transitionId_Liste(Automaton * automaton, Symbol * s) = 0;
        virtual bool transitionAff(Automaton * automaton, Symbol * s) = 0;
        virtual bool transitionI(Automaton * automaton, Symbol * s) = 0;
        virtual bool transitionI_Prime(Automaton * automaton, Symbol * s) = 0;
        virtual bool transitionE(Automaton * automaton, Symbol * s) = 0;
        virtual bool transitionT(Automaton * automaton, Symbol * s) = 0;
        virtual bool transitionF(Automaton * automaton, Symbol * s) = 0;
        virtual bool transitionOpA(Automaton * automaton, Symbol * s) = 0;
        virtual bool transitionOpM(Automaton * automaton, Symbol * s) = 0;
        
        
        

    protected:
        int state;
};

#endif
