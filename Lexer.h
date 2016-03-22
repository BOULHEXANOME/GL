#ifndef LEXER_H0
#define LEXER_H

#include <string>
#include <vector>
#include <memory>
#include "symbolTypes.h"
#include "Symbols/Symbol.h"

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
