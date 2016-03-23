cmake_minimum_required(VERSION 2.8)
project(lut)
 
find_package(Boost 1.40.0 COMPONENTS regex REQUIRED) 

include_directories(${Boost_INCLUDE_DIRS}) 

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES 
Lexer.cpp Lexer.h 
main.cpp 
Symbols/Line.cpp Symbols/Line.h 
Symbols/Nonterminaux/Read.cpp Symbols/Nonterminaux/Read.h 
Symbols/Symbol.cpp Symbols/Symbol.h 
Automaton.cpp Automaton.h 
Symbols/Nonterminaux/Write.cpp Symbols/Nonterminaux/Write.h 
Symbols/Terminaux/AffectDeclareTerminal.cpp Symbols/Terminaux/AffectDeclareTerminal.h 
Symbols/Terminaux/AffectInstructTerminal.cpp Symbols/Terminaux/AffectInstructTerminal.h 
Symbols/Terminaux/VarTerminal.cpp Symbols/Terminaux/VarTerminal.h 
Symbols/Terminaux/ConstTerminal.cpp Symbols/Terminaux/ConstTerminal.h 
Symbols/Nonterminaux/Expression.cpp Symbols/Nonterminaux/Expression.h 
Symbols/Nonterminaux/Variable.cpp Symbols/Nonterminaux/Variable.h 
Symbols/Nonterminaux/Number.cpp Symbols/Nonterminaux/Number.h 
Symbols/Nonterminaux/Parenthesis.cpp Symbols/Nonterminaux/Parenthesis.h 
Symbols/Nonterminaux/BinaryExpression.cpp Symbols/Nonterminaux/BinaryExpression.h 
Symbols/Nonterminaux/MinusExpression.cpp Symbols/Nonterminaux/MinusExpression.h 
Symbols/Nonterminaux/PlusExpression.cpp Symbols/Nonterminaux/PlusExpression.h 
Symbols/Nonterminaux/DivideExpression.cpp Symbols/Nonterminaux/DivideExpression.h 
Symbols/Nonterminaux/MultiplyExpression.cpp Symbols/Nonterminaux/MultiplyExpression.h 
Symbols/Terminaux/PlusTerminal.cpp Symbols/Terminaux/PlusTerminal.h 
Symbols/Terminaux/MinusTerminal.cpp Symbols/Terminaux/MinusTerminal.h 
Symbols/Terminaux/DivideTerminal.cpp Symbols/Terminaux/DivideTerminal.h 
Symbols/Terminaux/MultiplyTerminal.cpp Symbols/Terminaux/MultiplyTerminal.h 
Symbols/Terminaux/ParenthesisTerminal.cpp Symbols/Terminaux/ParenthesisTerminal.h 
Symbols/Terminaux/ReadTerminal.cpp Symbols/Terminaux/ReadTerminal.h 
Symbols/Terminaux/WriteTerminal.cpp Symbols/Terminaux/WriteTerminal.h
Symbols/Nonterminaux/Constant.cpp Symbols/Nonterminaux/Constant.h exceptions.h 
Symbols/Nonterminaux/VarDeclare.cpp Symbols/Nonterminaux/VarDeclare.h
Symbols/Nonterminaux/AffectInstruct.cpp Symbols/Nonterminaux/AffectInstruct.h 
Symbols/Nonterminaux/AffectConst.cpp Symbols/Nonterminaux/AffectConst.h 
Symbols/Terminaux/IdTerminal.cpp Symbols/Terminaux/IdTerminal.h 
Symbols/Terminaux/Semicolon.cpp Symbols/Terminaux/Semicolon.h 
Symbols/Terminaux/Dollar.cpp Symbols/Terminaux/Dollar.h 
Symbols/Terminaux/Comma.cpp Symbols/Terminaux/Comma.h 
Symbols/Terminaux/SyntaxError.cpp Symbols/Terminaux/SyntaxError.h 
Symbols/Nonterminaux/OpA.cpp Symbols/Nonterminaux/OpA.h 
Symbols/Nonterminaux/OpM.cpp Symbols/Nonterminaux/OpM.h 
states/DefaultState.cpp states/DefaultState.h 
states/State.h 
states/E0.cpp states/E0.h 
states/E1.cpp states/E1.h 
states/E2.cpp states/E2.h 
states/E15.h states/E15.cpp 
states/E3.cpp states/E3.h 
states/E10.cpp states/E10.h 
states/E4.cpp states/E4.h 
states/E40.cpp states/E40.h 
states/E9.cpp states/E9.h 
states/E35.cpp states/E35.h 
states/E31.cpp states/E31.h 
states/E29.cpp states/E29.h 
states/E18.cpp states/E18.h 
states/E5.cpp states/E5.h 
states/E43.cpp states/E43.h 
states/E11.cpp states/E11.h 
states/E14.cpp states/E14.h 
states/E23.cpp states/E23.h 
states/E34.cpp states/E34.h 
states/E41.cpp states/E41.h 
states/E42.cpp states/E42.h 
states/E17.cpp states/E17.h 
states/E20.cpp states/E20.h 
states/E38.cpp states/E38.h 
states/E39.cpp states/E39.h
states/E21.cpp states/E21.h 
states/E27.cpp states/E27.h 
states/E36.h states/E36.cpp 
states/E6.h states/E6.cpp
states/E8.h states/E8.cpp
states/E7.h states/E7.cpp
states/E16.h states/E16.cpp
states/E12.h states/E12.cpp
states/E24.h states/E24.cpp
states/E25.h states/E25.cpp
states/E37.h states/E37.cpp
states/E13.h states/E13.cpp
)

add_executable(lut ${SOURCE_FILES})

target_link_libraries(lut ${Boost_LIBRARIES})
