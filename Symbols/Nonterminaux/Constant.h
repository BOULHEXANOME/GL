//
// Created by hdelval on 08/03/16.
//

#ifndef GL_CONSTANT_H
#define GL_CONSTANT_H


#include "StockageUnit.h"
#include "../../exceptions.h"

class Constant : public StockageUnit{
public:
    Constant(std::string theName) : StockageUnit(theName) { }
    /***********************/
    /*** Getters/Setters ***/
    /***********************/
    void setTheName(std::string theName)
    {
        throw TRYING_TO_MODIFY_CONST;
    }
    /***********************/
    /* End Getters/Setters */
    /***********************/
};


#endif //GL_CONSTANT_H
