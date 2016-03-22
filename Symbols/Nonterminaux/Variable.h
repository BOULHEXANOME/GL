//
// Created by hdelval on 08/03/16.
//

#ifndef GL_VARIABLE_H
#define GL_VARIABLE_H


#include <string>
#include "../Symbol.h"
#include "Expression.h"

class Variable : public Expression
{
private:
    std::string theName;
public:
    Variable(std::string theName) : theName(theName) { }
    virtual int execute() const;

    const std::string &getTheName() const {
        return theName;
    }

    void setTheName(const std::string &theName) {
        Variable::theName = theName;
    }
};


#endif //GL_VARIABLE_H
