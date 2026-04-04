//
// Created by Junie on 04.04.2026.
//

#ifndef ST_C_R_STRINGSTASK_H
#define ST_C_R_STRINGSTASK_H
#pragma once

#include "../Base.h"
#include "../Shared/Helpers.h"
#include <iostream>
#include <string>
#include <limits>

class StringsTask : public Base {
public:
    StringsTask() {}

    void Run() override {
        int choice;
        const Helpers helpers;
        cout << "Select a task:\n"
             << "1. Delete character by index\n"
             << "2. Delete all occurrences of a character\n"
             << "3. Insert character at position\n"
             << "4. Replace '.' with '!'\n"
             << "5. Count occurrences of a character\n"
             << "6. Count letters, digits, and others\n"
             << "0. Exit\n";

        choice = helpers.GetDataFromUser<int>("Your choice: ");
        cin.ignore((numeric_limits<streamsize>::max)(), '\n'); // Clear buffer for getline

        switch (choice) {
            case 1: Task1Run(); break;
            case 2: Task2Run(); break;
            case 3: Task3Run(); break;
            case 4: Task4Run(); break;
            case 5: Task5Run(); break;
            case 6: Task6Run(); break;
            default: break;
        }
    }

private:
    // Завдання 1. Написати функцію, яка видаляє з рядка символ із заданим номером.
    static void deleteCharByIndex(string& s, int index) {
        if (index >= 0 && index < (int)s.length()) {
            s.erase(index, 1);
        }
    }

    void Task1Run() {
        string s;
        cout << "Enter a string: ";
        getline(cin, s);
        int index = Helpers().GetDataFromUser<int>("Enter index to delete: ");
        deleteCharByIndex(s, index);
        cout << "Result: " << s << endl;
    }

    // Завдання 2. Написати функцію, яка видаляє з рядка всі входження в нього заданого символу.
    static void deleteAllOccurrences(string& s, char target) {
        size_t pos;
        while ((pos = s.find(target)) != string::npos) {
            s.erase(pos, 1);
        }
    }

    void Task2Run() {
        string s;
        cout << "Enter a string: ";
        getline(cin, s);
        char target = Helpers().GetDataFromUser<char>("Enter character to delete: ");
        deleteAllOccurrences(s, target);
        cout << "Result: " << s << endl;
    }

    // Завдання 3. Написати функцію, яка вставляє в рядок у зазначену позицію заданий символ.
    static void insertChar(string& s, int pos, char val) {
        if (pos >= 0 && pos <= (int)s.length()) {
            s.insert(pos, 1, val);
        }
    }

    void Task3Run() {
        string s;
        cout << "Enter a string: ";
        getline(cin, s);
        int pos = Helpers().GetDataFromUser<int>("Enter position to insert: ");
        char val = Helpers().GetDataFromUser<char>("Enter character to insert: ");
        insertChar(s, pos, val);
        cout << "Result: " << s << endl;
    }

    // Завдання 4. Написати програму, яка замінює всі символи точки «.» у рядку, введеному користувачем, на символи знаку оклику «!».
    void Task4Run() {
        string s;
        cout << "Enter a string with dots: ";
        getline(cin, s);
        for (char& c : s) {
            if (c == '.') c = '!';
        }
        cout << "Result: " << s << endl;
    }

    // Завдання 5. Користувач вводить рядок символів і шуканий символ, порахувати скільки разів він трапляється в рядку.
    void Task5Run() {
        string s;
        cout << "Enter a string: ";
        getline(cin, s);
        char target = Helpers().GetDataFromUser<char>("Enter character to count: ");
        int count = 0;
        for (char c : s) {
            if (c == target) count++;
        }
        cout << "Character '" << target << "' occurs " << count << " times." << endl;
    }

    // Завдання 6. Користувач вводить рядок. Визначити кількість літер, цифр та інших символів, присутніх у рядку.
    void Task6Run() {
        string s;
        cout << "Enter a string: ";
        getline(cin, s);
        int letters = 0, digits = 0, others = 0;
        for (char c : s) {
            if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')) {
                letters++;
            } else if (c >= '0' && c <= '9') {
                digits++;
            } else {
                others++;
            }
        }
        cout << "Letters: " << letters << endl;
        cout << "Digits: " << digits << endl;
        cout << "Others: " << others << endl;
    }
};

#endif //ST_C_R_STRINGSTASK_H
