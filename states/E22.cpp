#include "E22.h"

bool transitionAffectDeclare(Automaton * automaton, Symbol * s) {
	automaton->pushState(s, E26());
	return true;
}

