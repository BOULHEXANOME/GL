#include "E33.h"
#include "../Symbols/Nonterminaux/OpM.h"

bool E33::transitionId(Automaton * automaton, Symbol * id) {
	Symbol * divide = automaton->popSymbol();
	OpM * opM = new OpM();
	opM->setOp(DIVIDE);
	opM->setType(OPM);
	automaton->popState();
	automaton->programFromLexer.push_front(id);
	(*automaton->states.begin())->transition(automaton,opM);
	return true;
}

bool E33::transitionVal(Automaton * automaton, Symbol * val) {
	Symbol * divide = automaton->popSymbol();
	OpM * opM = new OpM();
	opM->setOp(DIVIDE);
	opM->setType(OPM);
	automaton->popState();
	automaton->programFromLexer.push_front(val);
	(*automaton->states.begin())->transition(automaton,opM);
	return true;
}

bool E33::transitionOpenParenthesis(Automaton * automaton, Symbol * openParenthesis) {
	Symbol * divide = automaton->popSymbol();
	OpM * opM = new OpM();
	opM->setOp(DIVIDE);
	opM->setType(OPM);
	automaton->popState();
	automaton->programFromLexer.push_front(openParenthesis);
	(*automaton->states.begin())->transition(automaton,opM);
	return true;
}

E33::E33()
{
    state = 33;
}
