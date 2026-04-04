//
// Created by Junie on 04.04.2026.
//

#ifndef ST_C_R_HOMEWORK_H
#define ST_C_R_HOMEWORK_H
#pragma once

#include "../Base.h"
#include "../Shared/Helpers.h"
#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

class Homework : public Base {
public:
    Homework() {}

    void Run() override {
        const Helpers helpers;
        bool exit = false;
        while (!exit) {
            cout << "\n--- Homework Menu ---\n";
            cout << "1. Task 1 (Array copy and sort by sign)\n";
            cout << "2. Task 2 (ICQ and Phone Directory)\n";
            cout << "3. Task 3 (Academic Performance)\n";
            cout << "0. Back to Main Menu / Exit\n";
            int choice = helpers.GetDataFromUser<int>("Select task: ");

            switch (choice) {
                case 1: Task1Run(); break;
                case 2: Task2Run(); break;
                case 3: Task3Run(); break;
                case 0: exit = true; break;
                default: cout << "Invalid choice.\n";
            }
        }
    }

private:
    // Завдання 1:
    // Написати програму, яка копіює елементи двох масивів розміром 5 елементів кожен в один масив розміром 10 елементів:
    // спочатку > 0, потім == 0, потім < 0.
    void Task1Run() {
        cout << "\n--- Task 1: Array Grouping ---\n";
        int arr1[5], arr2[5], result[10];
        const Helpers helpers;

        cout << "Enter 5 elements for first array:\n";
        for (int i = 0; i < 5; i++) arr1[i] = helpers.GetDataFromUser<int>("[" + to_string(i) + "]: ");

        cout << "Enter 5 elements for second array:\n";
        for (int i = 0; i < 5; i++) arr2[i] = helpers.GetDataFromUser<int>("[" + to_string(i) + "]: ");

        int idx = 0;
        // Позитивні
        for (int x : arr1) if (x > 0) result[idx++] = x;
        for (int x : arr2) if (x > 0) result[idx++] = x;
        // Нулі
        for (int x : arr1) if (x == 0) result[idx++] = x;
        for (int x : arr2) if (x == 0) result[idx++] = x;
        // Негативні
        for (int x : arr1) if (x < 0) result[idx++] = x;
        for (int x : arr2) if (x < 0) result[idx++] = x;

        cout << "Resulting array: ";
        for (int i = 0; i < 10; i++) cout << result[i] << " ";
        cout << endl;
    }

    // Завдання 2:
    // Написати програму «Довідник». Створити два одновимірних масиви (ICQ та телефон).
    // Меню: Сортування ICQ, Сортування Телефон, Пошук ICQ, Вихід.
    void Task2Run() {
        cout << "\n--- Task 2: Directory ---\n";
        const int size = 5; // Для прикладу 5
        long long icq[size] = {555666, 111222, 444333, 222111, 333444};
        string phones[size] = {"0501112233", "0671112233", "0931112233", "0504445566", "0677778899"};
        const Helpers helpers;
        bool back = false;

        while (!back) {
            cout << "\n1. Sort by ICQ\n";
            cout << "2. Sort by Phone\n";
            cout << "3. Find by ICQ\n";
            cout << "0. Back\n";
            int choice = helpers.GetDataFromUser<int>("Select option: ");

            if (choice == 1) {
                // Сортування бульбашкою (синхронне)
                for (int i = 0; i < size - 1; i++) {
                    for (int j = 0; j < size - i - 1; j++) {
                        if (icq[j] > icq[j + 1]) {
                            swap(icq[j], icq[j + 1]);
                            swap(phones[j], phones[j + 1]);
                        }
                    }
                }
                cout << "Sorted by ICQ.\n";
                PrintDirectory(icq, phones, size);
            } else if (choice == 2) {
                for (int i = 0; i < size - 1; i++) {
                    for (int j = 0; j < size - i - 1; j++) {
                        if (phones[j] > phones[j + 1]) {
                            swap(icq[j], icq[j + 1]);
                            swap(phones[j], phones[j + 1]);
                        }
                    }
                }
                cout << "Sorted by Phone.\n";
                PrintDirectory(icq, phones, size);
            } else if (choice == 3) {
                long long searchIcq = helpers.GetDataFromUser<long long>("Enter ICQ to find: ");
                int foundIdx = -1;
                for (int i = 0; i < size; i++) {
                    if (icq[i] == searchIcq) {
                        foundIdx = i;
                        break;
                    }
                }
                if (foundIdx != -1) {
                    cout << "Found at index: " << foundIdx << " (ICQ: " << icq[foundIdx] << ", Phone: " << phones[foundIdx] << ")\n";
                } else {
                    cout << "Not found.\n";
                }
            } else if (choice == 0) {
                back = true;
            }
        }
    }

    void PrintDirectory(long long icq[], string phones[], int size) {
        for (int i = 0; i < size; i++) {
            cout << "[" << i << "] ICQ: " << icq[i] << ", Phone: " << phones[i] << endl;
        }
    }

    // Завдання 3:
    // Програма «Успішність». 10 оцінок, сортування.
    // Меню: Вивід, Перескладання (оптимальний пошук), Стипендія (середній >= 10.7).
    void Task3Run() {
        cout << "\n--- Task 3: Academic Performance ---\n";
        const int size = 10;
        int grades[size];
        const Helpers helpers;

        cout << "Enter 10 grades (1-12):\n";
        for (int i = 0; i < size; i++) {
            grades[i] = helpers.GetDataFromUser<int>("Grade " + to_string(i + 1) + ": ");
        }

        // Початкове сортування для роботи меню
        sort(grades, grades + size);

        bool back = false;
        while (!back) {
            cout << "\n1. Show grades\n";
            cout << "2. Retake exam (change grade)\n";
            cout << "3. Scholarship check\n";
            cout << "0. Back\n";
            int choice = helpers.GetDataFromUser<int>("Select option: ");

            if (choice == 1) {
                cout << "Grades: ";
                for (int g : grades) cout << g << " ";
                cout << endl;
            } else if (choice == 2) {
                // За умовою: "користувач вводить номер елемента масиву та нову оцінку"
                // "пошук реалізувати найбільш оптимальним методом"
                // Якщо ми шукаємо за ІНДЕКСОМ, пошук миттєвий. 
                // Але можливо мається на увазі пошук ОЦІНКИ для заміни? 
                // "користувач вводить номер елемента" зазвичай означає індекс.
                // Спробуємо реалізувати пошук за значенням (бінарний), якщо це малось на увазі, 
                // або просто за індексом як просить умова.
                int idx = helpers.GetDataFromUser<int>("Enter element index (0-9): ");
                if (idx >= 0 && idx < size) {
                    int newGrade = helpers.GetDataFromUser<int>("Enter new grade: ");
                    grades[idx] = newGrade;
                    sort(grades, grades + size); // Пересортовуємо після зміни
                    cout << "Updated and re-sorted.\n";
                } else {
                    cout << "Invalid index.\n";
                }
            } else if (choice == 3) {
                double sum = 0;
                for (int g : grades) sum += g;
                double avg = sum / size;
                cout << "Average: " << avg << endl;
                if (avg >= 10.7) cout << "Scholarship granted!\n";
                else cout << "No scholarship.\n";
            } else if (choice == 0) {
                back = true;
            }
        }
    }
};

#endif //ST_C_R_HOMEWORK_H
