//
// Created by Junie on 25.04.2026.
//

#ifndef ST_C_R_HOUSESIMULATIONTASK_H
#define ST_C_R_HOUSESIMULATIONTASK_H

#include "../Base.h"
#include <iostream>
#include <cstring>

class Person {
private:
    char* fullName;

public:
    Person() : fullName(nullptr) {}

    Person(const char* name) {
        if (name) {
            fullName = new char[strlen(name) + 1];
            strcpy(fullName, name);
        } else {
            fullName = nullptr;
        }
    }

    // Конструктор копіювання
    Person(const Person& other) {
        if (other.fullName) {
            fullName = new char[strlen(other.fullName) + 1];
            strcpy(fullName, other.fullName);
        } else {
            fullName = nullptr;
        }
    }

    // Оператор присвоювання
    Person& operator=(const Person& other) {
        if (this != &other) {
            delete[] fullName;
            if (other.fullName) {
                fullName = new char[strlen(other.fullName) + 1];
                strcpy(fullName, other.fullName);
            } else {
                fullName = nullptr;
            }
        }
        return *this;
    }

    ~Person() {
        delete[] fullName;
    }

    void Show() const {
        if (fullName) std::cout << fullName;
        else std::cout << "Невідомо";
    }
};

class Apartment {
private:
    Person* residents;
    int residentCount;
    int apartmentNumber;

public:
    Apartment(int number = 0) : residents(nullptr), residentCount(0), apartmentNumber(number) {}

    Apartment(int number, Person* people, int count) : apartmentNumber(number), residentCount(count) {
        if (count > 0 && people) {
            residents = new Person[count];
            for (int i = 0; i < count; ++i) {
                residents[i] = people[i];
            }
        } else {
            residents = nullptr;
            residentCount = 0;
        }
    }

    // Конструктор копіювання
    Apartment(const Apartment& other) : apartmentNumber(other.apartmentNumber), residentCount(other.residentCount) {
        if (other.residentCount > 0 && other.residents) {
            residents = new Person[other.residentCount];
            for (int i = 0; i < other.residentCount; ++i) {
                residents[i] = other.residents[i];
            }
        } else {
            residents = nullptr;
        }
    }

    // Оператор присвоювання
    Apartment& operator=(const Apartment& other) {
        if (this != &other) {
            delete[] residents;
            apartmentNumber = other.apartmentNumber;
            residentCount = other.residentCount;
            if (other.residentCount > 0 && other.residents) {
                residents = new Person[other.residentCount];
                for (int i = 0; i < other.residentCount; ++i) {
                    residents[i] = other.residents[i];
                }
            } else {
                residents = nullptr;
            }
        }
        return *this;
    }

    ~Apartment() {
        delete[] residents;
    }

    void Show() const {
        std::cout << "Квартира №" << apartmentNumber << ", мешканців: " << residentCount << std::endl;
        for (int i = 0; i < residentCount; ++i) {
            std::cout << "  - ";
            residents[i].Show();
            std::cout << std::endl;
        }
    }
};

class House {
private:
    Apartment* apartments;
    int apartmentCount;
    char* address;

public:
    House(const char* addr = nullptr) : apartments(nullptr), apartmentCount(0) {
        if (addr) {
            address = new char[strlen(addr) + 1];
            strcpy(address, addr);
        } else {
            address = nullptr;
        }
    }

    void SetApartments(Apartment* aps, int count) {
        delete[] apartments;
        apartmentCount = count;
        if (count > 0 && aps) {
            apartments = new Apartment[count];
            for (int i = 0; i < count; ++i) {
                apartments[i] = aps[i];
            }
        } else {
            apartments = nullptr;
        }
    }

    // Конструктор копіювання
    House(const House& other) : apartmentCount(other.apartmentCount) {
        if (other.address) {
            address = new char[strlen(other.address) + 1];
            strcpy(address, other.address);
        } else {
            address = nullptr;
        }

        if (other.apartmentCount > 0 && other.apartments) {
            apartments = new Apartment[other.apartmentCount];
            for (int i = 0; i < other.apartmentCount; ++i) {
                apartments[i] = other.apartments[i];
            }
        } else {
            apartments = nullptr;
        }
    }

    ~House() {
        delete[] address;
        delete[] apartments;
    }

    void Show() const {
        std::cout << "Будинок за адресою: " << (address ? address : "невідома") << std::endl;
        std::cout << "Кількість квартир: " << apartmentCount << std::endl;
        for (int i = 0; i < apartmentCount; ++i) {
            apartments[i].Show();
        }
    }
};

class HouseSimulationTask : public Base {
public:
    void Run() override {
        std::cout << "--- Завдання 2: Імітація будинку ---" << std::endl;
        
        Person p1("Іван Іваненко");
        Person p2("Марія Петренко");
        Person p3("Олександр Коваленко");
        
        Person residents1[] = { p1, p2 };
        Apartment apt1(101, residents1, 2);
        
        Person residents2[] = { p3 };
        Apartment apt2(102, residents2, 1);
        
        House myHouse("вул. Головна, 1");
        Apartment houseApts[] = { apt1, apt2 };
        myHouse.SetApartments(houseApts, 2);
        
        std::cout << "Оригінальний будинок:" << std::endl;
        myHouse.Show();
        
        std::cout << "\nТестування конструктора копіювання (House copy = myHouse):" << std::endl;
        House copy = myHouse;
        copy.Show();
    }
};

#endif //ST_C_R_HOUSESIMULATIONTASK_H
