//
// Created by hdelval on 20/03/16.
//

#include "E37.h"
#include "E13.h"
#include "E39.h"
#include "E21.h"
#include "E38.h"


E37::E37()
{
    state = 37;
}

bool E37::transitionCloseParenthesis(Automaton * automaton, Symbol * closeParenthesis)
{
    automaton->pushState(closeParenthesis, new E13());
	return true;
}

bool E37::transitionMinus(Automaton * automaton, Symbol * minus)
{
    automaton->pushState(minus, new E39());
	return true;
}

bool E37::transitionPlus(Automaton * automaton, Symbol * plus)
{
    automaton->pushState(plus, new E38());
	return true;
}

bool E37::transitionOpA(Automaton * automaton, Symbol * opA)
{
    automaton->pushState(opA, new E21());
	return true;
}

