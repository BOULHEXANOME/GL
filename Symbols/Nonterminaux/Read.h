//
// Created by hdelval on 04/03/16.
//

#ifndef GL_READ_H
#define GL_READ_H


#include "../Symbol.h"
#include "Variable.h"

class ReadTerminal : public Symbol{
private:
    Variable * variableToReadFromUser;
public:

    ReadTerminal(Variable *variableToReadFromUser) : variableToReadFromUser(variableToReadFromUser) { }

    /***********************/
    /*** Getters/Setters ***/
    /***********************/
    Variable * getVariableToReadFromUser() const
    {
        return variableToReadFromUser;
    }

    void setVariableToReadFromUser(Variable * variableToReadFromUser)
    {
        ReadTerminal::variableToReadFromUser = variableToReadFromUser;
    }
    /***********************/
    /* End Getters/Setters */
    /***********************/

    /***********************/
    /******** Methods ******/
    /***********************/
    virtual std::string print() const;
    /***********************/
    /****** End Methods ****/
    /***********************/
};


#endif //GL_READ_H
