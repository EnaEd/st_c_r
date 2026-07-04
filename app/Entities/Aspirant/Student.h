#include <iostream>
#include <ostream>
#include <string>

class Student {
private:
    std::string _firstName;
    std::string _lastName;
    std::string _group;
    int _year;

public:
    Student(const std::string &firstName,
        const std::string &lastName,
        const std::string &group,
        const int year = 1) {
        _firstName = firstName;
        _lastName = lastName;
        _group = group;
        _year = year;
    }

    ~Student() = default;

    //properties
    std::string getFirstName() const {
        return _firstName;
    };

    void setFirstName(const std::string &firstName) {
        _firstName = firstName;
    };

    std::string getLastName() const {
        return _lastName;
    };

    void setLastName(const std::string &lastName) {
        _lastName = lastName;
    };

    std::string getGroup() const {
        return _group;
    };

    void setGroup(const std::string &group) {
        _group = group;
    };

    int getYear() const {
        return _year;
    };

    void setYear(const int year) {
        _year = year;
    };

    //methods
    void toString() const {
        std::cout << "Student: " << _firstName << " " << _lastName << " Course: " << _year << "\n";
    };
};
