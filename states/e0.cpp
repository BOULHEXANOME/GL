#include "E0.h"

bool E0::transitionD(Automaton * automaton, Symbol * s) {
	automaton->pushState(s, E1());
	return true;
}

bool E0::transitionRead(Automaton * automaton, Symbol * s) {
	automaton->popState();
	automaton->CurrentState->transition(new D(), E0());
	return true;
}

bool E0::transitionWrite(Automaton * automaton, Symbol * s) {
	automaton->popState();
	automaton->CurrentState->transition(new D(), E0());
	return true;
}

bool E0::transitionId(Automaton * automaton, Symbol * s) {
	automaton->popState();
	automaton->CurrentState->transition(new D(), E0());
	return true;
}

bool E0::transitionConst(Automaton * automaton, Symbol * s) {
	automaton->popState();
	automaton->CurrentState->transition(new D(), E0());
	return true;
}

bool E0::transitionVar(Automaton * automaton, Symbol * s) {
	automaton->popState();
	automaton->CurrentState->transition(new D(), E0());
	return true;
}

E0::E0()
{
	this->state = 0;
}
