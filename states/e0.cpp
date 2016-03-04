#include "e0.h"

#include "e1.h"
#include "../ast/symboltype.h"

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
