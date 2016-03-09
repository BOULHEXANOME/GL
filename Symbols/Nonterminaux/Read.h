//
// Created by hdelval on 04/03/16.
//

#ifndef GL_READ_H
#define GL_READ_H


#include "../Symbol.h"
#include "Variable.h"

class ReadTerminal : public Symbol{
private:
    Variable variableToReadFromUser;
public:

    ReadTerminal(const Variable &variableToReadFromUser) : variableToReadFromUser(variableToReadFromUser) { }

    /***********************/
    /*** Getters/Setters ***/
    /***********************/
    const Variable & getVariableToReadFromUser() const
    {
        return variableToReadFromUser;
    }

    void setVariableToReadFromUser(const Variable & variableToReadFromUser)
    {
        ReadTerminal::variableToReadFromUser = variableToReadFromUser;
    }
    /***********************/
    /* End Getters/Setters */
    /***********************/
};


#endif //GL_READ_H
