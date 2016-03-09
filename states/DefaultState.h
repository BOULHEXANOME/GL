#ifndef DEFAULTSTATE_H
#define DEFAULTSTATE_H

#include "State.h"
#include "E0.h"
#include "E1.h"
#include "E2.h"
#include "E3.h"
#include "E4.h"
#include "E5.h"
#include "E6.h"
#include "E7.h"
#include "E8.h"
#include "E9.h"
#include "E10.h"
#include "E11.h"
#include "E12.h"
#include "E13.h"
#include "E14.h"
#include "E15.h"
#include "E16.h"
#include "E17.h"
#include "E18.h"
#include "E19.h"
#include "E20.h"
#include "E21.h"
#include "E22.h"
#include "E23.h"
#include "E24.h"
#include "E25.h"
#include "E26.h"
#include "E27.h"
#include "E28.h"
#include "E29.h"
#include "E30.h"
#include "E31.h"
#include "E32.h"
#include "E33.h"
#include "E34.h"
#include "E35.h"
#include "E36.h"
#include "E37.h"
#include "E38.h"
#include "E39.h"
#include "E40.h"
#include "E41.h"
#include "E42.h"
#include "E43.h"

class DefaultState : public State
{
    public:
        DefaultState() : State(-1) {};
        ~State() {};
        
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
