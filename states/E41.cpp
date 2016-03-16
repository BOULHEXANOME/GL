#include "E41.h"

bool transitionSemicolon(Automaton * automaton, Symbol * s) {
	automaton->pushState(s, E42());
	return true;
}
