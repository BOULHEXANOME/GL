#include "e1.h"



bool DefaultState::transition (Automaton & automaton, Symbol & s) {

	switch(s->getType())
    {
		case MINUS :
			transitionRead();
			return true;
		case SymbolType::write :
			transitionWrite();
			return true;
		case SymbolType::id :
			transitionId();
			return true;
		case SymbolType::cons :
			transitionConst();
			return true;
		case SymbolType::var :
			transitionVar();
			return true;
		default :
			return false;
    }
}
