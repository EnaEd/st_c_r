//
// Created by Junie on 04.04.2026.
//

#ifndef ST_C_R_RECURSIONANDGAMES_H
#define ST_C_R_RECURSIONANDGAMES_H
#pragma once

#include "../Base.h"
#include "../Shared/Helpers.h"
#include <iostream>
#include <string>
#include <vector>
#include <random>
#include <ctime>

using namespace std;

class RecursionAndGames : public Base {
public:
    RecursionAndGames() {}

    void Run() override {
        const Helpers helpers;
        bool exit = false;
        while (!exit) {
            cout << "\n--- Recursion and Games Menu ---\n";
            cout << "1. Task 1 (Recursive GCD)\n";
            cout << "2. Task 2 (Recursive Power)\n";
            cout << "3. Task 3 (Recursive Digit Sum)\n";
            cout << "4. Task 4 (Bulls and Cows Game)\n";
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
    // Завдання 1: Рекурсивний НСД
    int GCD(int a, int b) {
        if (b == 0) return a;
        return GCD(b, a % b);
    }

    void Task1Run() {
        const Helpers helpers;
        cout << "\n--- Task 1: Recursive GCD ---\n";
        int a = helpers.GetDataFromUser<int>("Enter first number: ");
        int b = helpers.GetDataFromUser<int>("Enter second number: ");
        cout << "GCD(" << a << ", " << b << ") = " << GCD(a, b) << endl;
    }

    // Завдання 2: Рекурсивний степінь
    long long isPow(int a, int n) {
        if (n == 0) return 1;
        if (n == 1) return a;
        return a * isPow(a, n - 1);
    }

    void Task2Run() {
        const Helpers helpers;
        cout << "\n--- Task 2: Recursive Power ---\n";
        int a = helpers.GetDataFromUser<int>("Enter base (a): ");
        int n = helpers.GetDataFromUser<int>("Enter exponent (n): ");
        if (n < 0) {
            cout << "Exponent must be non-negative for this implementation.\n";
        } else {
            cout << a << "^" << n << " = " << isPow(a, n) << endl;
        }
    }

    // Завдання 3: Рекурсивна сума цифр
    int digitSum(int n) {
        n = abs(n);
        if (n == 0) return 0;
        return (n % 10) + digitSum(n / 10);
    }

    void Task3Run() {
        const Helpers helpers;
        cout << "\n--- Task 3: Recursive Digit Sum ---\n";
        int n = helpers.GetDataFromUser<int>("Enter number: ");
        cout << "Sum of digits of " << n << " is " << digitSum(n) << endl;
    }

    // Завдання 4: Гра «Бики і корови»
    void Task4Run() {
        cout << "\n--- Task 4: Bulls and Cows ---\n";
        cout << "Welcome to Bulls and Cows game!\n";

        random_device rd;
        mt19937 gen(rd());
        uniform_int_distribution<> dis(0, 9);

        // Загадуємо чотиризначне число (цифри можуть повторюватися за умовою прикладу "9978")
        vector<int> secret(4);
        for (int i = 0; i < 4; ++i) {
            secret[i] = dis(gen);
        }

        const Helpers helpers;
        int attempts = 0;
        bool guessed = false;

        while (!guessed) {
            int guessNum = helpers.GetDataFromUser<int>("Enter a 4-digit number: ");
            if (guessNum < 0 || guessNum > 9999) {
                cout << "Please enter a 4-digit number (0-9999).\n";
                continue;
            }

            attempts++;
            vector<int> guess(4);
            int temp = guessNum;
            for (int i = 3; i >= 0; --i) {
                guess[i] = temp % 10;
                temp /= 10;
            }

            int bulls = 0;
            int cows = 0;
            vector<bool> secretUsed(4, false);
            vector<bool> guessUsed(4, false);

            // Рахуємо биків
            for (int i = 0; i < 4; ++i) {
                if (guess[i] == secret[i]) {
                    bulls++;
                    secretUsed[i] = true;
                    guessUsed[i] = true;
                }
            }

            // Рахуємо корів
            for (int i = 0; i < 4; ++i) {
                if (!guessUsed[i]) {
                    for (int j = 0; j < 4; ++j) {
                        if (!secretUsed[j] && guess[i] == secret[j]) {
                            cows++;
                            secretUsed[j] = true;
                            break;
                        }
                    }
                }
            }

            cout << bulls << " bulls, " << cows << " cows\n";

            if (bulls == 4) {
                guessed = true;
                cout << "Congratulations! You guessed the number " << guessNum << " in " << attempts << " attempts.\n";
            }
        }
    }
};

#endif //ST_C_R_RECURSIONANDGAMES_H
