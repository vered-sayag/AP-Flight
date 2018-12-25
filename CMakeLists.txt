cmake_minimum_required(VERSION 3.13)
project(AP4)

set(CMAKE_CXX_STANDARD 14)

add_executable(AP4 main.cpp Command.h connectCommand.cpp connectCommand.h DataBase.h equalBindCommand.cpp equalBindCommand.h equalCommand.cpp equalCommand.h Expression.h IfCommand.cpp IfCommand.h lexer.cpp lexer.h ODSCommand.cpp ODSCommand.h parser.cpp parser.h Shunting_Yard.cpp Shunting_Yard.h TCPThread.cpp TCPThread.h WhileCommand.cpp WhileCommand.h DataBase.cpp VarCommand.cpp VarCommand.h sleepCommand.cpp sleepCommand.h printCommand.cpp printCommand.h conditionParser.cpp conditionParser.h BlockCommand.cpp BlockCommand.h Condition.cpp Condition.h exitCommand.cpp exitCommand.h xmlLexer.cpp xmlLexer.h)

SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pthread")