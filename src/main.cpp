#include <iostream>
#include "Parser.h"
#include "scan.h"

using namespace std;

int main() {
    try {
        string line;

        while (true) {
            cout << "Enter an equation: ";
            cin >> line;
            vector<Token *> tokens;
            scan(tokens, line.c_str(), line.length());
            Parser *parser = new Parser(&tokens);
            Expression *expression = parser->parseExpression();
            delete parser;

            if (expression == nullptr) {
                cerr << "Invalid expression entered." << endl;
                return 1;
            } else {
                double result = expression->solve();
                cout << "Result: " << result << endl;
            }
        }
    } catch(const char* err) {
        cerr << err << endl;
        return 1;
    }
}