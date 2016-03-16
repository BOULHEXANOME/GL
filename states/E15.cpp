#include "E15.h"

bool transitionSemilocon(Automaton * automaton, Symbol * s) {
	Symbol * s1 = automaton->popSymbol();
	automaton->CurrentState->transition(automaton,new Symbol(s1));
	return true;
}
