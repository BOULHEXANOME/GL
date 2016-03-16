#include <boost/regex.hpp>
#include <fstream>
#include <iostream>
#include "Lexer.h"

#include "Symbols/Terminaux/Semicolon.h"

//#include "ast/unknown.h"

/*
 * TODO :
 * - Vérifier et éventuellement réécrire toutes les regex
 * - Ré-Ecrire la méthode getSymbol
 * - Gérer le cas de symbole inconnu (erreur)
 *
 *
 *
 */

// TODO:
// gérer les espaces, tab et retour ligne avant et apres les symboles : esp tab retour_ligne VAR esp tab retour_ligne
static std::pair<SymbolType::Symbol, boost::regex> regexesList[] = {
    std::make_pair(SymbolType::AFF, boost::regex("\\A(:=)")),                               // AffectInstructTerminal
    std::make_pair(SymbolType::PV,  boost::regex("\\A(;)")),                                // Semicolon
    std::make_pair(SymbolType::VG,  boost::regex("\\A(,)")),                                // Coma
    std::make_pair(SymbolType::EQ,  boost::regex("\\A(=)")),                                // AffectDeclareTerminal
    std::make_pair(SymbolType::ADD, boost::regex("\\A(\\+)")),                              // PlusTerminal
    std::make_pair(SymbolType::SUB, boost::regex("\\A(-)")),                                // MinusTerminal
    std::make_pair(SymbolType::MUL, boost::regex("\\A(\\*)")),                              // MultiplyTerminal
    std::make_pair(SymbolType::DIV, boost::regex("\\A(/)")),                                // DivideTerminal
    std::make_pair(SymbolType::PO,  boost::regex("\\A(\\()")),                              //
    std::make_pair(SymbolType::PF,  boost::regex("\\A(\\))")),                              //
    std::make_pair(SymbolType::VAR, boost::regex("\\A(var)\\s+")),                          // VarTerminal
    std::make_pair(SymbolType::CST, boost::regex("\\A(const)\\s+")),                        // ConstTerminal
    std::make_pair(SymbolType::W,   boost::regex("\\A(ecrire)\\s+")),                       // WriteTerminal
    std::make_pair(SymbolType::R,   boost::regex("\\A(lire)\\s+")),                         // ReadTerminal
    std::make_pair(SymbolType::ID,  boost::regex("\\A([a-zA-Z][a-zA-Z0-9]*)")),             // IdTerminal
    std::make_pair(SymbolType::VAL, boost::regex("\\A([0-9]+)")),                           //
    std::make_pair(SymbolType::END, boost::regex("\\A\\z"))                                 // Dollar
};

static boost::regex whitespace("\\A(\\s)");

Lexer::Lexer(std::string path) {

  std::ifstream file;
  file.open(path);

  std::stringstream stream;
  stream << file.rdbuf();
  fileContentStr = stream.str();

  file.close();
    std::cout << fileContentStr << std::endl << std::endl;

  numberOfLines = 1;
  //m_char = 1;
}

Symbol* Lexer::getSymbol() {

/*
  if(currentSymbol) {
    return currentSymbol;
  } */

  trim();
  
  // Le symbole à renvoyer
  //Symbol* currentSymbol;
  
  // Parcourt la liste des Regex : pour chaque regex :
  for(const auto& reg: regexesList) {
	  
    boost::smatch stringResult;
    
    // Chercher un mot identifiable par reg.second dans fileContentStr et le met dans stringResult
    if(boost::regex_search(fileContentStr, stringResult, reg.second)) {
		
		// Si une regex a reconnu un motif

      std::shared_ptr<SymbolType::Symbol> symbol;

        std::cout << "x" << stringResult << "x" << std::endl;
      
      // On crée le symbole associé à la regex avec un switch sur le type de symbole
      // TODO : Gros switch case

        std::cout << "RegIndex : "<< reg.first << std::endl << std::endl;

        switch(reg.first) {
			
            case SymbolType::PV:	
                //std::cout << "Instanciation du pt virgule" << std::endl;
                currentSymbol = new Semicolon();
                break;
                
            default:
                break;
        }
      
      /*
      switch(reg.first) {
        case SymbolType::ID:
          symbol = std::make_shared<Symbol>(reg.first, stringResult[1]);
          break;
        case SymbolType::VAL:
          symbol = std::make_shared<Symbol>(reg.first, std::stoi(stringResult[1]));
          break;
        default:
          symbol = std::make_shared<Symbol>(reg.first);
      }


      symbol->setPosition(m_line, m_char);
      m_curSymbol = symbol;
       */

      int symbolLength = stringResult[1].length();
      //m_char += matchlen;
      fileContentStr.erase(0, symbolLength);

	// On retourne le symbole
      return currentSymbol;
    }
  }
  
  // Si aucun symbole n'a été identifié par la regex, on retourne un symbole inconnu
  
  /*
  auto unknown = std::make_shared<Unknown>(fileContentStr[0]);
  unknown->setPosition(m_line, m_char);
  fileContentStr.erase(0, 1);
  return unknown;
  */

  //std::shared_ptr<SymbolType::Symbol> error;
  return currentSymbol;

}

/*
void Lexer::shift() {
  m_curSymbol = nullptr;
}
* */

// Réduire : supprimer les espaces et compte le nombre de lignes
void Lexer::trim() {
	
  boost::smatch stringResult;
  while(boost::regex_search(fileContentStr, stringResult, whitespace)) {

    // Pour chaque whitespace trouvé
    for (int i = 0; i < stringResult.length(); ++i) {

      if (stringResult[i] == "\n") {
        numberOfLines++;
        // Utilite de m_char ?
        //m_char = 1;
      }
      else {
        //m_char++;
      }
      // Supprime les whitespace en tete du fileContentStr
      fileContentStr.erase(0, stringResult[i].length());

    }
  }
  
}

// Dans l'automate : boucle
/*
void Lexer::main() {
	
	Lexer lexer("test.lt");
	
	// Tant que on n'a pas trouvé de symbole de fin, on récupère le symbole suivant
	do {
		
		//symbol = lexer.getSymbol();
		
		

		auto curState = m_states.top();
		if(symbol->getType() == SymbolType::UNKNOWN) {
		  auto unknown = std::dynamic_pointer_cast<Unknown>(symbol);
			std::cerr << "Erreur lexicale (" << symbol->getLine() << ":";
		  std::cerr << symbol->getCol() << ") caractere ";
		  std::cerr << unknown->getChar() << std::endl;
		}
		else if(!curState->transition(*this, symbol)) {
		  std::cerr << "Erreur syntaxique. Symbole non attendu: " << *symbol << std::endl;
		  return nullptr;
		}
		m_lastSymbol = symbol;
		m_lexer.shift();


  } while(symbol->getType() != SymbolType::END);

  //return m_program;
}*/
