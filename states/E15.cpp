#include "E15.h"

bool transitionSemilocon(Automaton * automaton, Symbol * s) {
	Symbol * s1 = automaton->popSymbole();
	automaton->CurrentState->transition(automaton,new ID(s1));
	return true;
}
