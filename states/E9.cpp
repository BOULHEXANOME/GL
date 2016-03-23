//
// Created by hdelval on 20/03/16.
//

#include "E9.h"
#include "E35.h"
#include "E31.h"
#include "E29.h"
#include "E18.h"
#include "E34.h"
#include "E36.h"
#include "../Symbols/Nonterminaux/Number.h"

E9::E9()
{
    expectedSymbols = "id, val, (, expression, term, factor";
    state = 9;
}

bool E9::transitionVal(Automaton *automaton, Symbol *val)
{
    automaton->pushState(val, new E35());
    return true;
}

bool E9::transitionF(Automaton *automaton, Symbol *f)
{
    automaton->pushState(f, new E31());
    return true;
}

bool E9::transitionT(Automaton *automaton, Symbol *t)
{
    automaton->pushState(t, new E29());
    return true;
}

bool E9::transitionE(Automaton *automaton, Symbol *e)
{
    automaton->pushState(e, new E18());
    return true;
}
bool E9::transitionId(Automaton * automaton, Symbol * id)
{
	automaton->pushState(id, new E34());
    return true;
}

bool E9::transitionOpenParenthesis(Automaton * automaton, Symbol * openParenthesis)
{
	automaton->pushState(openParenthesis, new E36());
    return true;
}

bool E9::transitionDefault(Automaton *automaton, Symbol *unknown)
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
