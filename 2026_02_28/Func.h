//
// Created by djazi on 02.03.2026.
//

#ifndef ST_C_R_FUNC_H
#define ST_C_R_FUNC_H
#pragma once
#include <ostream>

#include "../Base.h"
class Func: public Base {
public:
    Func(){}
    void Run() override {
        //Task1Run();
        //Task2Run();
        //Task5Run();
        Task6Run();
    };

    //region Task1
//     . Написати функцію, яка приймає два параметри: основа степеня і показник степеня, та обчислює
// степінь числа на основі отриманих даних.
    static void Task1Run() {
        constexpr double base = 2;
        constexpr double exponent = 3;
        cout << Power(base, exponent) << endl;
    }

    static double Power(double base, double exponent) {
        return pow(base, exponent);
    }
    //endregion

    //region task2
//     Написати функцію, яка отримує в якості
// параметрів 2 цілих числа та повертає суму чисел із діапазону між ними.
    static void Task2Run() {
        cout << SumRange(1, 5) << endl;
    }

    static int SumRange(int start, int end) {
        int sum = 0;
        for (int i = start; i <= end; i++) {
            sum += i;
        }
        return sum;
    }
    //endregion

    //region task5
    // Написати функцію, що визначає, чи є «щасливим» шестизначне число.
    static void Task5Run() {
        cout << IsGoodNumber(123321) << endl;
    }

    static bool IsGoodNumber(int digit) {
        int firstPart=digit/1000;
        int secondPart=digit%1000;
        int firstList[3];
        int secondList[3];

        for (int i =0;i<3;i++) {
            firstList[i]=firstPart%10;
            secondList[i]=secondPart%10;

            firstPart=firstPart/10;
            secondPart=secondPart/10;
        }
        auto fSum=accumulate(firstList, firstList+3, 0);
        auto sSum=accumulate(secondList, secondList+3, 0);

        return fSum==sSum;
    }
    //endregion

    //region task6

    static void Task6Run() {
        cout << BinaryToDecimal("1000") << endl;
    }

    static int BinaryToDecimal(const string& binary)
    {
        int decimal = 0;
        int power = 0;

        for (int i = binary.length() - 1; i >= 0; i--)
        {
            if (binary[i] == '1')
                decimal += pow(2, power);
            else if (binary[i] != '0')
                throw invalid_argument("Invalid binary number");

            power++;
        }

        return decimal;
    }
    //endregion
};
#endif //ST_C_R_FUNC_H