//
// Created by djazi on 02.03.2026.
//

#ifndef ST_C_R_ARRAYS_H
#define ST_C_R_ARRAYS_H
#pragma once
#include "../Base.h"
#include "Shared/Helpers.h"
#include <random>
class Arrays: public Base {
public:
    Arrays(){}
    void Run() override {
        //Task1Run();
        //Task2Run();
        //Task3Run();
        Task4Run();
    };

//region Task1
    // В одновимірному масиві, заповненому випадковими числами, визначити мінімальний і максимальний елементи.
    static void Task1Run() {
        random_device rd;
        mt19937 gen(rd());
        const uniform_int_distribution<> dist(1, 6);
        int numbers[5];
        for (int i = 0; i < 5; i++) {
            numbers[i] = dist(gen);
            cout << numbers[i] << " \n";
        }

        int min = numbers[0];
        int max = numbers[0];

        for (int i = 1; i < 5; i++) {
            if (numbers[i] < min) {
                min = numbers[i];
            }
            if (numbers[i] > max) {
                max = numbers[i];
            }
        }
        cout << "min: " << min << endl;
        cout << "max: " << max << endl;

    }
//endregion

    //region task2
    // Користувач вводить прибуток фірми за рік (12 місяців). Потім користувач вводить діапазон
    // (наприклад, 3 і 6 — пошук між третім і шостим місяцем). Необхідно визначити:
    // • місяць, у якому прибуток був максимальним,
    // • місяць, у якому прибуток був мінімальним — з урахуванням обраного діапазону.
    static void Task2Run() {
        int yearIncome[12];
            const Helpers helpers;
        for (int i = 0; i < 12; i++) {
            double income = helpers.GetDataFromUser<double>("enter income for" + to_string(i + 1) + " month");
            yearIncome[i] = income;
        }
        int startPoint = helpers.GetDataFromUser<int>("enter start point");
        int endPoint = helpers.GetDataFromUser<int>("enter end point");
        int minIncome=yearIncome[startPoint];
        int maxIncome=yearIncome[startPoint];

        for (int i = startPoint; i <= endPoint; i++) {
            if (yearIncome[i]>maxIncome) {
                maxIncome=yearIncome[i];
            }
            if (yearIncome[i]<minIncome) {
                minIncome=yearIncome[i];
            }
        }
        cout << "min: " << minIncome << endl;
        cout << "max: " << maxIncome << endl;
    }

    //endregion

    //region task3
//     Завдання 3. Обчислення на масиві дійсних чисел
// В одновимірному масиві, що складається з N дійсних чисел, обчислити:
//     • суму від'ємних елементів;
//     • добуток елементів, що розташовані між min і max елементами;
//     • добуток елементів з парними номерами;
//     • суму елементів, що розташовані між першим і останнім від'ємними елементами.
    static void Task3Run() {
        const int N = 10;

        double arr[N] = {
            4.5,   // 0
            -2.0,  // 1  (первый отрицательный)
            7.3,   // 2
            -8.1,  // 3  (min)
            5.0,   // 4
            12.4,  // 5  (max)
            -1.5,  // 6
            3.2,   // 7
            -4.7,  // 8  (последний отрицательный)
            6.6    // 9
        };
        int minIndex = 0;
        int maxIndex = 0;

        int firstNegativeIndex = N+1;
        int lastNegativeIndex = N+1;

        double sumNegative = 0;
        double sumMinMaxRange = 0;
        double multEven = 1;
        double sumFirstLastNegative = 0;

        for (int i = 0; i < N; i++) {
            if (arr[i] < arr[minIndex]) {
                minIndex = i;
            }
            if (arr[i] > arr[maxIndex]) {
                maxIndex = i;
            }

            if (arr[i] < 0 && firstNegativeIndex == N+1) {
                firstNegativeIndex = i;
            }
            if (arr[i] < 0 ) {
                lastNegativeIndex = i;
            }

            if (arr[i] < 0) {
                sumNegative += arr[i];
            }
            if (i % 2 == 0 || i==0) {
                multEven *= arr[i];
            }
        }

        for (int i = 0; i < N; i++) {
            if (minIndex<i && maxIndex>i) {
                sumMinMaxRange += arr[i];
            }
            if (firstNegativeIndex<i && lastNegativeIndex>i) {
                sumFirstLastNegative += arr[i];
            }
        }
        cout << "sum of negative elements: " << sumNegative << endl;
        cout << "sum of elements between min and max: " << sumMinMaxRange << endl;
        cout << "sum of even elements: " << multEven << endl;
        cout << "sum of elements between first and last negative elements: " << sumFirstLastNegative << endl;
    }
    //endregion

    //region task4
//     Завдання 1. Заповнення множенням на 2
// Написати програму, яка створює двовимірний масив і заповнює його за таким принципом: користувач вводить число (наприклад, 3).
//     • Перший елемент масиву приймає значення введеного числа (3).
//     • Наступний елемент = попередній × 2 (тобто 6).
//     • Третій елемент = попередній × 2 (тобто 12) і так далі.
// Створений масив вивести на екран.

    static void Task4Run() {
        const int N = 5;
        int arr[N][N] = {0};
        arr[0][0] = 3;
        for (int i = 1; i < N; i++) {
            arr[i][0] = arr[i-1][0] * 2;
            for (int j = 1; j < N; j++) {
                arr[i][j] = arr[i][j-1] * 2;
            }
        }
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                cout << arr[i][j] << " ";
            }
        cout << endl;
        }
        cout << endl;
    }
    //endregion

};
#endif //ST_C_R_ARRAYS_H