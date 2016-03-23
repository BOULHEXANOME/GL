#include "E38.h"
#include "../Symbols/Nonterminaux/OpA.h"
#include "../Symbols/Terminaux/IdTerminal.h"

bool E38::transitionId(Automaton * automaton, Symbol * id) {
	Symbol * plus = automaton->popSymbol();
	OpA * opA = new OpA();
	opA->setOp(PLUS);
	opA->setType(OPA);
	automaton->popState();
	automaton->programFromLexer.push_front(id);
	(*automaton->states.begin())->transition(automaton,opA);
	return true;
}

bool E38::transitionVal(Automaton * automaton, Symbol * val) {
	Symbol * plus = automaton->popSymbol();
	OpA * opA = new OpA();
	opA->setOp(PLUS);
	opA->setType(OPA);
	automaton->popState();
	automaton->programFromLexer.push_front(val);
	(*automaton->states.begin())->transition(automaton,opA);
	return true;
}

bool E38::transitionOpenParenthesis(Automaton * automaton, Symbol * openParenthesis) {
	Symbol * plus = automaton->popSymbol();
	OpA * opA = new OpA();
	opA->setOp(PLUS);
	opA->setType(OPA);
	automaton->popState();
	automaton->programFromLexer.push_front(openParenthesis);
	(*automaton->states.begin())->transition(automaton,opA);
	return true;
}

E38::E38()
{
	expectedSymbols = "id, val, (";
    state = 38;
}

bool E38::transitionDefault(Automaton *automaton, Symbol *unknown)
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
