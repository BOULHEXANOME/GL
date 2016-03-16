//
// Created by hdelval on 08/03/16.
//

#ifndef GL_STOCKAGEUNIT_H
#define GL_STOCKAGEUNIT_H


#include "Expression.h"
#include <string>

class StockageUnit : public Expression
{
protected:
    std::string theName;

    StockageUnit(const std::string &theName) : theName(theName) { }

public:
    /***********************/
    /*** Getters/Setters ***/
    /***********************/
    std::string getTheName() const
    {
        return theName;
    }
    virtual void setTheName(std::string theName) = 0;
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


#endif //GL_STOCKAGEUNIT_H
