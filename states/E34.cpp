#include "E34.h"
#include "../Symbols/Terminaux/IdTerminal.h"
#include "../Symbols/Nonterminaux/Variable.h"

E34::E34()
{
    state = 34;
}

bool E34::transitionSemicolon(Automaton * automaton, Symbol * semicolon) {
	IdTerminal * id = (IdTerminal*)automaton->popSymbol();
	Variable* variable = new Variable(id->getTheName());
	variable->setType(F);
	automaton->programFromLexer.push_front(semicolon);
    automaton->popState();
    
	(*automaton->states.begin())->transition(automaton, variable);
	return true;
}
/*
bool transitionMultiply(Automaton * automaton, Symbol * s) {
	Symbol * s1 = automaton->popSymbol();
	automaton->CurrentState->transition(automaton,new F(s1));
	return true;
}

bool transitionDivide(Automaton * automaton, Symbol * s) {
	Symbol * s1 = automaton->popSymbol();
	automaton->CurrentState->transition(automaton,new F(s1));
	return true;
}

bool transitionClosingParenthesis(Automaton * automaton, Symbol * s) {
	Symbol * s1 = automaton->popSymbol();
	automaton->CurrentState->transition(automaton,new F(s1));
	return true;
}

bool transitionPlus(Automaton * automaton, Symbol * s) {
	Symbol * s1 = automaton->popSymbol();
	automaton->CurrentState->transition(automaton,new F(s1));
	return true;
}

bool transitionMinus(Automaton * automaton, Symbol * s) {
	Symbol * s1 = automaton->popSymbol();
	automaton->CurrentState->transition(automaton,new F(s1));
	return true;
}
*/
