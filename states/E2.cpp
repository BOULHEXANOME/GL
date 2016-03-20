#include "E2.h"
#include "E10.h"
#include "E15.h"

bool E2::transitionId(Automaton * automaton, Symbol * id) {
	automaton->pushState(id, new E15());
	return true;
}

bool E2::transitionIdList(Automaton * automaton, Symbol * idList) {
	automaton->pushState(idList, new E10());
	return true;
}
E2::E2()
{
	this->state = 2;
}
