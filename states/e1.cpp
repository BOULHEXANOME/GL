#include "E1.h"
bool transitionRead() {
	automaton.setState(s, E6());
	return true;
}

bool transitionWrite() {
	automaton.setState(s, E9());
	return true;
}

bool transitionId() {
	automaton.setState(s, E11());
	return true;
}

bool transitionConst() {
	automaton.setState(s, E7());
	return true;
}

bool transitionVar() {
	automaton.setState(s, E2());
	return true;
}
