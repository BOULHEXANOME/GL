#include "E27.h"
#include "E32.h"
#include "E33.h"
#include "E30.h"
#include "../Symbols/Nonterminaux/PlusExpression.h"
#include "../Symbols/Nonterminaux/MinusExpression.h"
#include "../Symbols/Nonterminaux/OpA.h"
#include "../Symbols/Nonterminaux/Expression.h"
#include "../Symbols/Terminaux/Semicolon.h"

E27::E27()
{
    state = 27;
	expectedSymbols = "*, /, +, -, ), ;, multiplicative or dividing operation";
}

bool E27::transitionMultiply(Automaton * automaton, Symbol * multiply) {
	automaton->pushState(multiply, new E32());
	return true;
}

bool E27::transitionDivide(Automaton * automaton, Symbol * divide) {
	automaton->pushState(divide, new E33());
	return true;
}

bool E27::transitionOpM(Automaton * automaton, Symbol * opm) {
	automaton->pushState(opm, new E30());
	return true;
}

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

bool E27::transitionCloseParenthesis(Automaton * automaton, Symbol * parenthesis) {
	
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

bool E27::transitionDefault(Automaton *automaton, Symbol *unknown)
{
    std::cerr << "Erreur syntaxique, symbole non attendu";
    automaton->printError(unknown);
    std::cerr << "Un de ces symboles était attendu : [" << expectedSymbols << "]" << std::endl;
    std::cerr << "L'automate assume que le point virgule a été oublié, et continue donc avec le symbole ';'." << std::endl;

    // on simule une transition sur semicolon
    automaton->programFromLexer.push_front(unknown);
    Symbol * semicolon = new Semicolon();
    transitionSemicolon(automaton, semicolon);

    return true;
}
