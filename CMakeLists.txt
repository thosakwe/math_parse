cmake_minimum_required(VERSION 3.7)
project(math_parse)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES src/main.cpp src/token.h src/scan.h src/scan.cpp src/BaseParser.cpp src/BaseParser.h src/Parser.cpp src/Parser.h src/ast/Expression.h src/ast/NumberExpression.cpp src/ast/NumberExpression.h src/ast/ast.h src/ast/ParentheticalExpression.cpp src/ast/ParentheticalExpression.h src/ast/BinaryExpression.cpp src/ast/BinaryExpression.h src/token.cpp)
add_executable(math_parse ${SOURCE_FILES})