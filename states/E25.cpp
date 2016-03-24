//
// Created by hdelval on 22/03/16.
//

#include "E25.h"
#include "../Symbols/Nonterminaux/Number.h"
#include "../Symbols/Terminaux/IdTerminal.h"
#include "../Symbols/Nonterminaux/AffectConst.h"

E25::E25()
{
    state = 25;
}

bool E25::transitionSemicolon(Automaton *automaton, Symbol *semicolon)
{
    Number * val = (Number*)automaton->popSymbol();
    Symbol * equal = automaton->popSymbol();
    IdTerminal * id = (IdTerminal*) automaton->popSymbol();

    Number * valWithConst = new Number(val->getTheValue());
    AffectConst * actionDeclareAndAffectConst = new AffectConst(new Constant(id->getTheName()), valWithConst);
    Line affectAndDeclareConst(Type::declaration);
    affectAndDeclareConst.addSymbol(actionDeclareAndAffectConst);
    automaton->addProgramLine(affectAndDeclareConst);

    val->setType(AFF);
    automaton->programFromLexer.push_front(semicolon);
    automaton->popState();
    automaton->popState();
    automaton->popState();
    (*automaton->states.begin())->transition(automaton, val);
    return true;
}

bool E25::transitionComma(Automaton *automaton, Symbol *comma)
{
    Number * val = (Number*)automaton->popSymbol();
    Symbol * equal = automaton->popSymbol();
    IdTerminal * id = (IdTerminal*) automaton->popSymbol();

    Number * valWithConst = new Number(val->getTheValue());
    AffectConst * actionDeclareAndAffectConst = new AffectConst(new Constant(id->getTheName()), valWithConst);
    Line affectAndDeclareConst(Type::declaration);
    affectAndDeclareConst.addSymbol(actionDeclareAndAffectConst);
    automaton->addProgramLine(affectAndDeclareConst);

    val->setType(AFF);
    automaton->programFromLexer.push_front(comma);
    automaton->popState();
    automaton->popState();
    automaton->popState();
    (*automaton->states.begin())->transition(automaton, val);
    return true;
}
