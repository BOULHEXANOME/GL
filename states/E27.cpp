#include "E27.h"
#include "../Symbols/Nonterminaux/PlusExpression.h"
#include "../Symbols/Nonterminaux/MinusExpression.h"
#include "../Symbols/Nonterminaux/OpA.h"
#include "../Symbols/Nonterminaux/Expression.h"

E27::E27()
{
    state = 27;
}
/*
bool transitionMultiply(Automaton * automaton, Symbol * s) {
	automaton->pushState(s, E32());
	return true;
}

bool transitionDivide(Automaton * automaton, Symbol * s) {
	automaton->pushState(s, E33());
	return true;
}

bool transitionOpM(Automaton * automaton, Symbol * s) {
	automaton->pushState(s, E30());
	return true;
}*/

bool E27::transitionPlus(Automaton * automaton, Symbol * plus) {
	Symbol * t = automaton->popSymbol();
	Symbol * opa = automaton->popSymbol();
	Symbol * e = automaton->popSymbol();
	
	automaton->popState();
	automaton->popState();
	automaton->popState();
	
	OpA * operateur = (OpA*) (opa);
	Expression * expression = (Expression *) (e);
	Expression * terme = (Expression *) (t);
	
	Expression * opaExpression;
	if(operateur->getOp()==MINUS){
		opaExpression = new MinusExpression(expression, terme);
	}else{
		opaExpression = new PlusExpression(expression, terme);
	}
	
	opaExpression->setType(E);
		
	automaton->programFromLexer.push_front(plus);
	
	(*automaton->states.begin())->transition(automaton,opaExpression);
	return true;
}

bool E27::transitionMinus(Automaton * automaton, Symbol * minus) {
		Symbol * t = automaton->popSymbol();
	Symbol * opa = automaton->popSymbol();
	Symbol * e = automaton->popSymbol();
	
	automaton->popState();
	automaton->popState();
	automaton->popState();
	
	OpA * operateur = (OpA*) (opa);
	Expression * expression = (Expression *) (e);
	Expression * terme = (Expression *) (t);
	
	Expression * opaExpression;
	if(operateur->getOp()==MINUS){
		opaExpression = new MinusExpression(expression, terme);
	}else{
		opaExpression = new PlusExpression(expression, terme);
	}
	
	opaExpression->setType(E);
		
	automaton->programFromLexer.push_front(minus);
	
	(*automaton->states.begin())->transition(automaton,opaExpression);
	return true;
}

bool E27::transitionClosingParenthesis(Automaton * automaton, Symbol * parenthesis) {
	
	Symbol * t = automaton->popSymbol();
	Symbol * opa = automaton->popSymbol();
	Symbol * e = automaton->popSymbol();
	
	automaton->popState();
	automaton->popState();
	automaton->popState();
	
	OpA * operateur = (OpA*) (opa);
	Expression * expression = (Expression *) (e);
	Expression * terme = (Expression *) (t);
	
	Expression * opaExpression;
	if(operateur->getOp()==MINUS){
		opaExpression = new MinusExpression(expression, terme);
	}else{
		opaExpression = new PlusExpression(expression, terme);
	}
	
	opaExpression->setType(E);
		
	automaton->programFromLexer.push_front(parenthesis);
	
	(*automaton->states.begin())->transition(automaton,opaExpression);
	return true;
}

bool E27::transitionSemicolon(Automaton * automaton, Symbol * semicolon) {
	Symbol * t = automaton->popSymbol();
	Symbol * opa = automaton->popSymbol();
	Symbol * e = automaton->popSymbol();
	
	automaton->popState();
	automaton->popState();
	automaton->popState();
	
	OpA * operateur = (OpA*) (opa);
	Expression * expression = (Expression *) (e);
	Expression * terme = (Expression *) (t);
	
	Expression * opaExpression;
	if(operateur->getOp()==MINUS){
		opaExpression = new MinusExpression(expression, terme);
	}else{
		opaExpression = new PlusExpression(expression, terme);
	}
	
	opaExpression->setType(E);
		
	automaton->programFromLexer.push_front(semicolon);
	
	(*automaton->states.begin())->transition(automaton,opaExpression);
	return true;
}
