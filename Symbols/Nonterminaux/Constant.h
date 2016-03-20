//
// Created by hdelval on 08/03/16.
//

#ifndef GL_CONSTANT_H
#define GL_CONSTANT_H


#include "StockageUnit.h"
#include "../../exceptions.h"

class Constant : public StockageUnit
{
public:
    Constant(std::string theName/*, int theValue*/) : StockageUnit(theName/*, theValue*/) { }
    /***********************/
    /*** Getters/Setters ***/
    /***********************/
    /*virtual void setTheValue(int theValue)
    {
        throw TRYING_TO_MODIFY_CONST;
    }*/
    virtual int execute() const;
    /***********************/
    /* End Getters/Setters */
    /***********************/
};


#endif //GL_CONSTANT_H
