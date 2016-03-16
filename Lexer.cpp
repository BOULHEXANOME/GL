#include <boost/regex.hpp>
#include <fstream>
#include <iostream>
#include "Lexer.h"

#include "Symbols/Terminaux/AffectDeclareTerminal.h"
#include "Symbols/Terminaux/AffectInstructTerminal.h"
#include "Symbols/Terminaux/Coma.h"
#include "Symbols/Terminaux/ConstTerminal.h"
#include "Symbols/Terminaux/DivideTerminal.h"
#include "Symbols/Terminaux/Dollar.h"
#include "Symbols/Terminaux/IdTerminal.h"
#include "Symbols/Terminaux/MinusTerminal.h"
#include "Symbols/Terminaux/MultiplyTerminal.h"
#include "Symbols/Terminaux/ParenthesisTerminal.h"
#include "Symbols/Terminaux/PlusTerminal.h"
#include "Symbols/Terminaux/ReadTerminal.h"
#include "Symbols/Terminaux/Semicolon.h"
#include "Symbols/Terminaux/SyntaxError.h"
#include "Symbols/Terminaux/VarTerminal.h"
#include "Symbols/Terminaux/WriteTerminal.h"
#include "Symbols/Terminaux/AffectDeclareTerminal.h"
#include "Symbols/Terminaux/AffectInstructTerminal.h"
#include "Symbols/Terminaux/Coma.h"
#include "Symbols/Terminaux/ConstTerminal.h"
#include "Symbols/Terminaux/DivideTerminal.h"
#include "Symbols/Terminaux/Dollar.h"
#include "Symbols/Terminaux/IdTerminal.h"
#include "Symbols/Terminaux/MinusTerminal.h"
#include "Symbols/Terminaux/MultiplyTerminal.h"
#include "Symbols/Terminaux/ParenthesisTerminal.h"
#include "Symbols/Terminaux/PlusTerminal.h"
#include "Symbols/Terminaux/ReadTerminal.h"
#include "Symbols/Terminaux/Semicolon.h"
#include "Symbols/Terminaux/SyntaxError.h"
#include "Symbols/Terminaux/VarTerminal.h"
#include "Symbols/Terminaux/WriteTerminal.h"

#include "Symbols/Nonterminaux/Number.h"

// TODO:
// gérer les espaces, tab et retour ligne avant et apres les symboles : esp tab retour_ligne VAR esp tab retour_ligne
static std::pair<int, boost::regex> regexesList[] = {
    std::make_pair(AFFECTINSTRUCT, boost::regex("\\A(:=)")),                               // AffectInstructTerminal
    std::make_pair(SEMICOLON,  boost::regex("\\A(;)")),                                    // Semicolon
    std::make_pair(COMMA,  boost::regex("\\A(,)")),                                        // Coma
    std::make_pair(AFFECTDECLARE,  boost::regex("\\A(=)")),                                // AffectDeclareTerminal
    std::make_pair(PLUS, boost::regex("\\A(\\+)")),                              		   // PlusTerminal
    std::make_pair(MINUS, boost::regex("\\A(-)")),                                         // MinusTerminal
    std::make_pair(MULTIPLY, boost::regex("\\A(\\*)")),                                    // MultiplyTerminal
    std::make_pair(DIVIDE, boost::regex("\\A(/)")),                                        // DivideTerminal
    std::make_pair(OPENPARENTHESIS,  boost::regex("\\A(\\()")),                            // OpenP
    std::make_pair(CLOSEPARENTHESIS,  boost::regex("\\A(\\))")),                           // 
    std::make_pair(VAR, boost::regex("\\A(var)\\s+")),                                     // VarTerminal
    std::make_pair(CONST, boost::regex("\\A(const)\\s+")),                                 // ConstTerminal
    std::make_pair(WRITE,   boost::regex("\\A(ecrire)\\s+")),                              // WriteTerminal
    std::make_pair(READ,   boost::regex("\\A(lire)\\s+")),                                 // ReadTerminal
    std::make_pair(ID,  boost::regex("\\A([a-zA-Z][a-zA-Z0-9]*)")),                        // IdTerminal
    std::make_pair(VAL, boost::regex("\\A([0-9]+)")),                                      // Valeur
    std::make_pair(DOLLAR, boost::regex("\\A\\z"))                                         // Dollar
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

  currentLine = 1;
  currentPosition = 1;
}

Symbol* Lexer::getSymbol() {


  trim();
  
  // Le symbole à renvoyer
  //Symbol* currentSymbol;
  
  // Parcourt la liste des Regex : pour chaque regex :
  for(const auto& reg: regexesList) {
	  
    boost::smatch stringResult;
    
    // Chercher un mot identifiable par reg.second dans fileContentStr et le met dans stringResult
    if(boost::regex_search(fileContentStr, stringResult, reg.second)) {
		
		// Si une regex a reconnu un motif
      
      // On crée le symbole associé à la regex avec un switch sur le type de symbole
      // TODO : Gros switch case

        std::cout << "RegIndex : "<< reg.first << std::endl << std::endl;

        switch(reg.first) {
			
			case PLUS:
				currentSymbol = new PlusTerminal();
				break;
			case MINUS:
				currentSymbol = new MinusTerminal();
				break;
			case MULTIPLY:
				currentSymbol = new MultiplyTerminal();
				break;
			case DIVIDE:
				currentSymbol = new DivideTerminal();
				break;
			case WRITE:
				currentSymbol = new WriteTerminal();
				break;
			case READ:
				currentSymbol = new ReadTerminal();
				break;
			case AFFECTDECLARE:
				currentSymbol =  new AffectDeclareTerminal();
				break;
			case AFFECTINSTRUCT:
				currentSymbol = new AffectInstructTerminal();
				break;
			case OPENPARENTHESIS:
				currentSymbol = new ParenthesisTerminal(opening);
				break;
			case CLOSEPARENTHESIS:
				currentSymbol = new ParenthesisTerminal(closing);
				break;
			case VAR:
				currentSymbol = new VarTerminal();
				break;
			case VAL:
				currentSymbol = new Number(stoi(stringResult[1]));
				break;
			case DOLLAR:
				currentSymbol = new Dollar();
				break;
			case CONST:
				currentSymbol = new ConstTerminal();
				break;
			case COMMA:
				currentSymbol = new Coma();
				break;	                                                                         
            case SEMICOLON:	
                currentSymbol = new Semicolon();
                break;
            case ID:
				currentSymbol = new IdTerminal(stringResult[1]);
				break;
			case ERROR:
				currentSymbol = new SyntaxError(stringResult[1]);
				break;
            default:
				currentSymbol = new SyntaxError(stringResult[1]);
                break;
        }
      

      int symbolLength = stringResult[1].length();
      
      currentPosition += symbolLength;
      
      std::cout << "Pos dans la ligne : " << currentPosition << std::endl;
      
      fileContentStr.erase(0, symbolLength);

	// On retourne le symbole
      return currentSymbol;
    }
  }
  
  // Si aucun symbole n'a été identifié par la regex, on retourne un symbole inconnu
 
  return currentSymbol;

}

// Réduire : supprimer les espaces et compte le nombre de lignes
void Lexer::trim() {
	
  boost::smatch stringResult;
  while(boost::regex_search(fileContentStr, stringResult, whitespace)) {

    // Pour chaque whitespace trouvé
    for (int i = 0; i < stringResult.length(); ++i) {
		
	// Nouvelle ligne
      if (stringResult[i] == "\n") {
        currentLine++;
        std::cout << "Ligne actuelle : " << currentLine << std::endl;
        // Reset le curseur au début de la ligne
        currentPosition = 1;
      }
      else {
        currentPosition++;
      }
      // Supprime les whitespace en tete du fileContentStr
      fileContentStr.erase(0, stringResult[i].length());

    }
  }
  
}
