//
// Created by hdelval on 08/03/16.
//

#ifndef GL_NUMBER_H
#define GL_NUMBER_H


#include "Expression.h"

class Number : public Expression{
private:
    int theValue;

public:
    Number(int theValue) : theValue(theValue) { }

    /***********************/
    /*** Getters/Setters ***/
    /***********************/
    int getTheValue() const
    {
        return theValue;
    }

    void setTheValue(int theValue)
    {
        Number::theValue = theValue;
    }
    /***********************/
    /* End Getters/Setters */
    /***********************/

};


#endif //GL_NUMBER_H