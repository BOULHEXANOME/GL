#include "E3.h"

bool transitionId(Automaton * automaton, Symbol * s) {
	automaton->pushState(s, E11());
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

bool transitionI_Prime(Automaton * automaton, Symbol * s) {
	automaton->pushState(s, E41());
	return true;
}

bool transitionDollar(Automaton * automaton, Symbol * s) {
	automaton->accept();
	return true;
}
