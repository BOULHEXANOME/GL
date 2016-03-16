#include "E36.h"

bool transitionId(Automaton * automaton, Symbol * s) {
	automaton->pushState(s, E34());
	return true;
}

bool transitionVal(Automaton * automaton, Symbol * s) {
	automaton->pushState(s, E35());
	return true;
}

bool transitionOpeningParenthesis(Automaton * automaton, Symbol * s) {
	automaton->pushState(s, E36());
	return true;
}

bool transitionT(Automaton * automaton, Symbol * s) {
	automaton->pushState(s, E29());
	return true;
}

bool transitionE(Automaton * automaton, Symbol * s) {
	automaton->pushState(s, E37());
	return true;
}

bool transitionF(Automaton * automaton, Symbol * s) {
	automaton->pushState(s, E31());
	return true;
}
