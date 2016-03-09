#include "E2.h"

bool transitionId(Automaton * automaton, Symbol * s) {
	automaton->pushState(s, E15());
	return true;
}

bool transitionId_Liste(Automaton * automaton, Symbol * s) {
	automaton->pushState(s, E10());
	return true;
}
