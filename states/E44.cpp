#include "E44.h"
#include "../Symbols/Nonterminaux/DivideExpression.h"
#include "../Symbols/Nonterminaux/MultiplyExpression.h"
#include "../Symbols/Nonterminaux/OpM.h"
#include "../Symbols/Nonterminaux/Expression.h"
#include "../Symbols/Terminaux/MinusTerminal.h"

bool E44::transitionMultiply(Automaton * automaton, Symbol * multiply) {
	Symbol * f = automaton->popSymbol();
	Symbol * opm = automaton->popSymbol();
	Symbol * t = automaton->popSymbol();
	
	automaton->popState();
	automaton->popState();
	automaton->popState();
	
	OpM * operateur = (OpM*) (opm);
	Expression * facteur = (Expression *) (f);
	Expression * terme = (Expression *) (t);
	
	Expression * opmExpression;
	if(operateur->getOp()==MULTIPLY){
		opmExpression = new MultiplyExpression(terme, facteur);
	}else{
		opmExpression = new DivideExpression(terme, facteur);
	}

    facteur->setColumnWhereSymbolOccurs(f->getColumnWhereSymbolOccurs());
    facteur->setLineWhereSymbolOccurs(f->getLineWhereSymbolOccurs());
    opmExpression->setColumnWhereSymbolOccurs(f->getColumnWhereSymbolOccurs());
    opmExpression->setLineWhereSymbolOccurs(f->getLineWhereSymbolOccurs());
	delete opm;
	
	opmExpression->setType(T);
	automaton->programFromLexer.push_front(multiply);
	(*automaton->states.begin())->transition(automaton,opmExpression);
	return true;
}

bool E44::transitionDivide(Automaton * automaton, Symbol * divide) {
	Symbol * f = automaton->popSymbol();
	Symbol * opm = automaton->popSymbol();
	Symbol * t = automaton->popSymbol();
	
	automaton->popState();
	automaton->popState();
	automaton->popState();
	
	OpM * operateur = (OpM*) (opm);
	Expression * facteur = (Expression *) (f);
	Expression * terme = (Expression *) (t);
	
	Expression * opmExpression;
	if(operateur->getOp()==MULTIPLY){
		opmExpression = new MultiplyExpression(terme, facteur);
	}else{
		opmExpression = new DivideExpression(terme, facteur);
	}

    facteur->setColumnWhereSymbolOccurs(f->getColumnWhereSymbolOccurs());
    facteur->setLineWhereSymbolOccurs(f->getLineWhereSymbolOccurs());
    opmExpression->setColumnWhereSymbolOccurs(f->getColumnWhereSymbolOccurs());
    opmExpression->setLineWhereSymbolOccurs(f->getLineWhereSymbolOccurs());
	delete opm;
	opmExpression->setType(T);
	automaton->programFromLexer.push_front(divide);
	(*automaton->states.begin())->transition(automaton,opmExpression);
	return true;
}

bool E44::transitionCloseParenthesis(Automaton * automaton, Symbol * closeParenthesis) {
	Symbol * f = automaton->popSymbol();
	Symbol * opm = automaton->popSymbol();
	Symbol * t = automaton->popSymbol();
	
	automaton->popState();
	automaton->popState();
	automaton->popState();
	
	OpM * operateur = (OpM*) (opm);
	Expression * facteur = (Expression *) (f);
	Expression * terme = (Expression *) (t);
	
	Expression * opmExpression;
	if(operateur->getOp()==MULTIPLY){
		opmExpression = new MultiplyExpression(terme, facteur);
	}else{
		opmExpression = new DivideExpression(terme, facteur);
	}

    facteur->setColumnWhereSymbolOccurs(f->getColumnWhereSymbolOccurs());
    facteur->setLineWhereSymbolOccurs(f->getLineWhereSymbolOccurs());
    opmExpression->setColumnWhereSymbolOccurs(f->getColumnWhereSymbolOccurs());
    opmExpression->setLineWhereSymbolOccurs(f->getLineWhereSymbolOccurs());
	delete opm;
	opmExpression->setType(T);
	automaton->programFromLexer.push_front(closeParenthesis);
	(*automaton->states.begin())->transition(automaton,opmExpression);
	return true;
}

bool E44::transitionSemicolon(Automaton * automaton, Symbol * semicolon) {
	Symbol * f = automaton->popSymbol();
	Symbol * opm = automaton->popSymbol();
	Symbol * t = automaton->popSymbol();
	
	automaton->popState();
	automaton->popState();
	automaton->popState();
	
	OpM * operateur = (OpM*) (opm);
	Expression * facteur = (Expression *) (f);
	Expression * terme = (Expression *) (t);
	
	Expression * opmExpression;
	if(operateur->getOp()==MULTIPLY){
		opmExpression = new MultiplyExpression(terme, facteur);
	}else{
		opmExpression = new DivideExpression(terme, facteur);
	}

    facteur->setColumnWhereSymbolOccurs(f->getColumnWhereSymbolOccurs());
    facteur->setLineWhereSymbolOccurs(f->getLineWhereSymbolOccurs());
    opmExpression->setColumnWhereSymbolOccurs(f->getColumnWhereSymbolOccurs());
    opmExpression->setLineWhereSymbolOccurs(f->getLineWhereSymbolOccurs());
	delete opm;
	opmExpression->setType(T);
	automaton->programFromLexer.push_front(semicolon);
	(*automaton->states.begin())->transition(automaton,opmExpression);
	return true;
}

bool E44::transitionPlus(Automaton * automaton, Symbol * plus) {
	Symbol * f = automaton->popSymbol();
	Symbol * opm = automaton->popSymbol();
	Symbol * t = automaton->popSymbol();
	
	automaton->popState();
	automaton->popState();
	automaton->popState();
	
	OpM * operateur = (OpM*) (opm);
	Expression * facteur = (Expression *) (f);
	Expression * terme = (Expression *) (t);
	
	Expression * opmExpression;
	if(operateur->getOp()==MULTIPLY){
		opmExpression = new MultiplyExpression(terme, facteur);
	}else{
		opmExpression = new DivideExpression(terme, facteur);
	}

    facteur->setColumnWhereSymbolOccurs(f->getColumnWhereSymbolOccurs());
    facteur->setLineWhereSymbolOccurs(f->getLineWhereSymbolOccurs());
    opmExpression->setColumnWhereSymbolOccurs(f->getColumnWhereSymbolOccurs());
    opmExpression->setLineWhereSymbolOccurs(f->getLineWhereSymbolOccurs());
	delete opm;
	opmExpression->setType(T);
	automaton->programFromLexer.push_front(plus);
	(*automaton->states.begin())->transition(automaton,opmExpression);
	return true;
}

bool E44::transitionMinus(Automaton * automaton, Symbol * minus) {
	Symbol * f = automaton->popSymbol();
	Symbol * opm = automaton->popSymbol();
	Symbol * t = automaton->popSymbol();
	
	automaton->popState();
	automaton->popState();
	automaton->popState();

	OpM * operateur = (OpM*) (opm);
	Expression * facteur = (Expression *) (f);
	Expression * terme = (Expression *) (t);

	Expression * opmExpression;
	if(operateur->getOp()==MULTIPLY){
		opmExpression = new MultiplyExpression(terme, facteur);
	}else{
		opmExpression = new DivideExpression(terme, facteur);
	}

    facteur->setColumnWhereSymbolOccurs(f->getColumnWhereSymbolOccurs());
    facteur->setLineWhereSymbolOccurs(f->getLineWhereSymbolOccurs());
    opmExpression->setColumnWhereSymbolOccurs(f->getColumnWhereSymbolOccurs());
    opmExpression->setLineWhereSymbolOccurs(f->getLineWhereSymbolOccurs());

	delete opm;
	opmExpression->setType(T);
	automaton->programFromLexer.push_front(minus);
	(*automaton->states.begin())->transition(automaton,opmExpression);
	return true;
}

E44::E44()
{
    state = 44;
}

bool E44::transitionDefault(Automaton *automaton, Symbol *unknown) {
	std::cerr << "Erreur syntaxique, symbole non attendu";
	automaton->printError(unknown);
	std::cerr << "Un de ces symboles était attendu : [" << expectedSymbols << "]" << std::endl;
	std::cerr << "L'automate assume que un '-' a été oublié, et continue donc avec avec ce symbole." << std::endl;

	// on simule une transition sur ecrire
	automaton->programFromLexer.push_front(unknown);
	Symbol * minus = new MinusTerminal();
	transitionMinus(automaton, minus);
	return true;
}
