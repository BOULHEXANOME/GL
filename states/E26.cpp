#include "E26.h"

bool transitionVal(Automaton * automaton, Symbol * s) {
	automaton->pushState(s, E28());
	return true;
}
