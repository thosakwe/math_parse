//
// Created by Tobe on 4/5/17.
//
#include <iostream>
#include "BaseParser.h"

bool BaseParser::done(long n) {
    return (index == -1 && tokens->size() == 0) || (tokens->size() - index <= n);
}

Token *BaseParser::consume(long n) {
    if (done(n))
        return nullptr;
    else if (index == -1) {
        index++;
        return tokens->at(0);
    } else {
        unsigned long i = (unsigned long) ++index;
        return tokens->at(i);
    }
}
