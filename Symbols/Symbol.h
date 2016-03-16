//
// Created by hdelval on 04/03/16.
//

#ifndef GL_SYMBOL_H
#define GL_SYMBOL_H

#include "../symbolTypes.h"
#include <iostream>
#include <list>

class Symbol
{
protected:
    int columnWhereSymbolOccurs = -1;
    int lineWhereSymbolOccurs = -1;
    int symbolType;
    std::list <Symbol*> symbols;

public:
    //virtual int getType() const;
    virtual std::string print() const;

	//Constructors
	Symbol();
	Symbol(Symbol *s);
	Symbol(Symbol *s1, Symbol *s2);
	Symbol(Symbol *s1, Symbol *s2, Symbol *s3);
	Symbol(Symbol *s1, Symbol *s2, Symbol *s3, Symbol *s4);
	Symbol(Symbol *s1, Symbol *s2, Symbol *s3, Symbol *s4, Symbol *s5);
    /***********************/
    /*** Getters/Setters ***/
    /***********************/
    
    void setType(int type);
    int getType();
    
    int getColumnWhereSymbolOccurs() const
    {
        return columnWhereSymbolOccurs;
    }

    void setColumnWhereSymbolOccurs(int columnWhereSymbolOccurs)
    {
        Symbol::columnWhereSymbolOccurs = columnWhereSymbolOccurs;
    }

    int getLineWhereSymbolOccurs() const
    {
        return lineWhereSymbolOccurs;
    }

    void setLineWhereSymbolOccurs(int lineWhereSymbolOccurs)
    {
        Symbol::lineWhereSymbolOccurs = lineWhereSymbolOccurs;
    }

    /***********************/
    /* End Getters/Setters */
    /***********************/

    /************************/
    /** Override operators **/
    /************************/
    friend std::ostream & operator<<(std::ostream& os, const Symbol & s);
    /************************/
    /*End Override operators /
    /************************/
};


#endif //GL_SYMBOL_H
