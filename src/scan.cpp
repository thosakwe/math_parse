#include "scan.h"

void scan(vector<Token *> &tokens, const char *str, const long len) {
    for (long i = 0; i < len; i++) {
        vector<Token *> potential;
        char ch = str[i];

        if (ch == '(')
            potential.push_back(new Token(LPAREN, str + i, 1));
        else if (ch == ')')
            potential.push_back(new Token(RPAREN, str + i, 1));
        else if (ch == '^')
            potential.push_back(new Token(CARET, str + i, 1));
        else if (ch == '*')
            potential.push_back(new Token(ASTERISK, str + i, 1));
        else if (ch == '/')
            potential.push_back(new Token(SLASH, str + i, 1));
        else if (ch == '+')
            potential.push_back(new Token(PLUS, str + i, 1));
        else if (ch == '-')
            potential.push_back(new Token(MINUS, str + i, 1));
        else if (isnumber(ch)) {
            string s;

            for (long j = i; j < len; j++) {
                char peek = str[j];

                if (!isnumber(peek)) break;
                else {
                    s += peek;
                }
            }

            potential.push_back(new Token(NUMBER, s.c_str(), s.length()));
        }

        if (potential.size() > 0) {
            Token *longest = nullptr;
            long longestLen = 0;

            for (unsigned long j = 0; j < potential.size(); j++) {
                Token *token = potential.at(j);

                if (token->getLen() > longestLen) {
                    longest = token;
                    longestLen = token->getLen();
                }
            }

            if (longest != nullptr) {
                tokens.push_back(longest);

                i += longestLen - 1;
            }
        }
    }
}