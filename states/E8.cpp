#include "E8.h"

bool transitionSemicolon(Automaton * automaton, Symbol * s) {
	Symbol * s1 = automaton->popSymbole();
	Symbol * s2 = automaton->popSymbole();
	//Faut-il pop les state aussi ou on le fait dans popSymbole ? pareil E13-E15 ? structure de donnée pour expression parenthésée ? Symboles non terminaux dans la structure de donnée ?
	automaton->CurrentState->transition(automaton,new I_Prime(s2,s1));
	return true;
}
