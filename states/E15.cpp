#include "E15.h"
#include "../Symbols/Terminaux/IdTerminal.h"
#include "../Symbols/Nonterminaux/Variable.h"

bool E15::transitionSemicolon(Automaton * automaton, Symbol * semicolon) {
	Symbol * id = automaton->popSymbol();
    id->setType(ID_LIST);
	automaton->programFromLexer.push_front(semicolon);
	automaton->popState();
	(*automaton->states.begin())->transition(automaton, id);
	return true;
}

bool E15::transitionComma(Automaton * automaton, Symbol * comma) {
	Symbol * id = automaton->popSymbol();
    id->setType(ID_LIST);
	automaton->programFromLexer.push_front(comma);
	automaton->popState();
	(*automaton->states.begin())->transition(automaton, id);
	return true;
}

E15::E15()
{
	this->state = 15;
}
