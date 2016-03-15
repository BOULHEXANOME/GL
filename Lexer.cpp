#include "Lexer.h"


static std::pair<string,regex> expr[] = {
    std::make_pair("VAR",regex("/var"))
};

Lexer::Lexer()
{

}

Lexer::Lexer(string nom_fic)
{
    this->nom_fic=nom_fic;
}

Lexer::~Lexer()
{
    //dtor
}

Symbol*Lexer::getSymbol()
{
    std::string s = "var";
    std::cout << regex_match(s,expr[0]) << std::endl;

}
