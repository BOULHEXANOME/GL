#include "E24.h"

bool transitionVal(Automaton * automaton, Symbol * s) {
	automaton->pushState(s, E25());
	return true;
}
