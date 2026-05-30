#ifndef DATA_STRUCTURES_TASK_H
#define DATA_STRUCTURES_TASK_H

#include "../Base.h"
#include "../Shared/Helpers.h"
#include "StackTasks.h"
#include "QueueTasks.h"
#include "MatrixTask.h"

class DataStructuresTask : public Base {
public:
    void Run() override {
        const Helpers helpers;
        bool exit = false;
        while (!exit) {
            std::cout << "\n--- Data Structures and Templates Task (2026-06-13) ---\n";
            std::cout << "1. Bracket Balance (Stack)\n";
            std::cout << "2. Bus Stop Simulation (Queue)\n";
            std::cout << "3. Template Matrix\n";
            std::cout << "0. Back\n";
            int choice = helpers.GetDataFromUser<int>("Select task: ");

            switch (choice) {
                case 1: BracketChecker::Run(); break;
                case 2: BusStopSimulation::Run(); break;
                case 3: MatrixTask::Run(); break;
                case 0: exit = true; break;
                default: std::cout << "Invalid choice.\n";
            }
        }
    }
};

#endif // DATA_STRUCTURES_TASK_H
