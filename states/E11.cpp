#include "E11.h"

bool transitionAffectInstruct(Automaton * automaton, Symbol * s) {
	automaton->pushState(s, E14());
	return true;
}
