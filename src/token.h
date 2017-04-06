//
// Created by Tobe on 4/5/17.
//

#ifndef MATH_PARSE_TOKEN_H
#define MATH_PARSE_TOKEN_H

#include <string>

using namespace std;

enum TokenType {
    LPAREN,
    RPAREN,
    CARET,
    ASTERISK,
    SLASH,
    PLUS,
    MINUS,
    NUMBER
};

bool isBinaryOperator(const TokenType &type);

class Token {
private:
    TokenType type;
    const char *text;
    unsigned long len;
public:
    Token(TokenType type, const char *text, unsigned long len) : type(type), text(text), len(len) {}

    TokenType getType() const {
        return type;
    }

    const char *getText() const {
        return text;
    }

    long getLen() {
        return len;
    }

    string toString() {
        string s;

        for (long i = 0; i < len; i++)
            s += text[i];

        return s;
    }
};

#endif //MATH_PARSE_TOKEN_H
