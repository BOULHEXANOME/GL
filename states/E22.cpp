#include "E22.h"
#include "E26.h"

bool E22::transitionAffectDeclare(Automaton * automaton, Symbol * affectDeclare) {
	automaton->pushState(affectDeclare, new E26());
	return true;
}

E22::E22()
{
    state = 22;
}
