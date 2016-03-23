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

    Parenthesis * expressionParenthesised = new Parenthesis((Expression*) (e));

    expressionParenthesised->setType(F);
    automaton->programFromLexer.push_front(semicolon);
    automaton->popState();
    automaton->popState();
    automaton->popState();
    (*automaton->states.begin())->transition(automaton, expressionParenthesised);
    return true;
}


bool E13::transitionCloseParenthesis(Automaton *automaton, Symbol *closeParenthesis)
{ 
	Symbol * closeParenthesis2 = automaton->popSymbol();
	Symbol * e = automaton->popSymbol();
    Symbol * f = automaton->popSymbol();

    Parenthesis * expressionParenthesised = new Parenthesis((Expression*) (e));

    expressionParenthesised->setType(F);
    automaton->programFromLexer.push_front(closeParenthesis);
    automaton->popState();
    automaton->popState();
    automaton->popState();
    (*automaton->states.begin())->transition(automaton, expressionParenthesised);
    return true;
}

bool E13::transitionMinus(Automaton *automaton, Symbol *minus)
{ 
	Symbol * closeParenthesis = automaton->popSymbol();
	Symbol * e = automaton->popSymbol();
    Symbol * f = automaton->popSymbol();

    Parenthesis * expressionParenthesised = new Parenthesis((Expression*) (e));

    expressionParenthesised->setType(F);
    automaton->programFromLexer.push_front(minus);
    automaton->popState();
    automaton->popState();
    automaton->popState();
    (*automaton->states.begin())->transition(automaton, expressionParenthesised);
    return true;
}

bool E13::transitionPlus(Automaton *automaton, Symbol *plus)
{ 
	Symbol * closeParenthesis = automaton->popSymbol();
	Symbol * e = automaton->popSymbol();
    Symbol * f = automaton->popSymbol();

    Parenthesis * expressionParenthesised = new Parenthesis((Expression*) (e));

    expressionParenthesised->setType(F);
    automaton->programFromLexer.push_front(plus);
    automaton->popState();
    automaton->popState();
    automaton->popState();
    (*automaton->states.begin())->transition(automaton, expressionParenthesised);
    return true;
}


bool E13::transitionDivide(Automaton *automaton, Symbol *divide)
{ 
	Symbol * closeParenthesis = automaton->popSymbol();
	Symbol * e = automaton->popSymbol();
    Symbol * f = automaton->popSymbol();

    Parenthesis * expressionParenthesised = new Parenthesis((Expression*) (e));

    expressionParenthesised->setType(F);
    automaton->programFromLexer.push_front(divide);
    automaton->popState();
    automaton->popState();
    automaton->popState();
    (*automaton->states.begin())->transition(automaton, expressionParenthesised);
    return true;
}


bool E13::transitionMultiply(Automaton *automaton, Symbol *multiply)
{ 
	Symbol * closeParenthesis = automaton->popSymbol();
	Symbol * e = automaton->popSymbol();
    Symbol * f = automaton->popSymbol();

    Parenthesis * expressionParenthesised = new Parenthesis((Expression*) (e));

    expressionParenthesised->setType(F);
    automaton->programFromLexer.push_front(multiply);
    automaton->popState();
    automaton->popState();
    automaton->popState();
    (*automaton->states.begin())->transition(automaton, expressionParenthesised);
    return true;
}
