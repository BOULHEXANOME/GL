#include "e1.h"
#include "e2.h"
#include "e3.h"
#include "e4.h"
#include "e5.h"
#include "../ast/instruction/instructionlist.h"


bool E1::transition (Automaton & automaton, std::shared_ptr<Symbol> s) {

  switch(s->getType()) {
    case SymbolType::I :
		automaton.setState(s, std::make_shared<E3>());
		return true;
    case SymbolType::Dp :
		automaton.setState(s, std::make_shared<E4>());
		return true;
    case SymbolType::Ip :
		automaton.setState(s, std::make_shared<E5>());
		return true;
    case SymbolType::lire :
		automaton.setState(s, std::make_shared<E6>());
		return true;
    case SymbolType::ecrire :
		automaton.setState(s, std::make_shared<E9>());
		return true;
	case SymbolType::id :
		automaton.setState(s, std::make_shared<E11>());
		return true;
	case SymbolType::cons :
		automaton.setState(s, std::make_shared<E7>());
		return true;
	case SymbolType::var :
		automaton.setState(s, std::make_shared<E2>());
		return true;
	default :
		return false;
    }
  }
}
