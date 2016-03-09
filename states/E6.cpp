#include "E6.h"

bool transitionId(Automaton * automaton, Symbol * s) {
	automaton->pushState(s, E8());
	return true;
}
