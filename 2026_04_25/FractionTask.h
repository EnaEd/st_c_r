//
// Created by Junie on 25.04.2026.
//

#ifndef ST_C_R_FRACTIONTASK_H
#define ST_C_R_FRACTIONTASK_H

#include "../Base.h"
#include <iostream>

class Fraction {
private:
    int numerator;
    int denominator;

    int gcd(int a, int b) {
        return b == 0 ? a : gcd(b, a % b);
    }

    void simplify() {
        if (denominator == 0) return;
        int common = gcd(abs(numerator), abs(denominator));
        numerator /= common;
        denominator /= common;
        if (denominator < 0) {
            numerator = -numerator;
            denominator = -denominator;
        }
    }

public:
    Fraction(int n = 0, int d = 1) : numerator(n), denominator(d) {
        if (denominator == 0) denominator = 1;
        simplify();
    }

    Fraction operator+(const Fraction& other) const {
        return Fraction(numerator * other.denominator + other.numerator * denominator, 
                        denominator * other.denominator);
    }

    Fraction operator-(const Fraction& other) const {
        return Fraction(numerator * other.denominator - other.numerator * denominator, 
                        denominator * other.denominator);
    }

    Fraction operator*(const Fraction& other) const {
        return Fraction(numerator * other.numerator, denominator * other.denominator);
    }

    Fraction operator/(const Fraction& other) const {
        return Fraction(numerator * other.denominator, denominator * other.numerator);
    }

    void Display() const {
        std::cout << numerator << "/" << denominator;
    }
};

class FractionTask : public Base {
public:
    void Run() override {
        std::cout << "--- Завдання 2: Клас Fraction (Дріб) ---" << std::endl;
        
        Fraction f1(1, 2);
        Fraction f2(3, 4);
        
        std::cout << "f1 = "; f1.Display(); std::cout << std::endl;
        std::cout << "f2 = "; f2.Display(); std::cout << std::endl;
        
        Fraction res;
        
        res = f1 + f2;
        std::cout << "f1 + f2 = "; res.Display(); std::cout << std::endl;
        
        res = f1 - f2;
        std::cout << "f1 - f2 = "; res.Display(); std::cout << std::endl;
        
        res = f1 * f2;
        std::cout << "f1 * f2 = "; res.Display(); std::cout << std::endl;
        
        res = f1 / f2;
        std::cout << "f1 / f2 = "; res.Display(); std::cout << std::endl;
    }
};

#endif //ST_C_R_FRACTIONTASK_H
