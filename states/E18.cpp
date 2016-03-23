//
// Created by hdelval on 20/03/16.
//

#include "E18.h"
#include "E21.h"
#include "E38.h"
#include "E39.h"
#include "../Symbols/Nonterminaux/Write.h"

E18::E18()
{
    state = 18;
}

bool E18::transitionSemicolon(Automaton *automaton, Symbol *semicolon)
{
    Expression * e = (Expression*) automaton->popSymbol();
    Symbol * write = automaton->popSymbol();

    Write* writeInstruction = new Write(e);
    
    Line writeInstruct(Type::instruction);
    writeInstruct.addSymbol(writeInstruction);
    automaton->addProgramLine(writeInstruct);

    e->setType(I_PRIME);
    automaton->programFromLexer.push_front(semicolon);
    automaton->popState();
    automaton->popState();
    (*automaton->states.begin())->transition(automaton, e);
    return true;
}

bool E18::transitionOpA(Automaton * automaton, Symbol * opa){
	automaton->pushState(opa, new E21());
	return true;
}

bool E18::transitionPlus(Automaton * automaton, Symbol * plus){
	automaton->pushState(plus, new E38());
	return true;
}

bool E18::transitionMinus(Automaton * automaton, Symbol * minus){
	automaton->pushState(minus, new E39());
	return true;
}
