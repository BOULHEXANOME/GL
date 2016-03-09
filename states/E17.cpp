#include "E17.h"

bool transitionId(Automaton * automaton, Symbol * s) {
	automaton->pushState(s, E20());
	return true;
}
