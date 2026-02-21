//
// Created by djazi on 21.02.2026.
//

#ifndef ST_C_R_GREETING_H
#define ST_C_R_GREETING_H

#pragma once
#include <iostream>
#include <ostream>

#include "../Base.h"

class Greeting: public Base {
    public:
    Greeting(){}
    static void SayHello() {
        std::cout << "Hello from greeting!" << std::endl;
    }
    void Run() override {
        SayHello();
    }
};

#endif //ST_C_R_GREETING_H