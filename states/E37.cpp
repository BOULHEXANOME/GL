//
// Created by hdelval on 20/03/16.
//

#include "E37.h"
#include "E13.h"


E37::E37()
{
    state = 37;
}

bool E37::transitionCloseParenthesis(Automaton * automaton, Symbol * closeParenthesis)
{
    automaton->pushState(closeParenthesis, new E13());
	return true;
}

