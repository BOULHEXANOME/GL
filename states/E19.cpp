#include "E19.h"
#include "E22.h"

bool E19::transitionId(Automaton * automaton, Symbol * id) {
	automaton->pushState(id, new E22());
	return true;
}
E19::E19()
{
    state = 19;
}
