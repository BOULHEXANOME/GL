#include "E8.h"

bool transitionSemicolon(Automaton * automaton, Symbol * s) {
	Symbol * s1 = automaton->popSymbol();
	Symbol * s2 = automaton->popSymbol();
	//Faut-il pop les state aussi ou on le fait dans popSymbol ? pareil E13-E15 ? structure de donnée pour expression parenthésée ? Symbols non terminaux dans la structure de donnée ?
	automaton->CurrentState->transition(automaton,new I_Prime(s2,s1));
	return true;
}
