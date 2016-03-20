//
// Created by hdelval on 08/03/16.
//

#ifndef GL_VARIABLE_H
#define GL_VARIABLE_H


#include "StockageUnit.h"
#include <string>

class Variable : public StockageUnit
{
public:
    Variable(std::string theName/*, int theValue=0*/) : StockageUnit(theName/*, theValue*/) { }
    /***********************/
    /*** Getters/Setters ***/
    /***********************/
/*    virtual void setTheValue(int theValue)
    {
        StockageUnit::theValue = theValue;
    }*/
    virtual int execute() const;
    /***********************/
    /* End Getters/Setters */
    /***********************/
};


#endif //GL_VARIABLE_H
