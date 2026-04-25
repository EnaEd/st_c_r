//
// Created by Junie on 25.04.2026.
//

#ifndef ST_C_R_HOMEWORK_04_25_H
#define ST_C_R_HOMEWORK_04_25_H

#include "StringClassTask.h"
#include "HouseSimulationTask.h"
#include "ReservoirTask.h"
#include "FractionTask.h"

class Homework_04_25 : public Base {
public:
    void Run() override {
        StringClassTask task1;
        task1.Run();
        
        std::cout << "\n" << std::string(40, '=') << "\n" << std::endl;
        
        HouseSimulationTask task2;
        task2.Run();

        std::cout << "\n" << std::string(40, '=') << "\n" << std::endl;

        ReservoirTask task3;
        task3.Run();

        std::cout << "\n" << std::string(40, '=') << "\n" << std::endl;

        FractionTask task4;
        task4.Run();
    }
};

#endif //ST_C_R_HOMEWORK_04_25_H
