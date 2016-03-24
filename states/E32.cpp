#include "E32.h"
#include "../Symbols/Nonterminaux/OpM.h"
#include "../Symbols/Terminaux/Semicolon.h"
#include "../Symbols/Terminaux/IdTerminal.h"

bool E32::transitionId(Automaton * automaton, Symbol * id) {
	Symbol * multiply = automaton->popSymbol();
	OpM * opM = new OpM();
    opM->setColumnWhereSymbolOccurs(multiply->getColumnWhereSymbolOccurs());
    opM->setLineWhereSymbolOccurs(multiply->getLineWhereSymbolOccurs());
	opM->setOp(MULTIPLY);
	opM->setType(OPM);
	automaton->popState();
	delete multiply;
	automaton->programFromLexer.push_front(id);
	(*automaton->states.begin())->transition(automaton,opM);
	return true;
}

bool E32::transitionVal(Automaton * automaton, Symbol * val) {
	Symbol * multiply = automaton->popSymbol();
	OpM * opM = new OpM();
    opM->setColumnWhereSymbolOccurs(multiply->getColumnWhereSymbolOccurs());
    opM->setLineWhereSymbolOccurs(multiply->getLineWhereSymbolOccurs());
	opM->setOp(MULTIPLY);
	opM->setType(OPM);
	automaton->popState();
    delete multiply;
	automaton->programFromLexer.push_front(val);
	(*automaton->states.begin())->transition(automaton,opM);
	return true;
}

bool E32::transitionOpenParenthesis(Automaton * automaton, Symbol * openParenthesis) {
	Symbol * multiply = automaton->popSymbol();
	OpM * opM = new OpM();
    opM->setColumnWhereSymbolOccurs(multiply->getColumnWhereSymbolOccurs());
    opM->setLineWhereSymbolOccurs(multiply->getLineWhereSymbolOccurs());
	opM->setOp(MULTIPLY);
	opM->setType(OPM);
	automaton->popState();
    delete multiply;
	automaton->programFromLexer.push_front(openParenthesis);
	(*automaton->states.begin())->transition(automaton,opM);
	return true;
}

E32::E32()
{
    state = 32;
	expectedSymbols = "val, id, (";
}

bool E32::transitionDefault(Automaton *automaton, Symbol *unknown)
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
