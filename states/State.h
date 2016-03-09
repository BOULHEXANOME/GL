#ifndef STATE_H
#define STATE_H

class State {
    public:
        virtual State(int s) : state(s) {};
        virtual ~State() {};
        int state() { return state; }

		
        virtual bool transition(Automaton * automaton, Symbol * s) = 0; // fction de transition entre les états
        
        //Symboles Terminaux
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
        //Symboles non terminaux
        virtual bool transitionP() = 0;
        virtual bool transitionD() = 0;
        virtual bool transitionD_Prime() = 0;
        virtual bool transitionId_Liste() = 0;
        virtual bool transitionAff() = 0;
        virtual bool transitionI() = 0;
        virtual bool transitionI_Prime() = 0;
        virtual bool transitionE() = 0;
        virtual bool transitionT() = 0;
        virtual bool transitionF() = 0;
        virtual bool transitionOpA() = 0;
        virtual bool transitionOpM() = 0;
        
        
        

    protected:
        int state;
};

#endif
