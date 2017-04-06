//
// Created by Tobe on 4/5/17.
//
#include <iostream>
#include <stack>
#include "ast/ast.h"
#include "Parser.h"

Parser::Parser(vector<Token *> *tokens) : BaseParser(tokens) {}

typedef struct {
    long index = 0;
} ShuntState;

Expression *expressionFromQueue(queue<Token *> &outputQueue, ShuntState *state) {
    Expression *expression = nullptr;

    for (long i = state->index; i < outputQueue.size(); i++) {
        Token *token = outputQueue.back();
        outputQueue.pop();

        if (token->getType() == NUMBER) {
            expression = new NumberExpression(token);
            state->index++;
        } else if (token->getType() == LPAREN) {
            state->index++;
            Expression *inner = expressionFromQueue(outputQueue, state);
            return new ParentheticalExpression(inner);
        } else if (isBinaryOperator(token->getType())) {
            cout << state->index << ": " << token->toString() << endl;
            state->index++;
            Expression *right = expressionFromQueue(outputQueue, state);
            if (expression == nullptr || right == nullptr) throw "Invalid binary expression.";
            return new BinaryExpression(expression, token, right);
        } else {
            throw "Invalid operator.";
        }
    }

    return expression;
}

Expression *Parser::parseExpression() {
    queue<Token *> outputQueue;
    shuntingYard(outputQueue);

    if (!outputQueue.empty()) {
        cout << "Queue: " << outputQueue.size() << endl;

        for (long i = 0; i < outputQueue.size(); i++) {
            Token *token = outputQueue.back();
            outputQueue.pop();
            cout << i << ": " << token->toString() << endl;
        }
    }

    ShuntState state;
    if (outputQueue.empty()) return nullptr;
    else return expressionFromQueue(outputQueue, &state);
}

void Parser::shuntingYard(queue<Token *> &outputQueue) {
    if (done()) return;
    else {
        stack<Token *> opStack;

        while (!done()) {
            Token *token = consume();

            if (token->getType() == NUMBER) {
                outputQueue.push(token);
            } else if (isBinaryOperator(token->getType())) {
                int precedence = static_cast<int>(token->getType());
                Token *top = opStack.empty() ? nullptr : opStack.top();

                while (top != nullptr && isBinaryOperator(top->getType()) &&
                       static_cast<int>(top->getType()) < precedence) {
                    opStack.pop();
                    outputQueue.push(top);
                }

                opStack.push(token);
            } else if (token->getType() == LPAREN)
                opStack.push(token);
            else if (token->getType() == RPAREN) {
                Token *top = nullptr;

                while (!opStack.empty() && (top = opStack.top())->getType() != LPAREN) {
                    opStack.pop();
                    outputQueue.push(top);
                }

                if (!opStack.empty() && opStack.top()->getType() == LPAREN) {
                    opStack.pop();
                } else throw "Mismatched parentheses.";
            } else {
                cout << "wtf???" << endl;
            }
        }


        while (!opStack.empty()) {
            Token *top = opStack.top();
            opStack.pop();

            if (top->getType() == LPAREN || top->getType() == RPAREN)
                throw "Mismatched parentheses.";
            else {
                outputQueue.push(top);
            }
        }
    }
}
