#include "E0->h"

bool transitionD(Automaton * automaton, Symbol * s) {
	automaton->pushState(s, E1());
	return true;
}

bool transitionRead(Automaton * automaton, Symbol * s) {
	automaton->popState();
	automaton->CurrentState->transition(new D(), E0());
	return true;
}

bool transitionWrite(Automaton * automaton, Symbol * s) {
	automaton->popState();
	automaton->CurrentState->transition(new D(), E0());
	return true;
}

bool transitionId(Automaton * automaton, Symbol * s) {
	automaton->popState();
	automaton->CurrentState->transition(new D(), E0());
	return true;
}

bool transitionConst(Automaton * automaton, Symbol * s) {
	automaton->popState();
	automaton->CurrentState->transition(new D(), E0());
	return true;
}

bool transitionVar(Automaton * automaton, Symbol * s) {
	automaton->popState();
	automaton->CurrentState->transition(new D(), E0());
	return true;
}
