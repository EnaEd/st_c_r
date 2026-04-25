//
// Created by Junie on 25.04.2026.
//

#ifndef ST_C_R_RESERVOIRTASK_H
#define ST_C_R_RESERVOIRTASK_H

#include "../Base.h"
#include <iostream>
#include <cstring>
#include <fstream>
#include <vector>
#include <string>

class Reservoir {
private:
    char* name;
    char* type;
    double width;
    double length;
    double maxDepth;

    void copyFrom(const Reservoir& other) {
        if (other.name) {
            name = new char[strlen(other.name) + 1];
            strcpy(name, other.name);
        } else {
            name = nullptr;
        }
        if (other.type) {
            type = new char[strlen(other.type) + 1];
            strcpy(type, other.type);
        } else {
            type = nullptr;
        }
        width = other.width;
        length = other.length;
        maxDepth = other.maxDepth;
    }

public:
    // Конструктор за замовчуванням
    Reservoir() : name(nullptr), type(nullptr), width(0), length(0), maxDepth(0) {}

    // Конструктор з параметрами (explicit для запобігання неявному перетворенню, 
    // хоча зазвичай це для 1 параметра, застосуємо для ілюстрації або якщо буде один параметр в майбутньому)
    explicit Reservoir(const char* n, const char* t, double w, double l, double d) {
        name = new char[strlen(n) + 1];
        strcpy(name, n);
        type = new char[strlen(t) + 1];
        strcpy(type, t);
        width = w;
        length = l;
        maxDepth = d;
    }

    // Конструктор копіювання
    Reservoir(const Reservoir& other) {
        copyFrom(other);
    }

    // Деструктор
    ~Reservoir() {
        delete[] name;
        delete[] type;
    }

    // Метод для копіювання об'єктів (через оператор або явний метод)
    void Copy(const Reservoir& other) {
        if (this != &other) {
            delete[] name;
            delete[] type;
            copyFrom(other);
        }
    }

    // Визначення приблизного об'єму
    double GetVolume() const {
        return width * length * maxDepth;
    }

    // Визначення площі поверхні
    double GetSurfaceArea() const {
        return width * length;
    }

    // Перевірка чи належать до одного типу
    bool IsSameType(const Reservoir& other) const {
        if (!type || !other.type) return false;
        return strcmp(type, other.type) == 0;
    }

    // Порівняння площі водойм одного типу
    int CompareSurfaceArea(const Reservoir& other) const {
        if (!IsSameType(other)) {
            std::cout << "Попередження: Водойми різних типів!" << std::endl;
        }
        double area1 = GetSurfaceArea();
        double area2 = other.GetSurfaceArea();
        if (area1 > area2) return 1;
        if (area1 < area2) return -1;
        return 0;
    }

    // Сетери та гетери
    void SetName(const char* n) {
        delete[] name;
        name = new char[strlen(n) + 1];
        strcpy(name, n);
    }

    const char* GetName() const { return name ? name : "Unknown"; }

    void SetType(const char* t) {
        delete[] type;
        type = new char[strlen(t) + 1];
        strcpy(type, t);
    }

    const char* GetType() const { return type ? type : "Unknown"; }

    void SetDimensions(double w, double l, double d) {
        width = w;
        length = l;
        maxDepth = d;
    }

    void Display() const {
        std::cout << "Назва: " << GetName() << ", Тип: " << GetType() 
                  << ", Площа: " << GetSurfaceArea() << ", Об'єм: " << GetVolume() << std::endl;
    }

    // Для роботи з файлами
    void SaveToText(std::ostream& out) const {
        out << GetName() << "\n" << GetType() << "\n" << width << " " << length << " " << maxDepth << "\n";
    }

    void LoadFromText(std::istream& in) {
        char buffer[256];
        in.getline(buffer, 256);
        SetName(buffer);
        in.getline(buffer, 256);
        SetType(buffer);
        in >> width >> length >> maxDepth;
        in.ignore(); // очистити залишок рядка
    }

    void SaveToBinary(std::ostream& out) const {
        size_t nLen = strlen(GetName());
        out.write((char*)&nLen, sizeof(nLen));
        out.write(GetName(), nLen);

        size_t tLen = strlen(GetType());
        out.write((char*)&tLen, sizeof(tLen));
        out.write(GetType(), tLen);

        out.write((char*)&width, sizeof(width));
        out.write((char*)&length, sizeof(length));
        out.write((char*)&maxDepth, sizeof(maxDepth));
    }

    void LoadFromBinary(std::istream& in) {
        size_t nLen;
        in.read((char*)&nLen, sizeof(nLen));
        char* nBuf = new char[nLen + 1];
        in.read(nBuf, nLen);
        nBuf[nLen] = '\0';
        SetName(nBuf);
        delete[] nBuf;

        size_t tLen;
        in.read((char*)&tLen, sizeof(tLen));
        char* tBuf = new char[tLen + 1];
        in.read(tBuf, tLen);
        tBuf[tLen] = '\0';
        SetType(tBuf);
        delete[] tBuf;

        in.read((char*)&width, sizeof(width));
        in.read((char*)&length, sizeof(length));
        in.read((char*)&maxDepth, sizeof(maxDepth));
    }
};

class ReservoirTask : public Base {
private:
    Reservoir* reservoirs;
    int count;

    void AddReservoir(const Reservoir& r) {
        Reservoir* temp = new Reservoir[count + 1];
        for (int i = 0; i < count; ++i) {
            temp[i].Copy(reservoirs[i]);
        }
        temp[count].Copy(r);
        delete[] reservoirs;
        reservoirs = temp;
        count++;
    }

    void RemoveReservoir(int index) {
        if (index < 0 || index >= count) return;
        Reservoir* temp = new Reservoir[count - 1];
        for (int i = 0, j = 0; i < count; ++i) {
            if (i == index) continue;
            temp[j++].Copy(reservoirs[i]);
        }
        delete[] reservoirs;
        reservoirs = temp;
        count--;
    }

public:
    ReservoirTask() : reservoirs(nullptr), count(0) {}
    ~ReservoirTask() { delete[] reservoirs; }

    void Run() override {
        std::cout << "--- Завдання 1: Клас Reservoir ---" << std::endl;
        
        AddReservoir(Reservoir("Чорне море", "море", 1148000, 580000, 2210));
        AddReservoir(Reservoir("Азовське море", "море", 340000, 231000, 14));
        AddReservoir(Reservoir("Басейн Олімпійський", "басейн", 50, 25, 3));

        std::cout << "Список водойм:" << std::endl;
        for (int i = 0; i < count; ++i) {
            std::cout << i << ". ";
            reservoirs[i].Display();
        }

        std::cout << "\nПеревірка типів та площі:" << std::endl;
        if (reservoirs[0].IsSameType(reservoirs[1])) {
            std::cout << reservoirs[0].GetName() << " та " << reservoirs[1].GetName() << " одного типу." << std::endl;
            int cmp = reservoirs[0].CompareSurfaceArea(reservoirs[1]);
            if (cmp > 0) std::cout << reservoirs[0].GetName() << " має більшу площу." << std::endl;
            else if (cmp < 0) std::cout << reservoirs[1].GetName() << " має більшу площу." << std::endl;
            else std::cout << "Площі однакові." << std::endl;
        }

        std::cout << "\nЗбереження у файли..." << std::endl;
        std::ofstream txtOut("reservoirs.txt");
        for (int i = 0; i < count; ++i) reservoirs[i].SaveToText(txtOut);
        txtOut.close();

        std::ofstream binOut("reservoirs.bin", std::ios::binary);
        for (int i = 0; i < count; ++i) reservoirs[i].SaveToBinary(binOut);
        binOut.close();

        std::cout << "Видалення другої водойми..." << std::endl;
        RemoveReservoir(1);
        for (int i = 0; i < count; ++i) {
            std::cout << i << ". ";
            reservoirs[i].Display();
        }
    }
};

#endif //ST_C_R_RESERVOIRTASK_H
