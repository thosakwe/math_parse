//
// Created by Tobe on 4/5/17.
//

#ifndef MATH_PARSE_PARSER_H
#define MATH_PARSE_PARSER_H

#include <queue>
#include "BaseParser.h"
#include "ast/Expression.h"

class Parser : public BaseParser {
public:
    Parser(vector<Token *> *tokens);

    Expression *parseExpression();

    void shuntingYard(queue<Token *> &outputQueue);
};


#endif //MATH_PARSE_PARSER_H
