//
// Created by Tobe on 4/5/17.
//

#include "NumberExpression.h"

double NumberExpression::solve() {
    return atof(NUMBER->toString().c_str());
}

NumberExpression::NumberExpression(Token *NUMBER) : NUMBER(NUMBER) {}
