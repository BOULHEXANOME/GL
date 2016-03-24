#include "DefaultState.h"

bool DefaultState::transition(Automaton *automaton, Symbol *s) {

    if (s->getType() == ERROR) {
        if (automaton->debug) {
            std::cout << "Erreur : passage dans transitionError" << std::endl;
        }

        return transitionError(automaton, s);
    }

    alreadyOneError = false;

    if (automaton->debug)
        std::cout << "On va faire la transition avec le symbole : " << s->getType() << std::endl;

    switch (s->getType()) {
        case PLUS :
            return transitionPlus(automaton, s);
        case MINUS :
            return transitionMinus(automaton, s);
        case MULTIPLY :
            return transitionMultiply(automaton, s);
        case DIVIDE :
            return transitionDivide(automaton, s);
        case WRITE :
            return transitionWrite(automaton, s);
        case READ :
            return transitionRead(automaton, s);
        case AFFECTDECLARE :
            return transitionAffectDeclare(automaton, s);
        case AFFECTINSTRUCT :
            return transitionAffectInstruct(automaton, s);
        case OPENPARENTHESIS :
            return transitionOpenParenthesis(automaton, s);
        case CLOSEPARENTHESIS :
            return transitionCloseParenthesis(automaton, s);
        case VAR :
            return transitionVar(automaton, s);
        case VAL :
            return transitionVal(automaton, s);
        case DOLLAR :
            return transitionDollar(automaton, s);
        case COMMA :
            return transitionComma(automaton, s);
        case SEMICOLON :
            return transitionSemicolon(automaton, s);
        case ID :
            return transitionId(automaton, s);
        case P :
            return transitionP(automaton, s);
        case D :
            return transitionD(automaton, s);
        case D_PRIME :
            return transitionD_Prime(automaton, s);
        case ID_LIST :
            return transitionIdList(automaton, s);
        case AFF :
            return transitionAff(automaton, s);
        case I :
            return transitionI(automaton, s);
        case I_PRIME :
            return transitionI_Prime(automaton, s);
        case E :
            return transitionE(automaton, s);
        case T :
            return transitionT(automaton, s);
        case F :
            return transitionF(automaton, s);
        case OPA :
            return transitionOpA(automaton, s);
        case OPM :
            return transitionOpM(automaton, s);
        case CONST:
            return transitionConst(automaton, s);
        default :
            std::cerr << "Symbole inconnu" << std::endl;
            return false;
    }
}

bool DefaultState::transitionPlus(Automaton *automaton, Symbol *s) {
    return transitionDefault(automaton, s);
}

bool DefaultState::transitionMinus(Automaton *automaton, Symbol *s) {
    return transitionDefault(automaton, s);
}

bool DefaultState::transitionMultiply(Automaton *automaton, Symbol *s) {
    return transitionDefault(automaton, s);
}

bool DefaultState::transitionDivide(Automaton *automaton, Symbol *s) {
    return transitionDefault(automaton, s);
}

bool DefaultState::transitionWrite(Automaton *automaton, Symbol *s) {
    return transitionDefault(automaton, s);
}

bool DefaultState::transitionRead(Automaton *automaton, Symbol *s) {
    return transitionDefault(automaton, s);
}

bool DefaultState::transitionAffectDeclare(Automaton *automaton, Symbol *s) {
    return transitionDefault(automaton, s);
}

bool DefaultState::transitionAffectInstruct(Automaton *automaton, Symbol *s) {
    return transitionDefault(automaton, s);
}

bool DefaultState::transitionOpenParenthesis(Automaton *automaton, Symbol *s) {
    return transitionDefault(automaton, s);
}

bool DefaultState::transitionCloseParenthesis(Automaton *automaton, Symbol *s) {
    return transitionDefault(automaton, s);
}

bool DefaultState::transitionVar(Automaton *automaton, Symbol *s) {
    return transitionDefault(automaton, s);
}

bool DefaultState::transitionVal(Automaton *automaton, Symbol *s) {
    return transitionDefault(automaton, s);
}

bool DefaultState::transitionDollar(Automaton *automaton, Symbol *s) {
    return transitionDefault(automaton, s);
}

bool DefaultState::transitionConst(Automaton *automaton, Symbol *s) {
    return transitionDefault(automaton, s);
}

bool DefaultState::transitionComma(Automaton *automaton, Symbol *s) {
    return transitionDefault(automaton, s);
}

bool DefaultState::transitionSemicolon(Automaton *automaton, Symbol *s) {
    return transitionDefault(automaton, s);
}

bool DefaultState::transitionId(Automaton *automaton, Symbol *s) {
    return transitionDefault(automaton, s);
}

bool DefaultState::transitionDefault(Automaton *automaton, Symbol *s) {
    std::cerr << "Transition impossible" << std::endl;
    return false;
}

bool DefaultState::transitionError(Automaton *automaton, Symbol *s) {
    Symbol *s1 = Automaton::instance().programFromLexer.front();
    Automaton::instance().programFromLexer.pop_front();


    if (!alreadyOneError) {
        std::cerr << "Erreur lexicale, symbole inconnu";
        automaton->printError(s);
        std::cerr << "Un de ces symboles était attendu : [" << expectedSymbols << "]" << std::endl;
        std::cerr << "Essai d'élimination automatique du caractère et récupération." << std::endl;

        alreadyOneError = true;
        return (*automaton->states.begin())->transition(automaton, s1);
    }
    else {
        std::cerr << "Erreur lexicale, symbole inconnu";
        automaton->printError(s);
        std::cerr << "Un de ces symboles était attendu : [" << expectedSymbols << "]" << std::endl;
        std::cerr << "L'essai d'élimination automatique du caractère et de récupération a échoué !" << std::endl;
        std::cerr << "Quitte." << std::endl;

        return false;
    }

}

bool DefaultState::transitionP(Automaton *automaton, Symbol *s) {
    std::cerr << "Transition impossible" << std::endl;
    return false;
}

bool DefaultState::transitionD(Automaton *automaton, Symbol *s) {
    std::cerr << "Transition impossible" << std::endl;
    return false;
}

bool DefaultState::transitionD_Prime(Automaton *automaton, Symbol *s) {
    std::cerr << "Transition impossible" << std::endl;
    return false;
}

bool DefaultState::transitionIdList(Automaton *automaton, Symbol *s) {
    std::cerr << "Transition impossible" << std::endl;
    return false;
}

bool DefaultState::transitionAff(Automaton *automaton, Symbol *s) {
    std::cerr << "Transition impossible" << std::endl;
    return false;
}

bool DefaultState::transitionI(Automaton *automaton, Symbol *s) {
    std::cerr << "Transition impossible" << std::endl;
    return false;
}

bool DefaultState::transitionI_Prime(Automaton *automaton, Symbol *s) {
    std::cerr << "Transition impossible" << std::endl;
    return false;
}

bool DefaultState::transitionE(Automaton *automaton, Symbol *s) {
    std::cerr << "Transition impossible" << std::endl;
    return false;
}

bool DefaultState::transitionT(Automaton *automaton, Symbol *s) {
    std::cerr << "Transition impossible" << std::endl;
    return false;
}

bool DefaultState::transitionF(Automaton *automaton, Symbol *s) {
    std::cerr << "Transition impossible" << std::endl;
    return false;
}

bool DefaultState::transitionOpA(Automaton *automaton, Symbol *s) {
    std::cerr << "Transition impossible" << std::endl;
    return false;
}

bool DefaultState::transitionOpM(Automaton *automaton, Symbol *s) {
    std::cerr << "Transition impossible" << std::endl;
    return false;
}

DefaultState::DefaultState() {
    this->alreadyOneError = false;
    this->state = -1;
}

DefaultState::~DefaultState() {

}

