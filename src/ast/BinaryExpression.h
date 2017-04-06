//
// Created by Tobe on 4/5/17.
//

#ifndef MATH_PARSE_BINARYEXPRESSION_H
#define MATH_PARSE_BINARYEXPRESSION_H
#include <cstring>
#include <math.h>
#include "../token.h"
#include "Expression.h"
using namespace std;

class BinaryExpression : public Expression {
private:
    Expression *left, *right;
    Token *op;
public:
    BinaryExpression(Expression*, Token*, Expression*);

    double solve() override;
};


#endif //MATH_PARSE_BINARYEXPRESSION_H
