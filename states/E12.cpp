#include "E12.h"

bool transitionComma(Automaton * automaton, Symbol * s) {
	automaton->pushState(s, E19());
	return true;
}
