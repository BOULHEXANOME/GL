//
// Created by hdelval on 08/03/16.
//

#ifndef GL_AFFECTVARDECLARE_H
#define GL_AFFECTVARDECLARE_H


#include "../Symbol.h"
#include "Number.h"
#include "Variable.h"

class VarDeclare: public Symbol
{
private:
    Variable *variableToDeclare;
public:

    VarDeclare(Variable * variableToDeclare) : variableToDeclare(variableToDeclare) { }

    /***********************/
    /*** Getters/Setters ***/
    /***********************/
    /***********************/
    /* End Getters/Setters */
    /***********************/

    /***********************/
    /******** Methods ******/
    /***********************/
    virtual std::string print() const;
    virtual int execute() const;
    virtual bool analyse();
    virtual bool optimize();
    /***********************/
    /****** End Methods ****/
    /***********************/
};

#endif //GL_AFFECTVARDECLARE_H
