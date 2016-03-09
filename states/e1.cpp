#include "E1.h"

bool transitionI(Automaton * automaton, Symbol * s) {
	automaton->pushState(s, E3());
	return true;
}

bool transitionD_Prime(Automaton * automaton, Symbol * s) {
	automaton->pushState(s, E4());
	return true;
}

bool transitionI_Prime(Automaton * automaton, Symbol * s) {
	automaton->pushState(s, E5());
	return true;
}

bool transitionRead(Automaton * automaton, Symbol * s) {
	automaton->pushState(s, E6());
	return true;
}

bool transitionWrite(Automaton * automaton, Symbol * s) {
	automaton->pushState(s, E9());
	return true;
}

bool transitionId(Automaton * automaton, Symbol * s) {
	automaton->pushState(s, E11());
	return true;
}

bool transitionConst(Automaton * automaton, Symbol * s) {
	automaton->pushState(s, E7());
	return true;
}

bool transitionVar(Automaton * automaton, Symbol * s) {
	automaton->pushState(s, E2());
	return true;
}
