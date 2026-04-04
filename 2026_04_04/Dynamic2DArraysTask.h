//
// Created by Junie on 04.04.2026.
//

#ifndef ST_C_R_DYNAMIC2DARRAYSTASK_H
#define ST_C_R_DYNAMIC2DARRAYSTASK_H
#pragma once

#include "../Base.h"
#include "../Shared/Helpers.h"
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <set>

using namespace std;

class Dynamic2DArraysTask : public Base {
public:
    Dynamic2DArraysTask() {}

    void Run() override {
        const Helpers helpers;
        bool exit = false;
        while (!exit) {
            cout << "\n--- Dynamic 2D Arrays Task Menu ---\n";
            cout << "1. Task 1 (Add column to 2D array)\n";
            cout << "2. Task 2 (Remove column from 2D array)\n";
            cout << "3. Task 3 (Directory: Name and Phone)\n";
            cout << "4. Task 4 (Sort student surnames)\n";
            cout << "5. Task 5 (Operations on three arrays A, B, C)\n";
            cout << "0. Back to Main Menu / Exit\n";
            int choice = helpers.GetDataFromUser<int>("Select task: ");

            switch (choice) {
                case 1: Task1Run(); break;
                case 2: Task2Run(); break;
                case 3: Task3Run(); break;
                case 4: Task4Run(); break;
                case 5: Task5Run(); break;
                case 0: exit = true; break;
                default: cout << "Invalid choice.\n";
            }
        }
    }

private:
    // Helper to print 2D array
    void print2DArray(int** arr, int rows, int cols) {
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                cout << arr[i][j] << "\t";
            }
            cout << endl;
        }
    }

    // Task 1: Add a column to a 2D array at a specified position
    void Task1Run() {
        cout << "\n--- Task 1: Add column ---\n";
        const Helpers h;
        int rows = h.GetDataFromUser<int>("Enter number of rows: ");
        int cols = h.GetDataFromUser<int>("Enter number of columns: ");

        int** arr = new int*[rows];
        for (int i = 0; i < rows; i++) {
            arr[i] = new int[cols];
            for (int j = 0; j < cols; j++) {
                arr[i][j] = i * 10 + j;
            }
        }

        cout << "Initial array:\n";
        print2DArray(arr, rows, cols);

        int pos = h.GetDataFromUser<int>("Enter position for new column (0 to " + to_string(cols) + "): ");
        if (pos < 0 || pos > cols) {
            cout << "Invalid position.\n";
            // Clean up
            for (int i = 0; i < rows; i++) delete[] arr[i];
            delete[] arr;
            return;
        }

        int** newArr = new int*[rows];
        for (int i = 0; i < rows; i++) {
            newArr[i] = new int[cols + 1];
            for (int j = 0, k = 0; j < cols + 1; j++) {
                if (j == pos) {
                    newArr[i][j] = 999; // Value for the new column
                } else {
                    newArr[i][j] = arr[i][k++];
                }
            }
        }

        cout << "Array after adding column:\n";
        print2DArray(newArr, rows, cols + 1);

        // Clean up
        for (int i = 0; i < rows; i++) delete[] arr[i];
        delete[] arr;
        for (int i = 0; i < rows; i++) delete[] newArr[i];
        delete[] newArr;
    }

    // Task 2: Remove a column from a 2D array by index
    void Task2Run() {
        cout << "\n--- Task 2: Remove column ---\n";
        const Helpers h;
        int rows = h.GetDataFromUser<int>("Enter number of rows: ");
        int cols = h.GetDataFromUser<int>("Enter number of columns: ");

        if (cols <= 0) return;

        int** arr = new int*[rows];
        for (int i = 0; i < rows; i++) {
            arr[i] = new int[cols];
            for (int j = 0; j < cols; j++) {
                arr[i][j] = i * 10 + j;
            }
        }

        cout << "Initial array:\n";
        print2DArray(arr, rows, cols);

        int pos = h.GetDataFromUser<int>("Enter column index to remove (0 to " + to_string(cols - 1) + "): ");
        if (pos < 0 || pos >= cols) {
            cout << "Invalid position.\n";
            for (int i = 0; i < rows; i++) delete[] arr[i];
            delete[] arr;
            return;
        }

        int** newArr = new int*[rows];
        for (int i = 0; i < rows; i++) {
            newArr[i] = new int[cols - 1];
            for (int j = 0, k = 0; j < cols; j++) {
                if (j != pos) {
                    newArr[i][k++] = arr[i][j];
                }
            }
        }

        cout << "Array after removing column:\n";
        print2DArray(newArr, rows, cols - 1);

        // Clean up
        for (int i = 0; i < rows; i++) delete[] arr[i];
        delete[] arr;
        for (int i = 0; i < rows; i++) delete[] newArr[i];
        delete[] newArr;
    }

    // Task 3: Directory: Name and Phone (dynamic array of strings)
    void Task3Run() {
        cout << "\n--- Task 3: Directory ---\n";
        const Helpers h;
        int size = 0;
        // First row: Name, Second row: Phone
        string** directory = new string*[2];
        directory[0] = nullptr; // Names
        directory[1] = nullptr; // Phones

        auto resize = [&](int newSize) {
            string* newNames = new string[newSize];
            string* newPhones = new string[newSize];
            for (int i = 0; i < min(size, newSize); i++) {
                newNames[i] = directory[0][i];
                newPhones[i] = directory[1][i];
            }
            delete[] directory[0];
            delete[] directory[1];
            directory[0] = newNames;
            directory[1] = newPhones;
            size = newSize;
        };

        bool dirExit = false;
        while (!dirExit) {
            cout << "\n1. Add Entry\n2. Search by Name\n3. Search by Phone\n4. Change Data\n5. Show All\n0. Exit\n";
            int choice = h.GetDataFromUser<int>("Select action: ");
            switch (choice) {
                case 1: {
                    resize(size + 1);
                    directory[0][size - 1] = h.GetDataFromUser<string>("Enter Name: ");
                    directory[1][size - 1] = h.GetDataFromUser<string>("Enter Phone: ");
                    break;
                }
                case 2: {
                    string name = h.GetDataFromUser<string>("Enter name to search: ");
                    bool found = false;
                    for (int i = 0; i < size; i++) {
                        if (directory[0][i] == name) {
                            cout << "Found: " << directory[0][i] << " - " << directory[1][i] << endl;
                            found = true;
                        }
                    }
                    if (!found) cout << "Not found.\n";
                    break;
                }
                case 3: {
                    string phone = h.GetDataFromUser<string>("Enter phone to search: ");
                    bool found = false;
                    for (int i = 0; i < size; i++) {
                        if (directory[1][i] == phone) {
                            cout << "Found: " << directory[0][i] << " - " << directory[1][i] << endl;
                            found = true;
                        }
                    }
                    if (!found) cout << "Not found.\n";
                    break;
                }
                case 4: {
                    int idx = h.GetDataFromUser<int>("Enter index to change (0 to " + to_string(size - 1) + "): ");
                    if (idx >= 0 && idx < size) {
                        directory[0][idx] = h.GetDataFromUser<string>("Enter new Name: ");
                        directory[1][idx] = h.GetDataFromUser<string>("Enter new Phone: ");
                    } else cout << "Invalid index.\n";
                    break;
                }
                case 5: {
                    for (int i = 0; i < size; i++) {
                        cout << i << ". " << directory[0][i] << " - " << directory[1][i] << endl;
                    }
                    break;
                }
                case 0: dirExit = true; break;
            }
        }

        delete[] directory[0];
        delete[] directory[1];
        delete[] directory;
    }

    // Task 4: Sort student surnames
    void Task4Run() {
        cout << "\n--- Task 4: Sort Surnames ---\n";
        const Helpers h;
        string surnames[5];
        for (int i = 0; i < 5; i++) {
            surnames[i] = h.GetDataFromUser<string>("Enter surname " + to_string(i + 1) + ": ");
        }

        sort(surnames, surnames + 5);

        cout << "Sorted surnames:\n";
        for (const auto& s : surnames) cout << s << endl;
    }

    // Task 5: Operations on three arrays A, B, C
    void Task5Run() {
        cout << "\n--- Task 5: Array Operations ---\n";
        const Helpers h;
        auto fillArray = [&](int rows, int cols) {
            int** arr = new int*[rows];
            for (int i = 0; i < rows; i++) {
                arr[i] = new int[cols];
                for (int j = 0; j < cols; j++) {
                    arr[i][j] = h.GetDataFromUser<int>("Enter element [" + to_string(i) + "][" + to_string(j) + "]: ");
                }
            }
            return arr;
        };

        auto clearArray = [](int** arr, int rows) {
            for (int i = 0; i < rows; i++) delete[] arr[i];
            delete[] arr;
        };

        auto getUniqueFrom2D = [](int** arr, int rows, int cols) {
            set<int> elements;
            for (int i = 0; i < rows; i++) {
                for (int j = 0; j < cols; j++) {
                    elements.insert(arr[i][j]);
                }
            }
            return elements;
        };

        int rA = h.GetDataFromUser<int>("A Rows: "), cA = h.GetDataFromUser<int>("A Cols: ");
        int** A = fillArray(rA, cA);
        int rB = h.GetDataFromUser<int>("B Rows: "), cB = h.GetDataFromUser<int>("B Cols: ");
        int** B = fillArray(rB, cB);
        int rC = h.GetDataFromUser<int>("C Rows: "), cC = h.GetDataFromUser<int>("C Cols: ");
        int** C = fillArray(rC, cC);

        set<int> setA = getUniqueFrom2D(A, rA, cA);
        set<int> setB = getUniqueFrom2D(B, rB, cB);
        set<int> setC = getUniqueFrom2D(C, rC, cC);

        // Common values for A, B, C
        vector<int> commonABC;
        for (int x : setA) {
            if (setB.count(x) && setC.count(x)) commonABC.push_back(x);
        }

        // Unique values for A, B, C (elements that appear in any of them only once? 
        // Or elements that are present in total across all?
        // Typically "unique values" means elements present in the union. 
        // But task says "unique values for A, B, C", could mean elements present in A but not in B or C, etc.
        // Given Task 1 from previous homework, it likely means elements present in the union.
        // Let's assume UNION.
        set<int> unionABC = setA;
        unionABC.insert(setB.begin(), setB.end());
        unionABC.insert(setC.begin(), setC.end());

        // Common for A and C
        vector<int> commonAC;
        for (int x : setA) {
            if (setC.count(x)) commonAC.push_back(x);
        }

        // Negative values without repetitions
        set<int> negativeUnique;
        auto addNeg = [&](set<int>& s) {
            for (int x : s) if (x < 0) negativeUnique.insert(x);
        };
        addNeg(setA); addNeg(setB); addNeg(setC);

        cout << "\nCommon A, B, C: ";
        for (int x : commonABC) cout << x << " ";
        cout << "\nUnion (all values): ";
        for (int x : unionABC) cout << x << " ";
        cout << "\nCommon A, C: ";
        for (int x : commonAC) cout << x << " ";
        cout << "\nNegative Unique: ";
        for (int x : negativeUnique) cout << x << " ";
        cout << endl;

        clearArray(A, rA);
        clearArray(B, rB);
        clearArray(C, rC);
    }
};

#endif //ST_C_R_DYNAMIC2DARRAYSTASK_H
