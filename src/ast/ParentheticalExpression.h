//
// Created by Tobe on 4/5/17.
//

#ifndef MATH_PARSE_PARENTHETICALEXPRESSION_H
#define MATH_PARSE_PARENTHETICALEXPRESSION_H
#include "Expression.h"

class ParentheticalExpression: public  Expression {
private:
    Expression* inner;
public:
    double solve() override;

public:
    ParentheticalExpression(Expression *inner);
};


#endif //MATH_PARSE_PARENTHETICALEXPRESSION_H
