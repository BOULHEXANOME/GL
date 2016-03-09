bool DefaultState::transition (Automaton & automaton, Symbol & s) {

	switch(s->getType()) {
		case PLUS :
			transitionPlus(Automaton & automaton, Symbol & s);
			return true;
		case MINUS :
			transitionMinus(Automaton & automaton, Symbol & s);
			return true;
		case MULTIPLY :
			transitionMultiply(Automaton & automaton, Symbol & s);
			return true;
		case DIVIDE :
			transitionDivide(Automaton & automaton, Symbol & s);
			return true;
		case WRITE :
			transitionWrite(Automaton & automaton, Symbol & s);
			return true;
		case READ :
			transitionRead(Automaton & automaton, Symbol & s);
			return true;
		case AFFECTDECLARE :
			transitionAffectDeclare(Automaton & automaton, Symbol & s);
			return true;
		case AFFECTINSTRUCT :
			transitionAffectInstruct(Automaton & automaton, Symbol & s);
			return true;
		case OPENPARENTHESIS :
			transitionOpenParenthesis(Automaton & automaton, Symbol & s);
			return true;
		case CLOSEPARENTHESIS :
			transitionCloseParenthesis(Automaton & automaton, Symbol & s);
			return true;
		case VAR :
			transitionVar(Automaton & automaton, Symbol & s);
			return true;
		case VAL :
			transitionVal(Automaton & automaton, Symbol & s);
			return true;
		case DOLLAR :
			transitionDollar(Automaton & automaton, Symbol & s);
			return true;
		case COMMA :
			transitionComma(Automaton & automaton, Symbol & s);
			return true;
		case SEMICOLON :
			transitionSemicolon(Automaton & automaton, Symbol & s);
			return true;
		case ID :
			transitionId(Automaton & automaton, Symbol & s);
			return true;
		case ERROR :
			transitionError(Automaton & automaton, Symbol & s);
			return true;
		default :
			return false;
    }
}

bool transitionPlus(Automaton & automaton, Symbol & s) {
	return false;
}

bool transitionMinus(Automaton & automaton, Symbol & s){
	return false;
}

bool transitionMultiply(Automaton & automaton, Symbol & s){
	return false;
}

bool transitionDivide(Automaton & automaton, Symbol & s){
	return false;
}

bool transitionWrite(Automaton & automaton, Symbol & s){
	return false;
}

bool transitionRead(Automaton & automaton, Symbol & s){
	return false;
}

bool transitionAffectDeclare(Automaton & automaton, Symbol & s){
	return false;
}

bool transitionAffectInstruct(Automaton & automaton, Symbol & s){
	return false;
}

bool transitionOpenParenthesis(Automaton & automaton, Symbol & s){
	return false;
}

bool transitionCloseParenthesis(Automaton & automaton, Symbol & s){
	return false;
}

bool transitionVar(Automaton & automaton, Symbol & s){
	return false;
}

bool transitionVal(Automaton & automaton, Symbol & s){
	return false;
}

bool transitionDollar(Automaton & automaton, Symbol & s){
	return false;
}

bool transitionConst(Automaton & automaton, Symbol & s){
	return false;
}

bool transitionComma(Automaton & automaton, Symbol & s){
	return false;
}

bool transitionSemilicon(Automaton & automaton, Symbol & s){
	return false;
}

bool transitionId(Automaton & automaton, Symbol & s){
	return false;
}

bool transitionError(Automaton & automaton, Symbol & s){
	return false;
}


