//
// Created by hdelval on 09/03/16.
//

#ifndef GL_SYNTAXERROR_H
#define GL_SYNTAXERROR_H


#include "../Symbol.h"
#include <string>

class SyntaxError : public Symbol{
private:
    std::string theWrongSymbol;
private:

public:
    SyntaxError(const std::string &theWrongSymbol) : theWrongSymbol(theWrongSymbol) { }
    SyntaxError() { }


    /***********************/
    /*** Getters/Setters ***/
    /***********************/
    const std::string & getTheWrongSymbol() const
    {
        return theWrongSymbol;
    }

    void setTheWrongSymbol(const std::string & theWrongSymbol)
    {
        SyntaxError::theWrongSymbol = theWrongSymbol;
    }
    /***********************/
    /* End Getters/Setters */
    /***********************/
};


#endif //GL_SYNTAXERROR_H
