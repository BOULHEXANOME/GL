#include "E17.h"
#include "E20.h"

bool E17::transitionId(Automaton * automaton, Symbol * id) {
	automaton->pushState(id, new E20());
	return true;
}

E17::E17()
{
    state = 17;
}
