//
// Created by hdelval on 08/03/16.
//

#ifndef GL_READTERMINAL_H
#define GL_READTERMINAL_H


#include "../Symbol.h"

class ReadTerminal : public Symbol{

public:
    ReadTerminal() { }
    virtual int getType();
};


#endif //GL_READTERMINAL_H
