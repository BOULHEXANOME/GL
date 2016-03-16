//
// Created by hdelval on 08/03/16.
//

#ifndef GL_AUTOMATON_H
#define GL_AUTOMATON_H


#include "Symbols/Line.h"
#include "States/DefaultState.h"

class Automaton {
private:
    typedef std::list<Line> Programm;
    Programm programLines;
	
    Automaton() { }

public:

	//Liste de symboles lus par le lexer
	std::list <Symbol*> programme;
	//Pile de symbole utilisée par l'automate
	std::list <Symbol*> symbols;
	//Pile d'etat de l'automate
	std::list <DefaultState*> states;
	//Etat courant de l'automate (haut de la pile d'etat) => choix de conception actuel a modifier peut-etre
	DefaultState *CurrentState;
	
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
