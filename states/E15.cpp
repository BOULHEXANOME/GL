#include "E15.h"
#include "../Symbols/Terminaux/IdTerminal.h"
#include "../Symbols/Nonterminaux/Variable.h"

bool E15::transitionSemicolon(Automaton * automaton, Symbol * semicolon) {
	Symbol * id = automaton->popSymbol();
	// Symbol * id2 =  new Symbol(s1);
    id->setType(ID_LISTE);//Mais wtf on change pas le type comme ca si ?
	automaton->programFromLexer.push_front(semicolon);
	automaton->popState();
	(*automaton->states.begin())->transition(automaton, id);
	return true;
}
E15::E15()
{
	this->state = 15;
}
