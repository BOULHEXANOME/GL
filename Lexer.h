#ifndef LEXER_H0
#define LEXER_H

#include <string>
#include <vector>
#include <memory>
#include "symbolTypes.h"
#include "Symbols/Symbol.h"
//#include "ast/symbol.h"


/*namespace SymbolType
{
    enum Symbol
    {
		P, DL, IL, D, V, C, I, E, OP_A, OP_M,
        AFF,PV,VG,EQ,ADD,SUB,MUL,DIV,PO,PF,VAR,CST,W,R,I_R,I_W,ID,VAL,E_VAL,E_CNUM,E_PAR,END,UNKNOWN
    };
}*/


class Lexer {
	
  public:
    Lexer(std::string path);
    Symbol* getSymbol();
    std::vector<std::string> getStringVector();
    
    //void shift();
  
  private:
    int currentLine;
    int currentPosition;
    std::string fileContentStr;
    Symbol* currentSymbol;
    void trim();

  

};

#endif
