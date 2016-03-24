#include "E21.h"
#include "E27.h"
#include "E31.h"
#include "E35.h"
#include "E36.h"
#include "E34.h"
#include "../Symbols/Nonterminaux/Number.h"

bool E21::transitionVal(Automaton * automaton, Symbol * val){
	automaton->pushState(val, new E35());
	return true;
}

bool E21::transitionF(Automaton * automaton, Symbol * f){
	automaton->pushState(f, new E31());
	return true;
}

bool E21::transitionT(Automaton * automaton, Symbol * t){
	automaton->pushState(t, new E27());
	return true;
}

bool E21::transitionId(Automaton * automaton, Symbol * id){
	automaton->pushState(id, new E34());
	return true;
}

bool E21::transitionOpenParenthesis(Automaton * automaton, Symbol * openParenthesis){
	automaton->pushState(openParenthesis, new E36());
	return true;
}



E21::E21()
{
    state = 21;
	expectedSymbols = "id, val, (, factor, term";
}

bool E21::transitionDefault(Automaton *automaton, Symbol *unknown)
{
	std::cerr << "Erreur syntaxique, symbole non attendu";
	automaton->printError(unknown);
	std::cerr << "Un de ces symboles était attendu : [" << expectedSymbols << "]" << std::endl;
	std::cerr << "L'automate assume que une valeur a été oubliée, et continue donc avec la valeur 10." << std::endl;

	// on simule une transition sur =
	automaton->programFromLexer.push_front(unknown);
	Symbol * val = new Number(0);
	transitionVal(automaton, val);
	return true;
}
