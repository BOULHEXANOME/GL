#include "E1.h"
bool transitionRead(Automaton & automaton, Symbol & s) {
	automaton.setState(s, E6());
	return true;
}

bool transitionWrite(Automaton & automaton, Symbol & s) {
	automaton.setState(s, E9());
	return true;
}

bool transitionId(Automaton & automaton, Symbol & s) {
	automaton.setState(s, E11());
	return true;
}

bool transitionConst(Automaton & automaton, Symbol & s) {
	automaton.setState(s, E7());
	return true;
}

bool transitionVar(Automaton & automaton, Symbol & s) {
	automaton.setState(s, E2());
	return true;
}
