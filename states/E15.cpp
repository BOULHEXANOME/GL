#include "E15.h"
#include "../Symbols/Terminaux/Comma.h"

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
	expectedSymbols = "comma, ;";
	this->state = 15;
}

bool E15::transitionDefault(Automaton *automaton, Symbol *unknown)
{
	std::cerr << "Erreur syntaxique, symbole non attendu";
	automaton->printError(unknown);
	std::cerr << "Un de ces symboles était attendu : [" << expectedSymbols << "]" << std::endl;
	std::cerr << "L'automate assume que la virgule a été oubliée, et continue donc avec ce symbole." << std::endl;

	// on simule une transition sur comma
	automaton->programFromLexer.push_front(unknown);
	Symbol * comma = new Comma();
	transitionComma(automaton, comma);
	return true;
}
