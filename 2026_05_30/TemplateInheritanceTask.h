#ifndef TEMPLATE_INHERITANCE_TASK_H
#define TEMPLATE_INHERITANCE_TASK_H

#include <iostream>

template <typename T1, typename T2>
class BaseTemplate {
protected:
    T1 value1;
    T2 value2;
public:
    BaseTemplate(T1 v1, T2 v2) : value1(v1), value2(v2) {
        std::cout << "BaseTemplate constructor" << std::endl;
    }
    virtual ~BaseTemplate() {
        std::cout << "BaseTemplate destructor" << std::endl;
    }
    virtual void Display() const {
        std::cout << "Value1: " << value1 << ", Value2: " << value2 << std::endl;
    }
};

template <typename T1, typename T2, typename T3, typename T4>
class ChildTemplate : public BaseTemplate<T1, T2> {
protected:
    T3 value3;
    T4 value4;
public:
    ChildTemplate(T1 v1, T2 v2, T3 v3, T4 v4) 
        : BaseTemplate<T1, T2>(v1, v2), value3(v3), value4(v4) {
        std::cout << "ChildTemplate constructor" << std::endl;
    }
    ~ChildTemplate() {
        std::cout << "ChildTemplate destructor" << std::endl;
    }
    void Display() const override {
        BaseTemplate<T1, T2>::Display();
        std::cout << "Value3: " << value3 << ", Value4: " << value4 << std::endl;
    }
};

template <typename T1, typename T2, typename T3, typename T4, typename T5, typename T6>
class Child2Template : public ChildTemplate<T1, T2, T3, T4> {
protected:
    T5 value5;
    T6 value6;
public:
    Child2Template(T1 v1, T2 v2, T3 v3, T4 v4, T5 v5, T6 v6) 
        : ChildTemplate<T1, T2, T3, T4>(v1, v2, v3, v4), value5(v5), value6(v6) {
        std::cout << "Child2Template constructor" << std::endl;
    }
    ~Child2Template() {
        std::cout << "Child2Template destructor" << std::endl;
    }
    void Display() const override {
        ChildTemplate<T1, T2, T3, T4>::Display();
        std::cout << "Value5: " << value5 << ", Value6: " << value6 << std::endl;
    }
};

#endif // TEMPLATE_INHERITANCE_TASK_H
