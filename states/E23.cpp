#include "E23.h"

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

bool transitionSemicolon(Automaton * automaton, Symbol * s) {
	Symbol * s1 = automaton->popSymbole();
	Symbol * s2 = automaton->popSymbole();
	Symbol * s3 = automaton->popSymbole();
	automaton->CurrentState->transition(automaton,new I_Prime(s3,s2,s1));
	return true;
}
