//
// Created by hdelval on 04/03/16.
//

#ifndef GL_SYMBOL_H
#define GL_SYMBOL_H

#include "../symbolTypes.h"

class Symbol {

public:
    virtual int getType()
    {
        return NON_TERMINAL;
    }
};


#endif //GL_SYMBOL_H
