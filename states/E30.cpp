#include "E30.h"
#include "E34.h"
#include "E35.h"
#include "E36.h"
#include "E44.h"
#include "../Symbols/Terminaux/IdTerminal.h"

bool E30::transitionId(Automaton * automaton, Symbol * id) {
	automaton->pushState(id, new E34());
	return true;
}

bool E30::transitionVal(Automaton * automaton, Symbol * val) {
	automaton->pushState(val, new E35());
	return true;
}

bool E30::transitionOpenParenthesis(Automaton * automaton, Symbol * openingParenthesis) {
	automaton->pushState(openingParenthesis, new E36());
	return true;
}

bool E30::transitionF(Automaton * automaton, Symbol * f) {
	automaton->pushState(f, new E44());
	return true;
}

E30::E30()
{
    state = 30;
}

bool E30::transitionDefault(Automaton *automaton, Symbol *unknown)
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
