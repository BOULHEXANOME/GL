//
// Created by hdelval on 04/03/16.
//

#ifndef GL_LINE_H
#define GL_LINE_H

#include <list>
#include <string>
#include "Symbol.h"

enum Type {declaration, instruction};

class Line {
protected:
    typedef std::list<Symbol*> ListOfSymbols;
    ListOfSymbols symbols;
    Type typeOfLine;

public:

    /***********************/
    /***** Contructors *****/
    /***********************/
    Line(Type typeOfLine) : typeOfLine(typeOfLine) { }
    Line(const ListOfSymbols &symbols, Type typeOfLine) : symbols(symbols), typeOfLine(typeOfLine) { }
    Line() { }
    /***********************/
    /*** End Contructors ***/
    /***********************/

    /***********************/
    /*** Getters/Setters ***/
    /***********************/
    const ListOfSymbols & getSymbols() const
    {
        return symbols;
    }

    void setSymbols(const ListOfSymbols & symbols)
    {
        this->symbols = symbols;
    }

    void addSymbol(Symbol * symbolsToAdd)
    {
        this->symbols.push_back(symbolsToAdd);
    }

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

};


#endif //GL_LINE_H
