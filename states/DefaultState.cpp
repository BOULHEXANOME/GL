#include "DefaultState.h"

bool DefaultState::transition (Automaton * automaton, Symbol * s) {
	std::cout << "On va faire la transition avec le symbole : " << s->getType()<< std::endl;
	switch(s->getType()) {
		case PLUS :
			transitionPlus(automaton, s);
			return true;
		case MINUS :
			transitionMinus(automaton, s);
			return true;
		case MULTIPLY :
			transitionMultiply(automaton, s);
			return true;
		case DIVIDE :
			transitionDivide(automaton, s);
			return true;
		case WRITE :
			transitionWrite(automaton, s);
			return true;
		case READ :
			transitionRead(automaton, s);
			return true;
		case AFFECTDECLARE :
			transitionAffectDeclare(automaton, s);
			return true;
		case AFFECTINSTRUCT :
			transitionAffectInstruct(automaton, s);
			return true;
		case OPENPARENTHESIS :
			transitionOpenParenthesis(automaton, s);
			return true;
		case CLOSEPARENTHESIS :
			transitionCloseParenthesis(automaton, s);
			return true;
		case VAR :
			transitionVar(automaton, s);
			return true;
		case VAL :
			transitionVal(automaton, s);
			return true;
		case DOLLAR :
			transitionDollar(automaton, s);
			return true;
		case COMMA :
			transitionComma(automaton, s);
			return true;
		case SEMICOLON :
			transitionSemicolon(automaton, s);
			return true;
		case ID :
			transitionId(automaton, s);
			return true;
		case P :
			transitionP(automaton, s);
			return true;
		case D :
			transitionD(automaton, s);
			return true;
		case D_PRIME :
			transitionD_Prime(automaton, s);
			return true;
		case ID_LISTE :
			transitionId_Liste(automaton, s);
			return true;
		case AFF :
			transitionAff(automaton, s);
			return true;
		case I :
			transitionI(automaton, s);
			return true;
		case I_PRIME :
			transitionI_Prime(automaton, s);
			return true;
		case E :
			transitionE(automaton, s);
			return true;
		case T :
			transitionT(automaton, s);
			return true;
		case F :
			transitionF(automaton, s);
			return true;
		case OPA :
			transitionOpA(automaton, s);
			return true;
		case OPM :
			transitionOpM(automaton, s);
			return true;
		case ERROR :
			transitionError(automaton, s);
			return true;
			
		default :
			return false;
    }
}

bool DefaultState::transitionPlus(Automaton * automaton, Symbol * s) {
	return false;
}

bool DefaultState::transitionMinus(Automaton * automaton, Symbol * s){
	return false;
}

bool DefaultState::transitionMultiply(Automaton * automaton, Symbol * s){
	return false;
}

bool DefaultState::transitionDivide(Automaton * automaton, Symbol * s){
	return false;
}

bool DefaultState::transitionWrite(Automaton * automaton, Symbol * s){
	return false;
}

bool DefaultState::transitionRead(Automaton * automaton, Symbol * s){
	return false;
}

bool DefaultState::transitionAffectDeclare(Automaton * automaton, Symbol * s){
	return false;
}

bool DefaultState::transitionAffectInstruct(Automaton * automaton, Symbol * s){
	return false;
}

bool DefaultState::transitionOpenParenthesis(Automaton * automaton, Symbol * s){
	return false;
}

bool DefaultState::transitionCloseParenthesis(Automaton * automaton, Symbol * s){
	return false;
}

bool DefaultState::transitionVar(Automaton * automaton, Symbol * s){
	return false;
}

bool DefaultState::transitionVal(Automaton * automaton, Symbol * s){
	return false;
}

bool DefaultState::transitionDollar(Automaton * automaton, Symbol * s){
	return false;
}

bool DefaultState::transitionConst(Automaton * automaton, Symbol * s){
	return false;
}

bool DefaultState::transitionComma(Automaton * automaton, Symbol * s){
	return false;
}

bool DefaultState::transitionSemicolon(Automaton * automaton, Symbol * s){
	return false;
}

bool DefaultState::transitionId(Automaton * automaton, Symbol * s){
	return false;
}

bool DefaultState::transitionError(Automaton * automaton, Symbol * s){
	return false;
}

bool DefaultState::transitionP(Automaton * automaton, Symbol * s){
	return false;
}

bool DefaultState::transitionD(Automaton * automaton, Symbol * s){
	return false;
}

bool DefaultState::transitionD_Prime(Automaton * automaton, Symbol * s){
	return false;
}

bool DefaultState::transitionId_Liste(Automaton * automaton, Symbol * s){
	return false;
}

bool DefaultState::transitionAff(Automaton * automaton, Symbol * s){
	return false;
}

bool DefaultState::transitionI(Automaton * automaton, Symbol * s){
	return false;
}

bool DefaultState::transitionI_Prime(Automaton * automaton, Symbol * s){
	return false;
}

bool DefaultState::transitionE(Automaton * automaton, Symbol * s){
	return false;
}

bool DefaultState::transitionT(Automaton * automaton, Symbol * s){
	return false;
}

bool DefaultState::transitionF(Automaton * automaton, Symbol * s){
	return false;
}

bool DefaultState::transitionOpA(Automaton * automaton, Symbol * s){
	return false;
}

bool DefaultState::transitionOpM(Automaton * automaton, Symbol * s){
	return false;
}

DefaultState::DefaultState(){
	this->state = -1;
}

DefaultState::~DefaultState(){
	
}
