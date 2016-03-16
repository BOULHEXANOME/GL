bool DefaultState::transition (Automaton * automaton, Symbol * s) {

	switch(s->getType()) {
		case PLUS :
			transitionPlus(Automaton * automaton, Symbol * s);
			return true;
		case MINUS :
			transitionMinus(Automaton * automaton, Symbol * s);
			return true;
		case MULTIPLY :
			transitionMultiply(Automaton * automaton, Symbol * s);
			return true;
		case DIVIDE :
			transitionDivide(Automaton * automaton, Symbol * s);
			return true;
		case WRITE :
			transitionWrite(Automaton * automaton, Symbol * s);
			return true;
		case READ :
			transitionRead(Automaton * automaton, Symbol * s);
			return true;
		case AFFECTDECLARE :
			transitionAffectDeclare(Automaton * automaton, Symbol * s);
			return true;
		case AFFECTINSTRUCT :
			transitionAffectInstruct(Automaton * automaton, Symbol * s);
			return true;
		case OPENPARENTHESIS :
			transitionOpenParenthesis(Automaton * automaton, Symbol * s);
			return true;
		case CLOSEPARENTHESIS :
			transitionCloseParenthesis(Automaton * automaton, Symbol * s);
			return true;
		case VAR :
			transitionVar(Automaton * automaton, Symbol * s);
			return true;
		case VAL :
			transitionVal(Automaton * automaton, Symbol * s);
			return true;
		case DOLLAR :
			transitionDollar(Automaton * automaton, Symbol * s);
			return true;
		case COMMA :
			transitionComma(Automaton * automaton, Symbol * s);
			return true;
		case SEMICOLON :
			transitionSemicolon(Automaton * automaton, Symbol * s);
			return true;
		case ID :
			transitionId(Automaton * automaton, Symbol * s);
			return true;
		case P :
			transitionP(Automaton * automaton, Symbol * s);
			return true;
		case D :
			transitionD(Automaton * automaton, Symbol * s);
			return true;
		case D_PRIME :
			transitionD_Prime(Automaton * automaton, Symbol * s);
			return true;
		case ID_LISTE :
			transitionId_Liste(Automaton * automaton, Symbol * s);
			return true;
		case AFF :
			transitionAff(Automaton * automaton, Symbol * s);
			return true;
		case I :
			transitionI(Automaton * automaton, Symbol * s);
			return true;
		case I_PRIME :
			transitionI_Prime(Automaton * automaton, Symbol * s);
			return true;
		case E :
			transitionE(Automaton * automaton, Symbol * s);
			return true;
		case T :
			transitionT(Automaton * automaton, Symbol * s);
			return true;
		case F :
			transitionF(Automaton * automaton, Symbol * s);
			return true;
		case OPA :
			transitionOpA(Automaton * automaton, Symbol * s);
			return true;
		case OPM :
			transitionOpM(Automaton * automaton, Symbol * s);
			return true;
		case ERROR :
			transitionError(Automaton * automaton, Symbol * s);
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

bool DefaultState::transitionSemilicon(Automaton * automaton, Symbol * s){
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
