//
// Created by hdelval on 08/03/16.
//

#ifndef GL_AUTOMATON_H
#define GL_AUTOMATON_H


#include "Symbols/Line.h"
#include <map>
class Line;

struct var {
    int theValue;
    bool isIntancied = false;
};

class Automaton {
private:
    typedef std::list<Line> Programm;
    typedef std::map<std::string, int> AllTheConstants;
    typedef std::map<std::string, var> AllTheVariables;

    Automaton() { }

    Programm programLines;
    AllTheConstants theConstants;
    AllTheVariables theVariables;

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
