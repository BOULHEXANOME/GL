#include "E23.h"


E23::E23()
{
    state = 23;
}

bool transitionSemicolon(Automaton * automaton, Symbol * semicolon) {
	//PAS FINI DU TOUT
	Symbol * s1 = automaton->popSymbol();
	Symbol * s2 = automaton->popSymbol();
	Symbol * s3 = automaton->popSymbol();
	automaton->CurrentState->transition(automaton,new I_Prime(s3,s2,s1));
	return true;
}

/*
bool transitionOpA(Automaton * automaton, Symbol * s) {
	automaton->pushState(s, E21());
	return true;
}

bool transitionPlus(Automaton * automaton, Symbol * s) {
	automaton->pushState(s, E38());
	return true;
}

bool transitionMinus(Automaton * automaton, Symbol * s) {
	automaton->pushState(s, E39());
	return true;
}

*/
