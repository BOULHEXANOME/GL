//
// Created by hdelval on 08/03/16.
//

class Automaton;
#ifndef GL_AUTOMATON_H
#define GL_AUTOMATON_H


#include "Symbols/Line.h"
#include "Symbols/Symbol.h"
#include "states/DefaultState.h"
//#include "States/DefaultState.h"


class DefaultState;

class Automaton {
private:
    typedef std::list<Line> Program;
    typedef std::list<Symbol *> SymbolsStack;
    typedef std::list<DefaultState*> StatesStack;
    Program programLines;

    //Liste de symboles lus par le lexer
    SymbolsStack programFromLexer;
    //Pile de symbole utilisée par l'automate
    SymbolsStack symbolsAutomaton;
    //Pile d'etat de l'automate
    StatesStack states;
    //Etat courant de l'automate (haut de la pile d'etat)
    StatesStack::iterator currentState;

    friend class DefaultState;
    friend class E0;
    friend class E1;
    friend class E2;
    friend class E3;
    friend class E4;
    friend class E5;
    friend class E6;
    friend class E7;
    friend class E8;
    friend class E9;
    friend class E10;
    friend class E11;
    friend class E12;
    friend class E13;
    friend class E14;
    friend class E15;


    Automaton() { }

public:
    // this two lines forbid copy of singleton
    Automaton(Automaton const&) = delete;
    void operator=(Automaton const&) = delete;

    /***********************/
    /*** Getters/Setters ***/
    /***********************/
    const std::list<Line> & getProgramLines() const
    {
        return programLines;
    }

    void setProgramLines(const std::list<Line> & programLines)
    {
        Automaton::programLines = programLines;
    }

    void addProgramLine(Line & lineToAdd)
    {
        this->programLines.push_back(lineToAdd);
    }
    /***********************/
    /* End Getters/Setters */
    /***********************/


    /***********************/
    /******* Methods *******/
    /***********************/

    /*
     * Method used to test the creation and deletion of symbols
     * (just to test)
     */
    void createAndDeleteSomeLines();
    void createSomeLines();
    
    void testStates();

    /*
     * Method used to print the code in memory
     */
    void printCode();

    /*
     * Method singleton
     */
     
    /*
     * Method
     */
    void pushState(Symbol * s, DefaultState * e);
    Symbol* popSymbol();
    void popState();
    void accept();
    
    /*
     * 
     */ 
    static Automaton & instance()
    {
        static Automaton automatonInstance;
        return automatonInstance;
    }
    /***********************/
    /***** End Methods *****/
    /***********************/


};


#endif //GL_AUTOMATON_H
