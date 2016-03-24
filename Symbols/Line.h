//
// Created by hdelval on 04/03/16.
//

#ifndef GL_LINE_H
#define GL_LINE_H

#include <list>
#include <string>
#include "Symbol.h"
#include "../Automaton.h"
class Symbol;
class Automaton;

enum Type {declaration, instruction};

class Line
{
protected:
    Symbol * theSymbol;
    Type typeOfLine;

public:

    /***********************/
    /***** Contructors *****/
    /***********************/
    Line(Type typeOfLine) : typeOfLine(typeOfLine) { }
    Line() { }
    /***********************/
    /*** End Contructors ***/
    /***********************/

    /***********************/
    /*** Getters/Setters ***/
    /***********************/

    Symbol *getTheSymbol() const
    {
        return theSymbol;
    }

    void addSymbol(Symbol * symbolsToAdd);

    const Type & getTypeOfLine() const
    {
        return typeOfLine;
    }

    void setTypeOfLine(const Type &typeOfLine)
    {
        Line::typeOfLine = typeOfLine;
    }
    /***********************/
    /* End Getters/Setters */
    /***********************/


    /************************/
    /** Override operators **/
    /************************/
    friend std::ostream & operator<<(std::ostream& os, const Line & line);
    /************************/
    /*End Override operators /
    /************************/

    /***********************/
    /******* Methods *******/
    /***********************/

    /*
     * Execute all symbols in Line (just one normally)
     */
    void execute() const;

    /*
     * Optimize line
     */
    bool optimize();

    /***********************/
    /***** End Methods *****/
    /***********************/
};


#endif //GL_LINE_H
