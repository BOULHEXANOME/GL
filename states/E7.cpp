#include "E7.h"

bool transitionId(Automaton * automaton, Symbol * s) {
	automaton->pushState(s, E16());
	return true;
}

bool transitionAff(Automaton * automaton, Symbol * s) {
	automaton->pushState(s, E12());
	return true;
}
