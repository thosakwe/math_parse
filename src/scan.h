//
// Created by Tobe on 4/5/17.
//

#ifndef MATH_PARSE_SCAN_H
#define MATH_PARSE_SCAN_H
#include <string>
#include <vector>
#include "token.h"
using namespace std;

void scan(vector<Token*>& tokens, const char *str, const long len);

#endif //MATH_PARSE_SCAN_H
