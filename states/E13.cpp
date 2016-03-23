//
// Created by hdelval on 20/03/16.
//

#include "E13.h"

#include "../Symbols/Terminaux/ParenthesisTerminal.h"
#include "../Symbols/Nonterminaux/Parenthesis.h"
#include "../Symbols/Nonterminaux/Expression.h"

E13::E13()
{
    state = 13;
}

bool E13::transitionSemicolon(Automaton *automaton, Symbol *semicolon)
{ 
	Symbol * closeParenthesis = automaton->popSymbol();
	Symbol * e = automaton->popSymbol();
    Symbol * f = automaton->popSymbol();
    
    Expression * expressionToParenthesise = (Expression*) (e);
    Parenthesis * expressionParenthesised = new Parenthesis(expressionToParenthesise);
    
    expressionToParenthesise->setType(F);
    automaton->programFromLexer.push_front(semicolon);
    automaton->popState();
    automaton->popState();
    automaton->popState();
    (*automaton->states.begin())->transition(automaton, expressionToParenthesise);
    return true;
}


bool E13::transitionCloseParenthesis(Automaton *automaton, Symbol *closeParenthesis)
{ 
	Symbol * closeParenthesis2 = automaton->popSymbol();
	Symbol * e = automaton->popSymbol();
    Symbol * f = automaton->popSymbol();
    
    Expression * expressionToParenthesise = (Expression*) (e);
    Parenthesis * expressionParenthesised = new Parenthesis(expressionToParenthesise);
    
    expressionToParenthesise->setType(F);
    automaton->programFromLexer.push_front(closeParenthesis);
    automaton->popState();
    automaton->popState();
    automaton->popState();
    (*automaton->states.begin())->transition(automaton, expressionToParenthesise);
    return true;
}
