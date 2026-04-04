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
#include "2026_04_04/StringsTask.h"
#include "2026_04_04/Dynamic2DArraysTask.h"
#include "Enums/Enums.h"

class TaskFactory {
public:
    TaskFactory(){};
    ~TaskFactory(){};

    std::unique_ptr<Base> GetTask(TaskTheme theme) {
        switch (theme) {
            case GreetingTask:
                return std::make_unique<Greeting>();
            case IntroCTask:
                return std::make_unique<IntroC>();
            case LoopsTask:
                return std::make_unique<Loops>();
            case ArraysTask:
                return std::make_unique<Arrays>();
            case FuncTask:
                return std::make_unique<Func>();
            case HomeworkTask:
                return std::make_unique<Homework>();
            case RecursionAndGamesTask:
                return std::make_unique<RecursionAndGames>();
            case PointersTask:
                return std::make_unique<class PointersTask>();
            case DynamicArraysTask:
                return std::make_unique<class DynamicArraysTask>();
            case StringsTask:
                return std::make_unique<class StringsTask>();
            case Dynamic2DArraysTask:
                return std::make_unique<class Dynamic2DArraysTask>();
            default: nullptr;
        }
    }
};

#endif //ST_C_R_TASKFACTORY_H
