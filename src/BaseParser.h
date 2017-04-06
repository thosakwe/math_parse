//
// Created by Tobe on 4/5/17.
//

#ifndef MATH_PARSE_BASEPARSER_H
#define MATH_PARSE_BASEPARSER_H

#include <vector>
#include "token.h"

class BaseParser {
private:
    vector<Token *> *tokens;
    long index = -1;
protected:
    bool done(long n = 1);

    Token *consume(long n = 1);

protected:
    BaseParser(vector<Token *> *tokens) : tokens(tokens) {}
};


#endif //MATH_PARSE_BASEPARSER_H
