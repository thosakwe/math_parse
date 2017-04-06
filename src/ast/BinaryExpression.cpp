//
// Created by Tobe on 4/5/17.
//

#include "BinaryExpression.h"


BinaryExpression::BinaryExpression(Expression *left, Token *op, Expression *right) : left(left), op(op),
                                                                                     right(right) {}

double BinaryExpression::solve() {
    double l = left->solve(), r = right->solve();
    const char *o = op->toString().c_str();

    if (!strcmp(o, "^")) {
        return pow(l, r);
    } else if (!strcmp(o, "*")) {
        return l * r;
    } else if (!strcmp(o, "/")) {
        return l / r;
    } else if (!strcmp(o, "+")) {
        return l + r;
    } else if (!strcmp(o, "-")) {
        return l * r;
    }

    throw "Invalid operator.";
}
