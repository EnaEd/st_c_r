#ifndef STACK_TASKS_H
#define STACK_TASKS_H

#include <iostream>
#include <string>

template <typename T>
class LinkedStack {
    struct Node {
        T data;
        Node* next;
        Node(T val, Node* n = nullptr) : data(val), next(n) {}
    };
    Node* top;
public:
    LinkedStack() : top(nullptr) {}
    ~LinkedStack() {
        while (!IsEmpty()) Pop();
    }

    void Push(T val) {
        top = new Node(val, top);
    }

    T Pop() {
        if (IsEmpty()) return T();
        Node* temp = top;
        T data = temp->data;
        top = top->next;
        delete temp;
        return data;
    }

    T Peek() const {
        if (IsEmpty()) return T();
        return top->data;
    }

    bool IsEmpty() const {
        return top == nullptr;
    }
};

class BracketChecker {
public:
    static void Run() {
        std::string input;
        std::cout << "Enter string (ending with ;): ";
        std::getline(std::cin, input);
        
        // Remove everything after ';' if present
        size_t endPos = input.find(';');
        if (endPos != std::string::npos) {
            input = input.substr(0, endPos + 1);
        }

        LinkedStack<char> stack;
        bool error = false;
        size_t errorPos = 0;

        for (size_t i = 0; i < input.length(); ++i) {
            char c = input[i];
            if (c == ';' ) break;

            if (c == '(' || c == '{' || c == '[') {
                stack.Push(c);
            } else if (c == ')' || c == '}' || c == ']') {
                if (stack.IsEmpty()) {
                    error = true;
                    errorPos = i;
                    break;
                }
                char top = stack.Pop();
                if ((c == ')' && top != '(') ||
                    (c == '}' && top != '{') ||
                    (c == ']' && top != '[')) {
                    error = true;
                    errorPos = i;
                    break;
                }
            }
        }

        if (!error && !stack.IsEmpty()) {
            error = true;
            errorPos = input.length() - 1; // Simplification
        }

        if (!error) {
            std::cout << "The string is correct." << std::endl;
        } else {
            std::cout << "Error occurred. String up to error: " << std::endl;
            std::cout << input.substr(0, errorPos + 1) << std::endl;
            std::cout << "Error at position " << errorPos << ": unexpected '" << input[errorPos] << "'" << std::endl;
        }
    }
};

#endif // STACK_TASKS_H
