#ifndef EXCEPTIONS_TASKS_H
#define EXCEPTIONS_TASKS_H

#include <iostream>
#include <string>
#include <vector>
#include <climits>
#include "CustomExceptions.h"

// Завдання 1: Перетворення рядка в int з перевіркою переповнення
int StringToInt(const std::string& str) {
    long long result = 0;
    bool negative = false;
    size_t i = 0;

    if (str.empty()) throw MathException("Empty string");

    if (str[0] == '-') {
        negative = true;
        i = 1;
    } else if (str[0] == '+') {
        i = 1;
    }

    if (i == str.length()) throw MathException("String contains only sign");

    for (; i < str.length(); ++i) {
        if (str[i] < '0' || str[i] > '9') throw MathException("Invalid character");
        
        result = result * 10 + (str[i] - '0');
        
        if (!negative && result > INT_MAX) throw OverflowException();
        if (negative && -result < INT_MIN) throw OverflowException();
    }

    return negative ? static_cast<int>(-result) : static_cast<int>(result);
}

// Завдання 2: Stack з винятками
template <typename T>
class Stack {
    T* data;
    int capacity;
    int top;

public:
    Stack(int size) : capacity(size), top(-1) {
        if (size <= 0) throw StackException("Invalid stack size");
        data = new (std::nothrow) T[capacity];
        if (!data) throw MemoryException("Failed to allocate memory for stack");
    }

    ~Stack() {
        delete[] data;
    }

    void Push(const T& value) {
        if (top == capacity - 1) throw StackException("Stack overflow");
        data[++top] = value;
    }

    T Pop() {
        if (top == -1) throw StackException("Stack underflow");
        return data[top--];
    }

    T Peek() const {
        if (top == -1) throw StackException("Stack is empty");
        return data[top];
    }

    bool IsEmpty() const { return top == -1; }
};

// Завдання 1 (Exceptions 2): Двозв'язний список з винятками
template <typename T>
class DoubleLinkedList {
    struct Node {
        T data;
        Node* next;
        Node* prev;
        Node(const T& val) : data(val), next(nullptr), prev(nullptr) {}
    };

    Node* head;
    Node* tail;
    int size;

public:
    DoubleLinkedList() : head(nullptr), tail(nullptr), size(0) {}

    ~DoubleLinkedList() {
        while (head) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }

    void AddTail(const T& val) {
        Node* newNode = new (std::nothrow) Node(val);
        if (!newNode) throw MemoryException("Failed to allocate memory for list node");
        
        if (!head) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
        size++;
    }

    void RemoveTail() {
        if (!tail) throw ListException("Attempt to remove from empty list");
        
        Node* temp = tail;
        if (head == tail) {
            head = tail = nullptr;
        } else {
            tail = tail->prev;
            tail->next = nullptr;
        }
        delete temp;
        size--;
    }

    void Display() const {
        Node* curr = head;
        while (curr) {
            std::cout << curr->data << " <-> ";
            curr = curr->next;
        }
        std::cout << "nullptr" << std::endl;
    }
};

#endif // EXCEPTIONS_TASKS_H
