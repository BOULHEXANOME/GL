//
// Created by hdelval on 08/03/16.
//

#ifndef GL_AUTOMATON_H
#define GL_AUTOMATON_H


#include "Symbols/Line.h"

class Automaton {
private:
    std::list<Line> programLines;
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
