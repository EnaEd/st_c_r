//
// Created by djazi on 21.02.2026.
//

#ifndef ST_C_R_BASE_H
#define ST_C_R_BASE_H
class   Base {
public:
    Base(){}
    virtual void Run() = 0;
    virtual ~Base() = default;
};
#endif //ST_C_R_BASE_H