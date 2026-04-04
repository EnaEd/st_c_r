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
#include "2026_02_28/Arrays.h"
#include "2026_02_28/Func.h"
#include "2026_04_04/Homework.h"
#include "2026_04_04/RecursionAndGames.h"
#include "2026_04_04/PointersTask.h"
#include "2026_04_04/DynamicArraysTask.h"
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
            case TaskTheme::ArraysTask:
                return std::make_unique<Arrays>();
            case TaskTheme::FuncTask:
                return std::make_unique<Func>();
            case TaskTheme::HomeworkTask:
                return std::make_unique<Homework>();
            case TaskTheme::RecursionAndGamesTask:
                return std::make_unique<RecursionAndGames>();
            case TaskTheme::PointersTask:
                return std::make_unique<PointersTask>();
            case TaskTheme::DynamicArraysTask:
                return std::make_unique<DynamicArraysTask>();
            default: nullptr;
        }
    }
};

#endif //ST_C_R_TASKFACTORY_H
