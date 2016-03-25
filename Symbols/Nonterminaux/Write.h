//
// Created by hdelval on 08/03/16.
//

#ifndef GL_WRITE_H
#define GL_WRITE_H


#include "../Symbol.h"
#include "Expression.h"

class Write : public Symbol{
private:
    Expression * toWrite;
public:

    Write(Expression * toWrite) : toWrite(toWrite) { }

    /***********************/
    /*** Getters/Setters ***/
    /***********************/
    Expression * getToWrite() const
    {
        return toWrite;
    }

    void setToWrite(Expression * toWrite)
    {
        Write::toWrite = toWrite;
    }
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


#endif //GL_WRITE_H
