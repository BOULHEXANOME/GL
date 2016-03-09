//
// Created by hdelval on 08/03/16.
//

#ifndef GL_WRITE_H
#define GL_WRITE_H


#include "../Symbol.h"
#include "Expression.h"

class Write : public Symbol{
private:
    Expression toWrite;
public:

    Write(const Expression & toWrite) : toWrite(toWrite) { }

    /***********************/
    /*** Getters/Setters ***/
    /***********************/
    const Expression & getToWrite() const
    {
        return toWrite;
    }

    void setToWrite(const Expression & toWrite)
    {
        Write::toWrite = toWrite;
    }
    /***********************/
    /* End Getters/Setters */
    /***********************/
};


#endif //GL_WRITE_H
