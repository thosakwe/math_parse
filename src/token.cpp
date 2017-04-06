//
// Created by Tobe on 4/5/17.
//
#include "token.h"

bool isBinaryOperator(const TokenType &type) {
    return type == CARET || type == ASTERISK || type == SLASH || type == PLUS || type == MINUS;
}
