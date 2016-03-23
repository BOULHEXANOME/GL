//
// Created by hdelval on 22/03/16.
//

#include "E8.h"
#include "../Symbols/Terminaux/IdTerminal.h"
#include "../Symbols/Nonterminaux/Read.h"
#include "../Symbols/Terminaux/Semicolon.h"

bool E8::transitionSemicolon(Automaton *automaton, Symbol *semicolon)
{
    IdTerminal *id = (IdTerminal*) automaton->popSymbol();
    Symbol * read = automaton->popSymbol();

    Variable* variableToReadFromUser = new Variable(id->getTheName());
    Read* readSymbolInstruction = new Read(variableToReadFromUser);
    Line readInstruct(Type::instruction);
    readInstruct.addSymbol(readSymbolInstruction);
    automaton->addProgramLine(readInstruct);

    variableToReadFromUser->setType(I_PRIME);
    automaton->programFromLexer.push_front(semicolon);
    automaton->popState();
    automaton->popState();
    (*automaton->states.begin())->transition(automaton, variableToReadFromUser);
    return true;
}

E8::E8()
{
    expectedSymbols = "write, read, id, endOfProgram";
    state = 8;
}

bool E8::transitionDefault(Automaton *automaton, Symbol *unknown)
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
