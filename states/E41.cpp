#include "E41.h"
#include "E42.h"
#include "../Symbols/Terminaux/Semicolon.h"

bool E41::transitionSemicolon(Automaton * automaton, Symbol * semicolon) {
	automaton->pushState(semicolon, new E42());
	return true;
}
E41::E41()
{
	this->state = 41;
	expectedSymbols = ";";
}

bool E41::transitionDefault(Automaton *automaton, Symbol *unknown)
{

    std::cerr << "Erreur syntaxique, symbole non attendu";
    automaton->printError(unknown);
    std::cerr << "Un de ces symboles était attendu : [" << expectedSymbols << "]" << std::endl;
    std::cerr << "L'automate assume que le point virgule a été oublié, et continue donc avec le symbole ';'." << std::endl;

    // on simule une transition sur semicolon
    automaton->programFromLexer.push_front(unknown);
    Symbol * semicolon = new Semicolon();
    transitionSemicolon(automaton, semicolon);
	return true;
}
