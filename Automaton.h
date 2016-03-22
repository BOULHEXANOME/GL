//
// Created by hdelval on 08/03/16.
//

class Automaton;
#ifndef GL_AUTOMATON_H
#define GL_AUTOMATON_H


#include "Symbols/Line.h"
#include <map>
#include "Symbols/Symbol.h"
#include "states/DefaultState.h"

class DefaultState;
class Line;

struct var {
    int theValue;
    bool isIntancied = false;
};

class Automaton {
private:
    typedef std::map<std::string, int> AllTheConstants;
    typedef std::map<std::string, var> AllTheVariables;
    typedef std::list<Line> Program;
    typedef std::list<Symbol *> SymbolsStack;
    typedef std::list<DefaultState*> StatesStack;

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
    friend class E16;
    friend class E17;
    friend class E18;
    friend class E19;
    friend class E20;
    friend class E21;
    friend class E22;
    friend class E23;
    friend class E24;
    friend class E25;
    friend class E26;
    friend class E27;
    friend class E28;
    friend class E29;
    friend class E30;
    friend class E31;
    friend class E32;
    friend class E33;
    friend class E34;
    friend class E35;
    friend class E36;
    friend class E37;
    friend class E38;
    friend class E39;
    friend class E40;
    friend class E41;
    friend class E42;
    friend class E43;

    Automaton() { }

    Program programLines;
    AllTheConstants theConstants;
    AllTheVariables theVariables;

    //Liste de symboles lus par le lexer
    SymbolsStack programFromLexer;
    //Pile de symbole utilisée par l'automate
    SymbolsStack symbolsAutomaton;
    //Pile d'etat de l'automate
    StatesStack states;

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
    void testStates2();
    void testStates3();

    /*
     * Method used to print the code in memory
     */
    void printCode();

    /*
     * Method used to analyse the code in memory, and eventually
     * alert the user if errors occurs
     */
    void analyse();

    /*
     * Method used to execute the code in memory, and eventually
     * alert the user if errors occurs
     */
    void execute();

    /*
     * Method used to add a variable declaration to the table of symbols
     */
    bool declareVariable(std::string theName);

    /*
     * Method used to add a constant declaration to the table of symbols
     */
    bool declareAndAffectConst(std::string theName, int theValue);

    /*
     * Method used to change the value of a variable in the table of symbols
     */
    bool affectVariable(std::string theName, int theValue);

    /*
     * Method used to access the value of a variable in the table of symbols
     */
    bool accessVariable(std::string theName, var * toComplete);

    /*
     * Method used to access the value of a constant in the table of symbols
     */
    int accessConstant(std::string theName);

    /*
     * Method used to clear the table of symbols
     */
    void clearTables();

    /*
     * Method singleton
     */
     
    /*
     * Method
     */
    void pushState(Symbol * s, DefaultState * e);
    void pushSymbol(Symbol * s);
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
