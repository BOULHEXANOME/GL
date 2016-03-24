#include "E1.h"
#include "E2.h"
#include "E4.h"
#include "E9.h"
#include "E5.h"
#include "E3.h"
#include "E11.h"
#include "E6.h"
#include "E7.h"
#include "../Symbols/Terminaux/WriteTerminal.h"

bool E1::transitionVar(Automaton * automaton, Symbol * var) {
	automaton->pushState(var, new E2());
	return true;
}

bool E1::transitionId(Automaton * automaton, Symbol * s) {
	automaton->pushState(s, new E11());
	return true;
}

E1::E1()
{
    expectedSymbols = "var, const, id, write, read, instruction line, declarative line, instruction paragraph";
	this->state = 1;
}

bool E1::transitionD_Prime(Automaton *automaton, Symbol *dPrime)
{
    automaton->pushState(dPrime, new E4());
    return true;
}

bool E1::transitionWrite(Automaton *automaton, Symbol *write)
{
    automaton->pushState(write, new E9());
    return true;
}

bool E1::transitionI_Prime(Automaton *automaton, Symbol *iPrime)
{
    automaton->pushState(iPrime, new E5());
    return true;
}

bool E1::transitionI(Automaton *automaton, Symbol *i)
{
    automaton->pushState(i, new E3());
    return true;
}

bool E1::transitionRead(Automaton *automaton, Symbol *readS)
{
    automaton->pushState(readS, new E6());
    return true;
}

bool E1::transitionConst(Automaton *automaton, Symbol *constS)
{
    automaton->pushState(constS, new E7());
    return true;
}

bool E1::transitionDefault(Automaton *automaton, Symbol *unknown)
{
    std::cerr << "Erreur syntaxique, symbole non attendu";
    automaton->printError(unknown);
    std::cerr << "Un de ces symboles était attendu : [" << expectedSymbols << "]" << std::endl;
    std::cerr << "L'automate assume que un 'ecrire' a été oublié, et continue donc avec ce symbole." << std::endl;

    // on simule une transition sur ecrire
    automaton->programFromLexer.push_front(unknown);
    Symbol * ecrire = new WriteTerminal();
    transitionWrite(automaton, ecrire);
    return true;
}
