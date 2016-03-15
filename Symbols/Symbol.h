//
// Created by hdelval on 04/03/16.
//

#ifndef GL_SYMBOL_H
#define GL_SYMBOL_H

#include "../symbolTypes.h"
#include <iostream>

class Symbol {

public:
    virtual int getType() const;
    virtual std::string print() const;

    /************************/
    /** Override operators **/
    /************************/
    friend std::ostream & operator<<(std::ostream& os, const Symbol & s);
    /************************/
    /*End Override operators /
    /************************/
};


#endif //GL_SYMBOL_H
