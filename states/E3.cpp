#include "E3.h"
#include "E9.h"
#include "E41.h"
/*#include "E11.h"
#include "E6.h"

bool transitionId(Automaton * automaton, Symbol * s) {
	automaton->pushState(s, new E11());
	return true;
}

bool transitionRead(Automaton * automaton, Symbol * s) {
	automaton->pushState(s, new E6());
	return true;
}

*/
bool E3::transitionI_Prime(Automaton * automaton, Symbol * iprime) {
	automaton->pushState(iprime, new E41());
	return true;
}

bool E3::transitionDollar(Automaton * automaton, Symbol * dollar) {
	automaton->accept();
	return true;
}

bool E3::transitionWrite(Automaton * automaton, Symbol * write) {
	automaton->pushState(write, new E9());
	return true;
}

E3::E3()
{
	this->state = 3;
}
