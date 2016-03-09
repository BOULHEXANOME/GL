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
    std::list<Symbol> symbols;
    Type typeOfLine;

public:

    /***********************/
    /***** Contructors *****/
    /***********************/
    Line(Type typeOfLine) : typeOfLine(typeOfLine) { }
    Line(const std::list<Symbol> &symbols, Type typeOfLine) : symbols(symbols), typeOfLine(typeOfLine) { }
    Line() { }
    /***********************/
    /*** End Contructors ***/
    /***********************/

    /***********************/
    /*** Getters/Setters ***/
    /***********************/
    const std::list<Symbol> & getSymbols() const
    {
        return symbols;
    }

    void setSymbols(const std::list<Symbol> & symbols)
    {
        this->symbols = symbols;
    }

    void addSymbol(Symbol & symbolsToAdd)
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
};


#endif //GL_LINE_H
