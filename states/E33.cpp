#include "E33.h"
#include "../Symbols/Nonterminaux/OpM.h"
#include "../Symbols/Terminaux/IdTerminal.h"

bool E33::transitionId(Automaton * automaton, Symbol * id) {
	Symbol * divide = automaton->popSymbol();
	OpM * opM = new OpM();
    opM->setColumnWhereSymbolOccurs(divide->getColumnWhereSymbolOccurs());
    opM->setLineWhereSymbolOccurs(divide->getLineWhereSymbolOccurs());
	opM->setOp(DIVIDE);
	opM->setType(OPM);
	automaton->popState();
	delete divide;
	automaton->programFromLexer.push_front(id);
	(*automaton->states.begin())->transition(automaton,opM);
	return true;
}

bool E33::transitionVal(Automaton * automaton, Symbol * val) {
	Symbol * divide = automaton->popSymbol();
	OpM * opM = new OpM();
    opM->setColumnWhereSymbolOccurs(divide->getColumnWhereSymbolOccurs());
    opM->setLineWhereSymbolOccurs(divide->getLineWhereSymbolOccurs());
	opM->setOp(DIVIDE);
	opM->setType(OPM);
	automaton->popState();
	delete divide;
	automaton->programFromLexer.push_front(val);
	(*automaton->states.begin())->transition(automaton,opM);
	return true;
}

bool E33::transitionOpenParenthesis(Automaton * automaton, Symbol * openParenthesis) {
	Symbol * divide = automaton->popSymbol();
	OpM * opM = new OpM();
    opM->setColumnWhereSymbolOccurs(divide->getColumnWhereSymbolOccurs());
    opM->setLineWhereSymbolOccurs(divide->getLineWhereSymbolOccurs());
	opM->setOp(DIVIDE);
	opM->setType(OPM);
	automaton->popState();
	delete divide;
	automaton->programFromLexer.push_front(openParenthesis);
	(*automaton->states.begin())->transition(automaton,opM);
	return true;
}

E33::E33()
{
    state = 33;
}

bool E33::transitionDefault(Automaton *automaton, Symbol *unknown)
{
	std::cerr << "Erreur syntaxique, symbole non attendu";
	automaton->printError(unknown);
	std::cerr << "Un de ces symboles était attendu : [" << expectedSymbols << "]" << std::endl;
	std::cerr << "L'automate assume que un identifiant a été oublié, et continue donc avec avec l'identifiant 'please_do_not_use_this_otherwise_you_gonna_have_some_trouble'." << std::endl;

	// on simule une transition sur ecrire
	automaton->programFromLexer.push_front(unknown);
	Symbol * id = new IdTerminal("please_do_not_use_this_otherwise_you_gonna_have_some_trouble");
	transitionId(automaton, id);
	return true;
}
