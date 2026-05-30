#ifndef ABSTRACT_CLASSES_TASK_H
#define ABSTRACT_CLASSES_TASK_H

#include <iostream>
#include <vector>
#include <cmath>
#include <fstream>
#include "CustomExceptions.h"

// Завдання 1: Рівняння
class Equation {
public:
    virtual ~Equation() = default;
    virtual void Solve() const = 0;
};

class LinearEquation : public Equation {
    double a, b;
public:
    LinearEquation(double a, double b) : a(a), b(b) {}
    void Solve() const override {
        std::cout << "Solving " << a << "x + " << b << " = 0" << std::endl;
        if (a == 0) {
            if (b == 0) std::cout << "Infinite solutions" << std::endl;
            else std::cout << "No solution" << std::endl;
        } else {
            std::cout << "x = " << -b / a << std::endl;
        }
    }
};

class QuadraticEquation : public Equation {
    double a, b, c;
public:
    QuadraticEquation(double a, double b, double c) : a(a), b(b), c(c) {}
    void Solve() const override {
        std::cout << "Solving " << a << "x^2 + " << b << "x + " << c << " = 0" << std::endl;
        if (a == 0) {
            LinearEquation(b, c).Solve();
            return;
        }
        double d = b * b - 4 * a * c;
        if (d > 0) {
            std::cout << "x1 = " << (-b + sqrt(d)) / (2 * a) << ", x2 = " << (-b - sqrt(d)) / (2 * a) << std::endl;
        } else if (d == 0) {
            std::cout << "x = " << -b / (2 * a) << std::endl;
        } else {
            std::cout << "No real roots" << std::endl;
        }
    }
};

// Завдання 2: Фігури
class Shape {
public:
    virtual ~Shape() = default;
    virtual void Show() const = 0;
    virtual void Save(std::ofstream& ofs) const = 0;
    virtual void Load(std::ifstream& ifs) = 0;
};

class Square : public Shape {
    double x, y, side;
public:
    Square(double x = 0, double y = 0, double s = 0) : x(x), y(y), side(s) {}
    void Show() const override {
        std::cout << "Square: Top-Left(" << x << ", " << y << "), Side=" << side << std::endl;
    }
    void Save(std::ofstream& ofs) const override {
        int type = 1;
        ofs.write((char*)&type, sizeof(type));
        ofs.write((char*)&x, sizeof(x));
        ofs.write((char*)&y, sizeof(y));
        ofs.write((char*)&side, sizeof(side));
    }
    void Load(std::ifstream& ifs) override {
        ifs.read((char*)&x, sizeof(x));
        ifs.read((char*)&y, sizeof(y));
        ifs.read((char*)&side, sizeof(side));
    }
};

class Rectangle : public Shape {
    double x, y, w, h;
public:
    Rectangle(double x = 0, double y = 0, double w = 0, double h = 0) : x(x), y(y), w(w), h(h) {}
    void Show() const override {
        std::cout << "Rectangle: Top-Left(" << x << ", " << y << "), Width=" << w << ", Height=" << h << std::endl;
    }
    void Save(std::ofstream& ofs) const override {
        int type = 2;
        ofs.write((char*)&type, sizeof(type));
        ofs.write((char*)&x, sizeof(x));
        ofs.write((char*)&y, sizeof(y));
        ofs.write((char*)&w, sizeof(w));
        ofs.write((char*)&h, sizeof(h));
    }
    void Load(std::ifstream& ifs) override {
        ifs.read((char*)&x, sizeof(x));
        ifs.read((char*)&y, sizeof(y));
        ifs.read((char*)&w, sizeof(w));
        ifs.read((char*)&h, sizeof(h));
    }
};

class Circle : public Shape {
    double cx, cy, r;
public:
    Circle(double cx = 0, double cy = 0, double r = 0) : cx(cx), cy(cy), r(r) {}
    void Show() const override {
        std::cout << "Circle: Center(" << cx << ", " << cy << "), Radius=" << r << std::endl;
    }
    void Save(std::ofstream& ofs) const override {
        int type = 3;
        ofs.write((char*)&type, sizeof(type));
        ofs.write((char*)&cx, sizeof(cx));
        ofs.write((char*)&cy, sizeof(cy));
        ofs.write((char*)&r, sizeof(r));
    }
    void Load(std::ifstream& ifs) override {
        ifs.read((char*)&cx, sizeof(cx));
        ifs.read((char*)&cy, sizeof(cy));
        ifs.read((char*)&r, sizeof(r));
    }
};

class Ellipse : public Shape {
    double x, y, w, h;
public:
    Ellipse(double x = 0, double y = 0, double w = 0, double h = 0) : x(x), y(y), w(w), h(h) {}
    void Show() const override {
        std::cout << "Ellipse: BoundingBox Top-Left(" << x << ", " << y << "), Width=" << w << ", Height=" << h << std::endl;
    }
    void Save(std::ofstream& ofs) const override {
        int type = 4;
        ofs.write((char*)&type, sizeof(type));
        ofs.write((char*)&x, sizeof(x));
        ofs.write((char*)&y, sizeof(y));
        ofs.write((char*)&w, sizeof(w));
        ofs.write((char*)&h, sizeof(h));
    }
    void Load(std::ifstream& ifs) override {
        ifs.read((char*)&x, sizeof(x));
        ifs.read((char*)&y, sizeof(y));
        ifs.read((char*)&w, sizeof(w));
        ifs.read((char*)&h, sizeof(h));
    }
};

#endif // ABSTRACT_CLASSES_TASK_H
