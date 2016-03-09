#include "E16.h"

bool transitionAffectDeclare(Automaton * automaton, Symbol * s) {
	automaton->pushState(s, E24());
	return true;
}
