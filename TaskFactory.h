//
// Created by djazi on 21.02.2026.
//

#ifndef ST_C_R_TASKFACTORY_H
#define ST_C_R_TASKFACTORY_H
#pragma once

#include "Base.h"
#include "2026_02_21/Greeting.h"
#include "2026_02_21/IntroC.h"
#include "2026_02_21/Loops.h"
#include "Enums/Enums.h"

class TaskFactory {
public:
    TaskFactory(){};
    ~TaskFactory(){};

    std::unique_ptr<Base> GetTask(TaskTheme theme) {
        switch (theme) {
            case TaskTheme::GreetingTask:
                return std::make_unique<Greeting>();
            case TaskTheme::IntroCTask:
                return std::make_unique<IntroC>();
            case TaskTheme::LoopsTask:
                return std::make_unique<Loops>();
            default: nullptr;
        }
    }
};

#endif //ST_C_R_TASKFACTORY_H
