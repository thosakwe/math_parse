//
// Created by Tobe on 4/5/17.
//

#include "ParentheticalExpression.h"

ParentheticalExpression::ParentheticalExpression(Expression *inner) : inner(inner) {}

double ParentheticalExpression::solve() {
    return inner->solve();
}
