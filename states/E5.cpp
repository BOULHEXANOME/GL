#include "E5.h"

bool transitionSemicolon(Automaton * automaton, Symbol * s) {
	automaton->pushState(s, E43());
	return true;
}

