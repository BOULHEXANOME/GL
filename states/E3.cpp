#include "E3.h"
/*#include "E11.h"
#include "E6.h"
#include "E9.h"
#include "E41.h"

bool transitionId(Automaton * automaton, Symbol * s) {
	automaton->pushState(s, new E11());
	return true;
}

bool transitionRead(Automaton * automaton, Symbol * s) {
	automaton->pushState(s, new E6());
	return true;
}

bool transitionWrite(Automaton * automaton, Symbol * s) {
	automaton->pushState(s, new E9());
	return true;
}

bool transitionI_Prime(Automaton * automaton, Symbol * s) {
	automaton->pushState(s, new E41());
	return true;
}*/

bool E3::transitionDollar(Automaton * automaton, Symbol * s) {
	automaton->accept();
	return true;
}

E3::E3()
{
	this->state = 3;
}
