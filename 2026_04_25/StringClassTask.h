//
// Created by Junie on 25.04.2026.
//

#ifndef ST_C_R_STRINGCLASSTASK_H
#define ST_C_R_STRINGCLASSTASK_H

#include "../Base.h"
#include <iostream>
#include <cstring>

class String {
private:
    char* data;
    int length;
    static int objectCount;

public:
    // Конструктор довільного розміру
    String(int size) {
        length = size;
        data = new char[length + 1];
        data[0] = '\0';
        objectCount++;
    }

    // Конструктор за замовчуванням (80 символів) - делегування
    String() : String(80) {}

    // Конструктор з ініціалізацією рядком
    String(const char* str) {
        length = strlen(str);
        data = new char[length + 1];
        strcpy(data, str);
        objectCount++;
    }

    // Деструктор
    ~String() {
        delete[] data;
        objectCount--;
    }

    void Input() {
        std::cout << "Введіть рядок: ";
        char buffer[1024];
        std::cin.getline(buffer, 1024);
        
        delete[] data;
        length = strlen(buffer);
        data = new char[length + 1];
        strcpy(data, buffer);
    }

    void Output() const {
        std::cout << "Рядок: " << data << " (довжина: " << length << ")" << std::endl;
    }

    static int GetObjectCount() {
        return objectCount;
    }
};

int String::objectCount = 0;

class StringClassTask : public Base {
public:
    void Run() override {
        std::cout << "--- Завдання 1: Клас String ---" << std::endl;
        
        std::cout << "Кількість об'єктів до створення: " << String::GetObjectCount() << std::endl;
        
        String s1; // 80 chars
        String s2(20); // 20 chars
        String s3("Привіт, світ!");
        
        std::cout << "Кількість об'єктів після створення 3-х об'єктів: " << String::GetObjectCount() << std::endl;
        
        s1.Output();
        s2.Output();
        s3.Output();
        
        std::cout << "Введення для s2:" << std::endl;
        s2.Input();
        s2.Output();
        
        {
            String s4("Тимчасовий об'єкт");
            std::cout << "Кількість об'єктів (в блоці): " << String::GetObjectCount() << std::endl;
        }
        
        std::cout << "Кількість об'єктів (після блоку): " << String::GetObjectCount() << std::endl;
    }
};

#endif //ST_C_R_STRINGCLASSTASK_H
