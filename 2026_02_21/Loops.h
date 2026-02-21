//
// Created by djazi on 21.02.2026.
//

#ifndef ST_C_R_LOOPS_H
#define ST_C_R_LOOPS_H
#pragma once
#include <chrono>
#include <random>

#include "../Base.h"
class Loops: public Base {
    const Helpers helpers;
    public:
    Loops(){};
    virtual void Run() override {
        //RunTask1();
        //RunTask2();
        //RunTask3();
        //RunTask4();
        //RunTask5();
        RunTask6();
    };
    //region task1
    /*
     *  Напишіть програму, яка обчислює суму цілих чисел від а до 500
     *  (значення a вводиться з клавіатури).
     */

    void RunTask1() {
        int a = helpers.GetDataFromUser<int>("enter a number max 500:");
        cout << GetAvg(a) << endl;

    }
    double GetAvg(int a) {
        if (a == 500) {
            return 500;
        }
        int sum=0;
        for (int i = a; i <= 500; i++) {
            sum += i;
        }

        return sum/(500.0-a+1.0);
    }
    //endregion

    //region task2
    /*
     * . Знайти середнє арифметичне всіх цілих чисел від 1 до 1000.
     */
    void RunTask2() {

        cout << GetAvg(1,1000) << endl;
    }
    double GetAvg(int start, int last) {
        int sum=0;
        for (int i = start; i <= last; i++) {
            sum += i;
        }

        return sum/(last-start+1.0);
    }
    //endregion

    //region task3
    void RunTask3() {
        auto start = helpers.GetDataFromUser<int>("enter a number max 20:");
        cout << MultiplyRange(start,20) << endl;
    }

    double MultiplyRange(int start, int last) {
        double result = 1;
        for (int i = start; i <= last; i++) {
            result *= static_cast<double>(i);
        }
        return result;
    }
    //endregion

    //region task4
    /*
    * Написати програму, яка виводить на екран таблицю множення на k, де k — номер варіанта.
 Наприклад, для 7-го варіанта: 7 x 2 = 14; 7 x 3 = 21.
     */
    void RunTask4() {
        auto number = helpers.GetDataFromUser<int>("enter a number max 9:");
        PrintTable(number);
    }
    void PrintTable(int number) {
        for (int i = 1; i <= 9; i++) {
            cout << number << " x " << i << " = " << setw(2) << setfill('0') << number * i << endl;
        }
    }
    //endregion

    //region task5
    /*
     * \ Користувач вводить ціле число.
     * Необхідно вивести всі цілі числа, на які задане число ділиться без залишку.
     */
    void RunTask5() {
        int number = helpers.GetDataFromUser<int>("enter a number:");
        PrintDivisors(number);
    }
    void PrintDivisors(int number) {
        for (int i = 1; i <= number; i++) {
            if (number % i == 0) {
                cout << i << endl;
            }
        }
    }
    //endregion

    //task6
    /*
     *  Написати гру «Кубики». Користувач і комп'ютер по черзі кидають 2 кубики.
     *  Переможець той, у кого за результатами 3х кидків сума більше.
     *  Передбачити красивий інтерфейс гри
     */
    void RunTask6() {
        int playerSum=0;
        int pcSum=0;
        for (int i = 1; i <= 3; i++) {
            playerSum += ThrowCube();
            pcSum += ThrowCube();
        }
        cout << (playerSum > pcSum ? "Player win" : playerSum == pcSum ? "Drow" : "PC win") << endl;
    }
    int ThrowCube() {
        random_device rd;
        mt19937 gen(rd());
        uniform_int_distribution<> dist(1, 6);

        int result = dist(gen);
        return result;
    }


};
#endif //ST_C_R_LOOPS_H