#include "E20.h"

bool transitionSemicolon(Automaton * automaton, Symbol * s) {
	Symbol * s1 = automaton->popSymbole();
	Symbol * s2 = automaton->popSymbole();
	Symbol * s3 = automaton->popSymbole();
	automaton->CurrentState->transition(automaton, new ID(s3,s2,s1));
	return true;
}
