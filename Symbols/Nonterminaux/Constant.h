//
// Created by hdelval on 08/03/16.
//

#ifndef GL_CONSTANT_H
#define GL_CONSTANT_H


#include "../../exceptions.h"
#include "../Symbol.h"
#include "Expression.h"

class Constant : public Expression
{
private:
    std::string theName;
public:
    Constant(std::string theName) : theName(theName) { }

    /***********************/
    /*** Getters/Setters ***/
    /***********************/
    const std::string &getTheName() const {
        return theName;
    }

    void setTheName(const std::string &theName) {
        Constant::theName = theName;
    }
    /***********************/
    /* End Getters/Setters */
    /***********************/

    virtual int execute() const;
};


#endif //GL_CONSTANT_H
