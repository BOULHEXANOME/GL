//
// Created by hdelval on 08/03/16.
//

#ifndef GL_VARTERMINAL_H
#define GL_VARTERMINAL_H


#include "../Symbol.h"
#include <string>

class VarTerminal : public Symbol{
private:
    std::string theName;
public:

    VarTerminal(const std::string & theName) : theName(theName) { }

    /***********************/
    /*** Getters/Setters ***/
    /***********************/
    const std::string & getTheName() const
    {
        return theName;
    }

    void setTheName(const std::string & theName)
    {
        VarTerminal::theName = theName;
    }
    /***********************/
    /* End Getters/Setters */
    /***********************/
};


#endif //GL_VARTERMINAL_H
