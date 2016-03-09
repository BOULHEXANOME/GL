#include "E10.h"

bool transitionComma(Automaton * automaton, Symbol * s) {
	automaton->pushState(s, E17());
	return true;
}

bool transitionSemicolon(Automaton * automaton, Symbol * s) {
	Symbol * s1 = automaton->popSymbole();
	Symbol * s2 = automaton->popSymbole();
	automaton->CurrentState->transition(automaton, new D_Prime(s2,s1));
	return true;
}


