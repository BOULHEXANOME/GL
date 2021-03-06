//
// Created by hdelval on 08/03/16.
//

class Automaton;
#ifndef GL_AUTOMATON_H
#define GL_AUTOMATON_H

#include <map>
#include <vector>
#include "Symbols/Line.h"
#include "Symbols/Symbol.h"
#include "states/DefaultState.h"

class DefaultState;
class Line;

struct var {
    int theValue;
    bool isIntancied = false;
    bool isUsed = false;
};

struct constant {
    int theValue;
    bool isUsed = false;
};

class Automaton {
private:
    typedef std::map<std::string, constant> AllTheConstants;
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
    friend class E44;

    Program programLines;
    AllTheConstants theConstants;
    AllTheVariables theVariables;

    //Liste de symboles lus par le lexer
    SymbolsStack programFromLexer;
    //Pile de symbole utilisée par l'automate
    SymbolsStack symbolsAutomaton;
    //Pile d'etat de l'automate
    StatesStack states;

    //Fichier texte lu par le Lexer
    std::vector<std::string> stringsOfTheFile;

    bool debug;


    Automaton()
    {
        debug = false;
    }
public:
    // this two lines forbid copy of singleton
    Automaton(Automaton const&) = delete;
    void operator=(Automaton const&) = delete;
    ~Automaton();

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


    bool isDebug() const
    {
        return debug;
    }
    
    void setStringsOfTheFile(std::vector<std::string> theStringsOfTheFile)
    {
		this->stringsOfTheFile = theStringsOfTheFile;
	}

    /***********************/
    /* End Getters/Setters */
    /***********************/


    /***********************/
    /******* Methods *******/
    /***********************/

    /*
     * Method used to print the code in memory
     */
    void printCode();

    /*
     * Method used to analyse the code in memory, and eventually
     * alert the user if errors occurs
     */
    bool analyse();

    /*
     * Method used to add a variable declaration to the table of symbols
     */
    bool analyseDeclareVariable(std::string theName);

    /*
     * Method used to add a constant declaration to the table of symbols
     */
    bool analyseDeclareAndAffectConst(std::string theName);

    /*
     * Method used to change the value of a variable in the table of symbols
     */
    bool analyseAffectVariable(std::string theName);

    /*
     * Method used to access the value of a variable in the table of symbols
     */
    bool analyseAccessVariable(std::string theName);

    /*
     * Method used to access the value of a constant in the table of symbols
     */
    bool analyseAccessConstant(std::string theName);

    /*
     * Method used to execute the code in memory, and eventually
     * alert the user if errors occurs
     */
    void execute();
    
    /*
     *
     */
    void launchProgramExtraction();

    /*
     * Method used to add a variable declaration to the table of symbols
     */
    bool declareVariable(std::string theName, bool quiet=false);

    /*
     * Method used to add a constant declaration to the table of symbols
     */
    bool declareAndAffectConst(std::string theName, int theValue);

    /*
     * Method used to change the value of a variable in the table of symbols
     */
    bool affectVariable(std::string theName, int theValue, bool quiet=false);

    /*
     * Method used to access the value of a variable in the table of symbols
     */
    bool accessVariable(std::string theName, var * toComplete, bool quiet=false);


    /*
     * Method used to clear the table of symbols
     */
    void clearTables();

     
    /*
     * Methods managing states and symbols
     */
    void pushState(Symbol * s, DefaultState * e);
    void pushSymbol(Symbol * s);
    Symbol* popSymbol();
    void popState();
    void accept();
    
    /*
     * Error Handling
     */
     void printError(const Symbol* problematicSymbol);

    /*
     * Method singleton
     */
    static Automaton & instance()
    {
        static Automaton automatonInstance;
        return automatonInstance;
    }

    /*
     * Method to optimize
     */
    void optimize();

    /***********************/
    /***** End Methods *****/
    /***********************/


};


#endif //GL_AUTOMATON_H
