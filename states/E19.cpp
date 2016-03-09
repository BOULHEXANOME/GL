#include "E19.h"

bool transitionId(Automaton * automaton, Symbol * s) {
	automaton->pushState(s, E22());
	return true;
}
