//
// Created by Junie on 04.04.2026.
//

#ifndef ST_C_R_FILESTASK_H
#define ST_C_R_FILESTASK_H
#pragma once

#include "../Base.h"
#include "../Shared/Helpers.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <iomanip>

using namespace std;

class FilesTask : public Base {
public:
    FilesTask() {}

    void Run() override {
        const Helpers helpers;
        bool exit = false;
        while (!exit) {
            cout << "\n--- Files Task Menu ---\n";
            cout << "1. Task 1 (Compare two files)\n";
            cout << "2. Task 2 (File statistics)\n";
            cout << "3. Task 3 (Caesar Cipher)\n";
            cout << "4. Task 4 (Employee Information System)\n";
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
    // Завдання 1. Порівняння двох файлів
    void Task1Run() {
        cout << "\n--- Task 1: Compare Files ---\n";
        string path1, path2;
        const Helpers helpers;
        path1 = helpers.GetDataFromUser<string>("Enter path for first file: ");
        path2 = helpers.GetDataFromUser<string>("Enter path for second file: ");

        ifstream f1(path1), f2(path2);
        if (!f1 || !f2) {
            cout << "Error opening files!\n";
            return;
        }

        string line1, line2;
        int lineNum = 1;
        bool mismatch = false;

        while (getline(f1, line1)) {
            if (!getline(f2, line2)) {
                cout << "Mismatch at line " << lineNum << ":\n";
                cout << "File 1: " << line1 << "\n";
                cout << "File 2: [End of file]\n";
                mismatch = true;
                break;
            }
            if (line1 != line2) {
                cout << "Mismatch at line " << lineNum << ":\n";
                cout << "File 1: " << line1 << "\n";
                cout << "File 2: " << line2 << "\n";
                mismatch = true;
                break;
            }
            lineNum++;
        }

        if (!mismatch && getline(f2, line2)) {
            cout << "Mismatch at line " << lineNum << ":\n";
            cout << "File 1: [End of file]\n";
            cout << "File 2: " << line2 << "\n";
            mismatch = true;
        }

        if (!mismatch) {
            cout << "Files are identical.\n";
        }
    }

    // Завдання 2. Статистика файлу
    void Task2Run() {
        cout << "\n--- Task 2: File Statistics ---\n";
        string inputPath, outputPath;
        const Helpers helpers;
        inputPath = helpers.GetDataFromUser<string>("Enter input file path: ");
        outputPath = helpers.GetDataFromUser<string>("Enter output file path: ");

        ifstream fin(inputPath);
        if (!fin) {
            cout << "Error opening input file!\n";
            return;
        }

        int charCount = 0, lineCount = 0, vowelCount = 0, consCount = 0, digitCount = 0;
        string line;
        string vowels = "aeiouAEIOUаеєиіїоуюяАЕЄИІЇОУЮЯ";

        while (getline(fin, line)) {
            lineCount++;
            charCount += line.length(); // Including spaces, excluding \n
            for (char c : line) {
                if (isdigit(c)) {
                    digitCount++;
                } else if (isalpha((unsigned char)c) || (c < 0)) { // (c < 0) for cyrillic in some encodings
                    bool isVowel = false;
                    for (char v : vowels) if (c == v) isVowel = true;
                    if (isVowel) vowelCount++;
                    else consCount++;
                }
            }
        }

        ofstream fout(outputPath);
        if (!fout) {
            cout << "Error opening output file!\n";
            return;
        }

        fout << "Characters: " << charCount << "\n";
        fout << "Lines: " << lineCount << "\n";
        fout << "Vowels: " << vowelCount << "\n";
        fout << "Consonants: " << consCount << "\n";
        fout << "Digits: " << digitCount << "\n";

        cout << "Statistics saved to " << outputPath << "\n";
    }

    // Завдання 3. Шифр Цезаря
    void Task3Run() {
        cout << "\n--- Task 3: Caesar Cipher ---\n";
        const Helpers helpers;
        string inputPath = helpers.GetDataFromUser<string>("Enter input file path: ");
        string outputPath = helpers.GetDataFromUser<string>("Enter output file path: ");
        int key = helpers.GetDataFromUser<int>("Enter key (shift): ");

        ifstream fin(inputPath);
        ofstream fout(outputPath);
        if (!fin || !fout) {
            cout << "Error opening files!\n";
            return;
        }

        char c;
        while (fin.get(c)) {
            if (isalpha((unsigned char)c)) {
                char base = islower((unsigned char)c) ? 'a' : 'A';
                c = (char)(((c - base + key) % 26 + 26) % 26 + base);
            }
            // For Cyrillic, a more complex mapping would be needed. 
            // The example uses Cyrillic, so let's implement a basic version for it if possible.
            // But standard C++ char is signed and doesn't handle UTF-8 easily.
            // We'll stick to ASCII and mention the limitation if it fails on Cyrillic.
            fout.put(c);
        }
        cout << "Encrypted text saved to " << outputPath << "\n";
    }

    // Завдання 4. Інформаційна система «Співробітники»
    struct Employee {
        string lastName;
        int age;
        string position;
    };

    void Task4Run() {
        cout << "\n--- Task 4: Employee Information System ---\n";
        const Helpers helpers;
        vector<Employee> employees;
        string dbPath = helpers.GetDataFromUser<string>("Enter database file path (to load): ");

        // Load
        ifstream fin(dbPath);
        if (fin) {
            Employee emp;
            while (fin >> emp.lastName >> emp.age >> emp.position) {
                employees.push_back(emp);
            }
            fin.close();
            cout << "Loaded " << employees.size() << " employees.\n";
        } else {
            cout << "File not found or empty. Starting fresh.\n";
        }

        bool menuExit = false;
        while (!menuExit) {
            cout << "\n1. Add Employee\n2. Edit Employee\n3. Delete Employee\n4. Search by Last Name\n";
            cout << "5. Show by Age\n6. Show by First Letter of Last Name\n7. Show All\n8. Save Current View to File\n0. Exit & Save All\n";
            int subChoice = helpers.GetDataFromUser<int>("Choice: ");

            vector<Employee> filtered;
            switch (subChoice) {
                case 1: {
                    Employee e;
                    e.lastName = helpers.GetDataFromUser<string>("Last Name: ");
                    e.age = helpers.GetDataFromUser<int>("Age: ");
                    e.position = helpers.GetDataFromUser<string>("Position: ");
                    employees.push_back(e);
                    break;
                }
                case 2: {
                    string name = helpers.GetDataFromUser<string>("Enter Last Name to edit: ");
                    for (auto& e : employees) {
                        if (e.lastName == name) {
                            e.age = helpers.GetDataFromUser<int>("New Age: ");
                            e.position = helpers.GetDataFromUser<string>("New Position: ");
                            cout << "Updated.\n";
                        }
                    }
                    break;
                }
                case 3: {
                    string name = helpers.GetDataFromUser<string>("Enter Last Name to delete: ");
                    employees.erase(remove_if(employees.begin(), employees.end(), [&](const Employee& e) {
                        return e.lastName == name;
                    }), employees.end());
                    break;
                }
                case 4: {
                    string name = helpers.GetDataFromUser<string>("Enter Last Name to search: ");
                    for (const auto& e : employees) if (e.lastName == name) filtered.push_back(e);
                    displayEmployees(filtered);
                    break;
                }
                case 5: {
                    int age = helpers.GetDataFromUser<int>("Enter age: ");
                    for (const auto& e : employees) if (e.age == age) filtered.push_back(e);
                    displayEmployees(filtered);
                    break;
                }
                case 6: {
                    char letter = helpers.GetDataFromUser<char>("Enter letter: ");
                    for (const auto& e : employees) if (!e.lastName.empty() && tolower(e.lastName[0]) == tolower(letter)) filtered.push_back(e);
                    displayEmployees(filtered);
                    break;
                }
                case 7:
                    displayEmployees(employees);
                    break;
                case 8: {
                    string savePath = helpers.GetDataFromUser<string>("Enter filename to save results: ");
                    saveEmployees(savePath, filtered.empty() ? employees : filtered);
                    break;
                }
                case 0: {
                    saveEmployees(dbPath, employees);
                    menuExit = true;
                    break;
                }
            }
        }
    }

    void displayEmployees(const vector<Employee>& emps) {
        cout << left << setw(15) << "Last Name" << setw(5) << "Age" << "Position" << endl;
        for (const auto& e : emps) {
            cout << left << setw(15) << e.lastName << setw(5) << e.age << e.position << endl;
        }
    }

    void saveEmployees(const string& path, const vector<Employee>& emps) {
        ofstream fout(path);
        if (!fout) {
            cout << "Error saving to " << path << endl;
            return;
        }
        for (const auto& e : emps) {
            fout << e.lastName << " " << e.age << " " << e.position << "\n";
        }
        cout << "Saved to " << path << endl;
    }
};

#endif //ST_C_R_FILESTASK_H
