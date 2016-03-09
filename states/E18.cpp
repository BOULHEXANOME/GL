#include "E18.h"

bool transitionPlus(Automaton * automaton, Symbol * s) {
	automaton->pushState(s, E38());
	return true;
}

bool transitionMinus(Automaton * automaton, Symbol * s) {
	automaton->pushState(s, E39());
	return true;
}

bool transitionOpA(Automaton * automaton, Symbol * s) {
	automaton->pushState(s, E21());
	return true;
}
