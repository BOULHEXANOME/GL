#include "E4.h"

bool transitionSemicolon(Automaton * automaton, Symbol * s) {
	automaton->pushState(s, E40());
	return true;
}
