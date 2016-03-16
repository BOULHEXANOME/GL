#include "E18.h"

bool transitionPlus(Automaton * automaton, Symbol * s) {
	automaton->pushState(s, E38());
	return true;
}

bool transitionMinus(Automaton * automaton, Symbol * s) {
	automaton->pushState(s, E39());
	return true;
}

bool transitionOpA(Automaton * automaton, Symbol * s) {
	automaton->pushState(s, E21());
	return true;
}

bool transitionSemicolon(Automaton * automaton, Symbol * s) {
	Symbol * s1 = automaton->popSymbol();
	Symbol * s2 = automaton->popSymbol();
	automaton->CurrentState->transition(automaton,new I_Prime(s2,s1));
	return true;
}
