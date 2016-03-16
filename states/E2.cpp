#include "E2.h"
/*#include "E10.h"*/
#include "E15.h"

bool E2::transitionId(Automaton * automaton, Symbol * s) {
	automaton->pushState(s, new E15());
	return true;
}
/*
bool E2::transitionId_Liste(Automaton * automaton, Symbol * s) {
	automaton->pushState(s, new E10());
	return true;
}*/
E2::E2()
{
	this->state = 2;
}
