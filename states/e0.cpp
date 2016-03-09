#include "E0.h"

bool E0::transition (Automaton & automaton, std::shared_ptr<Symbol> s)
{
    if(s->getType() == SymbolType::D)
    {
        automaton.setState(s, std::make_shared<E1>());
        return true;
    }
    else
    {
        return false;
    }
}

bool transitionD(Automaton & automaton, Symbol & s) {
	automaton.setState(s, E1());
	return true;
}

bool transitionRead(Automaton & automaton, Symbol & s) {
	automaton.popState();
	automaton.setState(new D(), E0());
	return true;
}

bool transitionWrite(Automaton & automaton, Symbol & s) {
	automaton.setState(new D(), E0());
	return true;
}

bool transitionId(Automaton & automaton, Symbol & s) {
	automaton.setState(new D(), E0());
	return true;
}

bool transitionConst(Automaton & automaton, Symbol & s) {
	automaton.setState(new D(), E0());
	return true;
}

bool transitionVar(Automaton & automaton, Symbol & s) {
	automaton.setState(new D(), E0());
	return true;
}
