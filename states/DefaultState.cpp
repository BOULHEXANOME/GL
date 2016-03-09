bool DefaultState::transition (Automaton & automaton, Symbol & s) {

	switch(s->getType()) {
		case PLUS :
			transitionPlus();
			return true;
		case MINUS :
			transitionMinus();
			return true;
		case MULTIPLY :
			transitionMultiply();
			return true;
		case DIVIDE :
			transitionDivide();
			return true;
		case WRITE :
			transitionWrite();
			return true;
		case READ :
			transitionRead();
			return true;
		case AFFECTDECLARE :
			transitionAffectDeclare();
			return true;
		case AFFECTINSTRUCT :
			transitionAffectInstruct();
			return true;
		case OPENPARENTHESIS :
			transitionOpenParenthesis();
			return true;
		case CLOSEPARENTHESIS :
			transitionCloseParenthesis();
			return true;
		case VAR :
			transitionVar();
			return true;
		case VAL :
			transitionVal();
			return true;
		case DOLLAR :
			transitionDollar();
			return true;
		case COMMA :
			transitionComma();
			return true;
		case SEMICOLON :
			transitionSemicolon();
			return true;
		case ID :
			transitionId();
			return true;
		case ERROR :
			transitionError();
			return true;
		default :
			return false;
    }
}

bool transitionPlus() {
	return false;
}

bool transitionMinus(){
	return false;
}

bool transitionMultiply(){
	return false;
}

bool transitionDivide(){
	return false;
}

bool transitionWrite(){
	return false;
}

bool transitionRead(){
	return false;
}

bool transitionAffectDeclare(){
	return false;
}

bool transitionAffectInstruct(){
	return false;
}

bool transitionOpenParenthesis(){
	return false;
}

bool transitionCloseParenthesis(){
	return false;
}

bool transitionVar(){
	return false;
}

bool transitionVal(){
	return false;
}

bool transitionDollar(){
	return false;
}

bool transitionConst(){
	return false;
}

bool transitionComma(){
	return false;
}

bool transitionSemilicon(){
	return false;
}

bool transitionId(){
	return false;
}

bool transitionError(){
	return false;
}


