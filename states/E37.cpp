#include "E37.h"

bool transitionOpA(Automaton * automaton, Symbol * s) {
	automaton->pushState(s, E21());
	return true;
}

bool transitionClosingParenthesis(Automaton * automaton, Symbol * s) {
	automaton->pushState(s, E13());
	return true;
}

bool transitionPlus(Automaton * automaton, Symbol * s) {
	automaton->pushState(s, E38());
	return true;
}

bool transitionMinus(Automaton * automaton, Symbol * s) {
	automaton->pushState(s, E39());
	return true;
}
