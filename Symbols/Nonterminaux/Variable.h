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
    Variable(std::string theName) : StockageUnit(theName) { }
    /***********************/
    /*** Getters/Setters ***/
    /***********************/
    void setTheName(std::string theName)
    {
        StockageUnit::theName = theName;
    }
    /***********************/
    /* End Getters/Setters */
    /***********************/
};


#endif //GL_VARIABLE_H
