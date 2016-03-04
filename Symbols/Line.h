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
    Line(const std::list<Symbol> &symbols, Type typeOfLine) : symbols(symbols), typeOfLine(typeOfLine) { }

    Line() : {}{}


    const std::list<Symbol> &Line::getSymbols() const
    {
        return symbols;
    }

    void Line::setSymbols(const std::list<Symbol> &symbols)
    {
        this->symbols = symbols;
    }

    void Line::addSymbol(Symbol symbolsToAdd)
    {
        this->symbols.push_back(symbolsToAdd);
    }

    const Type &getTypeOfLine() const {
        return typeOfLine;
    }

    void setTypeOfLine(const Type &typeOfLine) {
        Line::typeOfLine = typeOfLine;
    }
};


#endif //GL_LINE_H
