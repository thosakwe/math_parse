//
// Created by Tobe on 4/5/17.
//

#ifndef MATH_PARSE_NUMBEREXPRESSION_H
#define MATH_PARSE_NUMBEREXPRESSION_H
#include <cstdlib>
#include "../token.h"
#include "Expression.h"
using namespace std;

class NumberExpression : public Expression {
private:
    Token *NUMBER;
public:
    NumberExpression(Token *NUMBER);

public:
    double solve() override;
};


#endif //MATH_PARSE_NUMBEREXPRESSION_H
