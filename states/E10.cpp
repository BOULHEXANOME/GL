#include "E10.h"

bool transitionComma(Automaton * automaton, Symbol * s) {
	automaton->pushState(s, E17());
	return true;
}

