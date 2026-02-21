//
// Created by djazi on 21.02.2026.
//

#ifndef ST_C_R_INTROC_H
#define ST_C_R_INTROC_H
#pragma once
#include <iomanip>
#include <iostream>
#include <numeric>
#include "Shared/Helpers.h"

#include "../Base.h"


using namespace std;

class IntroC : public Base {
private:
    const int HourInSec = 60 * 60;
    const int MinInSec = 60;
    const Helpers helpers;

public:
    IntroC() {};
    virtual void Run() override {
        //RunTask1();
        //RunTask2();
        //RunTask3();
        RunTask4();
    };

    //region Task1
    void RunTask1() {
        long timeInSec = helpers.GetDataFromUser<long>("enter time in seconds: ");
        ParseTimeAndPrint(timeInSec);
    }

    void ParseTimeAndPrint(long timeInSec) {
        int hours = GetHoursWithLeftOvers(timeInSec);
        int minutes = GetMinutesWithLeftOvers(timeInSec);
        cout
                << setw(2) << setfill('0') << hours << ":"
                << setw(2) << setfill('0') << minutes << ":"
                << setw(2) << setfill('0') << timeInSec << endl;
    }

    int GetHoursWithLeftOvers(long &leftOvers) {
        if (leftOvers < HourInSec) {
            return 0;
        }
        int hours = leftOvers / HourInSec;
        leftOvers = leftOvers % HourInSec;
        return hours;
    }

    int GetMinutesWithLeftOvers(long &leftOvers) {
        if (leftOvers < MinInSec) {
            return 0;
        }
        int minutes = leftOvers / MinInSec;
        leftOvers = leftOvers % MinInSec;
        return minutes;
    }

    //endregion
    //region task2
    /*
     * Написати програму, яка обчислює, з якою швидкістю бігун пробіг дистанцію.
     * Рекомендований вигляд екрану під час виконання програми наведено нижче: ■ Обчислення швидкості бігу;
     * ■ Введіть довжину дистанції (метрів) = 1000; ■ Введіть час (мін. сек) = 3.25; ■ Дистанція: 1000 м;
     * ■ Час: 3 хв 25 сек = 205 сек; ■ Ви бігли зі швидкістю 17.56 км/год.
     */
    void RunTask2() {
        auto distance = helpers.GetDataFromUser<long>("enter distance: ");
        auto time = helpers.GetDataFromUser<double>("enter time (min.sec): ");
        MakeSomeMagic(distance, time);
    }

    void MakeSomeMagic(long distance,double time) {
        int fractions = static_cast<int>((time - std::floor(time)) * 100);
        int seconds = ((int)time)*60 + fractions;
        double speed= (distance / 1000.0) /(seconds/3600.0);

        cout << "distance: "<< distance << " m\n";
        cout << "time : "<< (int)time << "min" << fractions << "sec = " << seconds <<endl;
        cout << "speed: "<< speed << "km/h\n";
    }
    //endregion
    //region task3
    /*
     * Написати програму, яка перетворює введену користувачем
     * кількість днів на кількість повних тижнів і днів, що залишилися.
     * Наприклад, користувач ввів 17 днів, програма має вивести на екран 2 тижні і 3 дні.
     */
    void RunTask3() {
        auto days = helpers.GetDataFromUser<int>("enter days: ");
        PrepareAndPrint(days);
    }
    void PrepareAndPrint(int days) {
        if (days < 7) {
            cout << "Weeks: ";
            cout << setw(2) << setfill('0') << 0 << " ";
            cout << "Days: ";
            cout << setw(2) << setfill('0') << days << endl;
            return;
        }
        cout
        << "Weeks: " << setw(2) << setfill('0') << days/7 << " "
        << "Days: "<< setw(2) << setfill('0') << days%7 << endl;
    }
    //endregion
    //region task4
    /*
    * Користувач вводить з клавіатури ціле шестизначне число.
    * Написати програму, яка визначає, чи є введене число щасливим
    * (щасливим вважається шестизначне
    число, у якого сума перших 3 цифр дорівнює сумі других трьох цифр).
    Якщо користувач ввів НЕ шестизначне число — повідомлення про помилку.
     */
    void RunTask4() {
        auto digit = helpers.GetDataFromUser<int>("enter digit: ");
        cout << IsGoodNumber(digit) << endl;
    }
    bool IsGoodNumber(int digit) {
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
    //region task5

    //endregion


};
#endif //ST_C_R_INTROC_H
