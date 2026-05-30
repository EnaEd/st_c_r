#ifndef VIRTUAL_FUNCTIONS_TASK_H
#define VIRTUAL_FUNCTIONS_TASK_H

#include <iostream>
#include <fstream>
#include <iomanip>
#include <bitset>
#include "CustomExceptions.h"

class FileDisplayBase {
public:
    virtual ~FileDisplayBase() = default;

    virtual void Display(const char* path) {
        std::ifstream file(path);
        if (!file.is_open()) throw FileException("Cannot open file: " + std::string(path));

        std::cout << "File content (Normal):" << std::endl;
        char ch;
        while (file.get(ch)) {
            std::cout << ch;
        }
        std::cout << std::endl;
        file.close();
    }
};

class FileDisplayASCII : public FileDisplayBase {
public:
    void Display(const char* path) override {
        std::ifstream file(path);
        if (!file.is_open()) throw FileException("Cannot open file: " + std::string(path));

        std::cout << "File content (ASCII codes):" << std::endl;
        char ch;
        while (file.get(ch)) {
            std::cout << static_cast<int>(static_cast<unsigned char>(ch)) << " ";
        }
        std::cout << std::endl;
        file.close();
    }
};

class FileDisplayBinary : public FileDisplayBase {
public:
    void Display(const char* path) override {
        std::ifstream file(path, std::ios::binary);
        if (!file.is_open()) throw FileException("Cannot open file: " + std::string(path));

        std::cout << "File content (Binary):" << std::endl;
        char ch;
        while (file.get(ch)) {
            std::cout << std::bitset<8>(static_cast<unsigned char>(ch)) << " ";
        }
        std::cout << std::endl;
        file.close();
    }
};

#endif // VIRTUAL_FUNCTIONS_TASK_H
