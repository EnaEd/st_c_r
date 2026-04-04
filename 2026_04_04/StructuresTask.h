//
// Created by Junie on 04.04.2026.
//

#ifndef ST_C_R_STRUCTURESTASK_H
#define ST_C_R_STRUCTURESTASK_H
#pragma once

#include "../Base.h"
#include "../Shared/Helpers.h"
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <iomanip>

using namespace std;

struct Complex {
    double real;
    double imag;

    Complex operator+(const Complex& other) const {
        return {real + other.real, imag + other.imag};
    }

    Complex operator-(const Complex& other) const {
        return {real - other.real, imag - other.imag};
    }

    Complex operator*(const Complex& other) const {
        return {real * other.real - imag * other.imag, real * other.imag + imag * other.real};
    }

    Complex operator/(const Complex& other) const {
        double denom = other.real * other.real + other.imag * other.imag;
        if (denom == 0) return {0, 0};
        return {(real * other.real + imag * other.imag) / denom, (imag * other.real - real * other.imag) / denom};
    }

    void Print() const {
        cout << real << (imag >= 0 ? " + " : " - ") << abs(imag) << "i";
    }
};

struct Car {
    double length;
    double clearance;
    double engineVolume;
    double enginePower;
    double wheelDiameter;
    string color;
    string gearboxType;

    void Input() {
        const Helpers helpers;
        length = helpers.GetDataFromUser<double>("Введіть довжину: ");
        clearance = helpers.GetDataFromUser<double>("Введіть кліренс: ");
        engineVolume = helpers.GetDataFromUser<double>("Введіть об'єм двигуна: ");
        enginePower = helpers.GetDataFromUser<double>("Введіть потужність двигуна: ");
        wheelDiameter = helpers.GetDataFromUser<double>("Введіть діаметр коліс: ");
        cout << "Введіть колір: ";
        cin >> color;
        cout << "Введіть тип коробки передач: ";
        cin >> gearboxType;
    }

    void Display() const {
        cout << "Автомобіль: Довжина=" << length << ", Кліренс=" << clearance 
             << ", Об'єм=" << engineVolume << ", Потужність=" << enginePower 
             << ", Діаметр коліс=" << wheelDiameter << ", Колір=" << color 
             << ", КПП=" << gearboxType << endl;
    }
};

struct Book {
    string title;
    string author;
    string publisher;
    string genre;

    void Display() const {
        cout << left << setw(20) << title << setw(20) << author << setw(20) << publisher << setw(15) << genre << endl;
    }
};

class StructuresTask : public Base {
public:
    StructuresTask() {}

    void Run() override {
        const Helpers helpers;
        bool exit = false;
        while (!exit) {
            cout << "\n--- Structures Task Menu ---\n";
            cout << "1. Завдання 1 (Комплексні числа)\n";
            cout << "2. Завдання 2 (Структура Автомобіль)\n";
            cout << "3. Завдання 3 (Бібліотека)\n";
            cout << "0. Вихід\n";
            int choice = helpers.GetDataFromUser<int>("Ваш вибір: ");

            switch (choice) {
                case 1: Task1Run(); break;
                case 2: Task2Run(); break;
                case 3: Task3Run(); break;
                case 0: exit = true; break;
                default: cout << "Невірний вибір.\n";
            }
        }
    }

private:
    void Task1Run() {
        const Helpers helpers;
        Complex c1, c2;
        cout << "Введіть дійсне та уявне значення першого комплексного числа (через пробіл): ";
        cin >> c1.real >> c1.imag;
        cout << "Введіть дійсне та уявне значення другого комплексного числа (через пробіл): ";
        cin >> c2.real >> c2.imag;

        cout << "Сума: "; (c1 + c2).Print(); cout << endl;
        cout << "Різниця: "; (c1 - c2).Print(); cout << endl;
        cout << "Множення: "; (c1 * c2).Print(); cout << endl;
        cout << "Ділення: "; (c1 / c2).Print(); cout << endl;
    }

    void Task2Run() {
        Car myCar;
        myCar.Input();
        myCar.Display();
    }

    void Task3Run() {
        const Helpers helpers;
        Book library[10] = {
            {"The Hobbit", "J.R.R. Tolkien", "George Allen & Unwin", "Fantasy"},
            {"1984", "George Orwell", "Secker & Warburg", "Dystopian"},
            {"The Great Gatsby", "F. Scott Fitzgerald", "Charles Scribner's Sons", "Classic"},
            {"Moby Dick", "Herman Melville", "Richard Bentley", "Adventure"},
            {"War and Peace", "Leo Tolstoy", "The Russian Messenger", "Historical Novel"},
            {"Brave New World", "Aldous Huxley", "Chatto & Windus", "Science Fiction"},
            {"Crime and Punishment", "Fyodor Dostoevsky", "The Russian Messenger", "Psychological Thriller"},
            {"The Odyssey", "Homer", "Unknown", "Epic Poetry"},
            {"Don Quixote", "Miguel de Cervantes", "Francisco de Robles", "Satire"},
            {"Pride and Prejudice", "Jane Austen", "T. Egerton", "Romance"}
        };

        bool exit = false;
        while (!exit) {
            cout << "\n--- Бібліотека ---\n";
            cout << "1. Редагувати книгу\n";
            cout << "2. Друк усіх книг\n";
            cout << "3. Пошук за автором\n";
            cout << "4. Пошук за назвою\n";
            cout << "5. Сортування за назвою\n";
            cout << "6. Сортування за автором\n";
            cout << "7. Сортування за видавництвом\n";
            cout << "0. Повернутися\n";
            int choice = helpers.GetDataFromUser<int>("Ваш вибір: ");

            switch (choice) {
                case 1: {
                    int idx = helpers.GetDataFromUser<int>("Введіть номер книги для редагування (0-9): ");
                    if (idx >= 0 && idx < 10) {
                        cout << "Введіть нову назву: "; cin >> library[idx].title;
                        cout << "Введіть нового автора: "; cin >> library[idx].author;
                        cout << "Введіть нове видавництво: "; cin >> library[idx].publisher;
                        cout << "Введіть новий жанр: "; cin >> library[idx].genre;
                    } else {
                        cout << "Невірний індекс.\n";
                    }
                    break;
                }
                case 2: {
                    cout << left << setw(20) << "Назва" << setw(20) << "Автор" << setw(20) << "Видавництво" << setw(15) << "Жанр" << endl;
                    cout << "----------------------------------------------------------------------------\n";
                    for (const auto& book : library) book.Display();
                    break;
                }
                case 3: {
                    string author;
                    cout << "Введіть автора: "; cin >> author;
                    for (const auto& book : library) if (book.author.find(author) != string::npos) book.Display();
                    break;
                }
                case 4: {
                    string title;
                    cout << "Введіть назву: "; cin >> title;
                    for (const auto& book : library) if (book.title.find(title) != string::npos) book.Display();
                    break;
                }
                case 5: {
                    sort(begin(library), end(library), [](const Book& a, const Book& b) { return a.title < b.title; });
                    cout << "Відсортовано за назвою.\n";
                    break;
                }
                case 6: {
                    sort(begin(library), end(library), [](const Book& a, const Book& b) { return a.author < b.author; });
                    cout << "Відсортовано за автором.\n";
                    break;
                }
                case 7: {
                    sort(begin(library), end(library), [](const Book& a, const Book& b) { return a.publisher < b.publisher; });
                    cout << "Відсортовано за видавництвом.\n";
                    break;
                }
                case 0: exit = true; break;
                default: cout << "Невірний вибір.\n";
            }
        }
    }
};

#endif //ST_C_R_STRUCTURESTASK_H
