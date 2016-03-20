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
//    int theValue;

public:
    StockageUnit(const std::string &theName/*, int theValue*/) : theName(theName)/*, theValue(theValue)*/ { }

    /***********************/
    /*** Getters/Setters ***/
    /***********************/
    std::string getTheName() const
    {
        return theName;
    }
    void setTheName(std::string theName){
        this->theName = theName;
    }

/*    int getTheValue() const
    {
        return theValue;
    }
    virtual void setTheValue(int theValue) = 0;*/
    /***********************/
    /* End Getters/Setters */
    /***********************/

    /***********************/
    /******** Methods ******/
    /***********************/
    virtual std::string print() const;
    virtual int execute() const;
    /***********************/
    /****** End Methods ****/
    /***********************/
};


#endif //GL_STOCKAGEUNIT_H
