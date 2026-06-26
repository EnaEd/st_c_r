#include <iostream>

#include "Services/CarDatabase.h"
void Print(const std::optional<VehicleRecord> &record) {
    std::cout << "Print: ";
    if(record) {
        std::cout << record->ToString() << std::endl;
    }
    else {
        std::cout << "Not found" << std::endl;
    }
}

int main() {

    CarDatabase carDatabase;
    carDatabase.Add(VehicleRecord("AA112233EB", Owner("John")));
    carDatabase.Add(VehicleRecord("BB112233EB", Owner("John")));
    carDatabase.Add(VehicleRecord("CC112233EB", Owner("John")));
    carDatabase.Add(VehicleRecord("DD112233EB", Owner("John")));
    carDatabase.Add(VehicleRecord("EE112233EB", Owner("John")));
    carDatabase.Add(VehicleRecord("FF112233EB", Owner("John")));
    carDatabase.Add(VehicleRecord("GG112233EB", Owner("John")));

    auto res=carDatabase.Find("AA112233EB");
    Print(res);
    res=carDatabase.Find("ZZ112233EB");
    Print(res);
    carDatabase.Remove(VehicleRecord("AA112233EB", Owner("John")));
    res = carDatabase.Find("AA112233EB");
    Print(res);
    carDatabase.List();
}


