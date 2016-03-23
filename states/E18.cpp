//
// Created by hdelval on 20/03/16.
//

#include "E18.h"
#include "../Symbols/Nonterminaux/Write.h"

E18::E18()
{
    expectedSymbols = "+, -, ;, additive or subtractive operation";
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
