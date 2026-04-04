//
// Created by Junie on 04.04.2026.
//

#ifndef ST_C_R_POINTERSTASK_H
#define ST_C_R_POINTERSTASK_H
#pragma once

#include "../Base.h"
#include "../Shared/Helpers.h"
#include <iostream>
#include <string>

using namespace std;

class PointersTask : public Base {
public:
    PointersTask() {}

    void Run() override {
        const Helpers helpers;
        bool exit = false;
        while (!exit) {
            cout << "\n--- Pointers Task Menu ---\n";
            cout << "1. Task 1 (Determine sign of a number using pointers)\n";
            cout << "2. Task 2 (Primitive calculator on pointers)\n";
            cout << "3. Task 3 (Sum of array elements using pointer arithmetic)\n";
            cout << "4. Task 4 (Copying an array in reverse order using pointers)\n";
            cout << "0. Back to Main Menu / Exit\n";
            int choice = helpers.GetDataFromUser<int>("Select task: ");

            switch (choice) {
                case 1: Task1Run(); break;
                case 2: Task2Run(); break;
                case 3: Task3Run(); break;
                case 4: Task4Run(); break;
                case 0: exit = true; break;
                default: cout << "Invalid choice.\n";
            }
        }
    }

private:
    // Завдання №1 — Визначення знаку числа
    void Task1Run() {
        cout << "\n--- Task 1: Determine Sign ---\n";
        int num;
        const Helpers helpers;
        num = helpers.GetDataFromUser<int>("Enter a number: ");
        
        int* ptr = &num;
        
        if (*ptr > 0) {
            cout << "Число додатне" << endl;
        } else if (*ptr < 0) {
            cout << "Число від'ємне" << endl;
        } else {
            cout << "Число дорівнює нулю" << endl;
        }
    }

    // Завдання №2 — Примітивний калькулятор на покажчиках
    void Task2Run() {
        cout << "\n--- Task 2: Pointers Calculator ---\n";
        double a, b, res;
        double *ptrA = &a, *ptrB = &b, *ptrRes = &res;
        const Helpers helpers;
        
        *ptrA = helpers.GetDataFromUser<double>("Enter first operand: ");
        *ptrB = helpers.GetDataFromUser<double>("Enter second operand: ");
        char op = helpers.GetDataFromUser<char>("Enter operation (+, -, *, /): ");
        
        bool valid = true;
        if (op == '+') {
            *ptrRes = *ptrA + *ptrB;
        } else if (op == '-') {
            *ptrRes = *ptrA - *ptrB;
        } else if (op == '*') {
            *ptrRes = *ptrA * *ptrB;
        } else if (op == '/') {
            if (*ptrB != 0) {
                *ptrRes = *ptrA / *ptrB;
            } else {
                cout << "Error: Division by zero!" << endl;
                valid = false;
            }
        } else {
            cout << "Error: Invalid operation!" << endl;
            valid = false;
        }
        
        if (valid) {
            cout << "Result: " << *ptrRes << endl;
        }
    }

    // Завдання №3 — Сума елементів масиву
    void Task3Run() {
        cout << "\n--- Task 3: Array Sum with Pointers ---\n";
        const int size = 5;
        int arr[size] = {10, 20, 30, 40, 50};
        int* ptr = arr;
        int sum = 0;
        
        cout << "Array: ";
        for (int i = 0; i < size; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
        
        for (int i = 0; i < size; i++) {
            sum += *ptr;
            ptr++;
        }
        
        cout << "Sum: " << sum << endl;
    }

    // Завдання №4 — Копіювання масиву у зворотному порядку
    void Task4Run() {
        cout << "\n--- Task 4: Reverse Array Copy with Pointers ---\n";
        const int size = 5;
        int srcArr[size] = {1, 2, 3, 4, 5};
        int dstArr[size];
        
        int* src = &srcArr[size - 1];
        int* dst = dstArr;
        
        for (int i = 0; i < size; i++) {
            *dst = *src;
            src--;
            dst++;
        }
        
        cout << "Source array: ";
        for (int i = 0; i < size; i++) cout << srcArr[i] << " ";
        cout << endl;
        
        cout << "Destination array (reversed): ";
        for (int i = 0; i < size; i++) cout << dstArr[i] << " ";
        cout << endl;
    }
};

#endif //ST_C_R_POINTERSTASK_H
