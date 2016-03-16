#include "E0.h"
#include "E1.h"
#include "../symbolTypes.h"

bool E0::transitionD(Automaton * automaton, Symbol * s) {
	automaton->pushState(s, new E1());
	return true;
}

bool E0::transitionRead(Automaton * automaton, Symbol * s) {
	Symbol * s2 =  new Symbol();
	s2->setType(D);
	automaton->programme.push_front(s);
	automaton->CurrentState->transition(automaton,s2);
	return true;
}

bool E0::transitionWrite(Automaton * automaton, Symbol * s) {
	Symbol * s2 =  new Symbol();
	s2->setType(D);
	automaton->programme.push_front(s);
	automaton->CurrentState->transition(automaton,s2);
	return true;
}

bool E0::transitionId(Automaton * automaton, Symbol * s) {
	Symbol * s2 =  new Symbol();
	s2->setType(D);
	automaton->programme.push_front(s);
	automaton->CurrentState->transition(automaton,s2);
	return true;
}

bool E0::transitionConst(Automaton * automaton, Symbol * s) {
	Symbol * s2 =  new Symbol();
	s2->setType(D);
	automaton->programme.push_front(s);
	automaton->CurrentState->transition(automaton,s2);
	return true;
}

bool E0::transitionVar(Automaton * automaton, Symbol * s) {
	Symbol * s2 =  new Symbol();
	s2->setType(D);
	automaton->programme.push_front(s);
	automaton->CurrentState->transition(automaton,s2);
	return true;
}

E0::E0()
{
	this->state = 0;
}
