#pragma once
#include <string>

class Owner {
private:
    std::string _firstName;
    std::string _middleName;
    std::string _lastName;
public:
    explicit Owner(const std::string &firstName = "", const std::string &middleName = "", const std::string &lastName ="") {
        _firstName = firstName;
        _middleName = middleName;
        _lastName = lastName;
    }

    std::string getFirstName() {
        return _firstName;
    }

    void setFirstName(const std::string &firstName) {
        _firstName = firstName;
    }

    std::string getMiddleName() {
        return _middleName;
    }
    void setMiddleName(const std::string &middleName) {
        _middleName = middleName;
    }

    std::string getLastName() {
        return _lastName;
    }
    void setLastName(const std::string &lastName) {
        _lastName = lastName;
    }

    std::string getFullName() const {
        return _firstName + " " + _middleName + " " + _lastName;
    }
};

