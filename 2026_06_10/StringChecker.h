#pragma once

#include <iostream>

#include "CustomString.h"
#include "../Base.h"

class StringChecker : public Base {
public:
    void Run() override {
        std::cout << "--- String checker ---\n";

        CustomString b("Alex");
        b.print();

        b.set_string("Alex");
        b.print();

        b.set_string("Ed");
        b.print();
        b.trim_to_size();
        b.print();
        b.set_string("SuperLongString");
        b.print();

        // String c(75);
        // c.print();

        // String d("Alex", 20);
        // d.print();

        // String e = d;
        // e.print();

    }
};

