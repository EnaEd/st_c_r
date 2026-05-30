#ifndef PETS_TASK_H
#define PETS_TASK_H

#include <iostream>
#include <string>

class Pet {
protected:
    std::string name;
    std::string species;
    std::string sound;

public:
    Pet(const std::string& n, const std::string& sp, const std::string& snd)
        : name(n), species(sp), sound(snd) {}

    virtual void Show() const {
        std::cout << "Тварина: " << species << ", Ім'я: " << name << ", Звук: " << sound << std::endl;
    }

    virtual ~Pet() = default;
};

class Dog : public Pet {
public:
    Dog(const std::string& n) : Pet(n, "Собака", "Гав-гав") {}
    
    void Show() const override {
        std::cout << "[Собака] ";
        Pet::Show();
    }
};

class Cat : public Pet {
public:
    Cat(const std::string& n) : Pet(n, "Кішка", "Мяу") {}

    void Show() const override {
        std::cout << "[Кішка] ";
        Pet::Show();
    }
};

class Parrot : public Pet {
public:
    Parrot(const std::string& n) : Pet(n, "Папуга", "Кеша хороший") {}

    void Show() const override {
        std::cout << "[Папуга] ";
        Pet::Show();
    }
};

#endif // PETS_TASK_H
