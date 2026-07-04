#include "Student.h"

class Aspirant : public Student {
private:
    std::string _degreeProjectTitle;

public:
    Aspirant(const std::string &firstName,
        const std::string &lastName,
        const std::string &group,
        const std::string &degreeProjectTitle,
        const int year = 1) : Student(firstName, lastName, group, year) {
        _degreeProjectTitle = degreeProjectTitle;
    }

    ~Aspirant() = default;

//props
    std::string getDegreeProjectTitle() const {
        return _degreeProjectTitle;
    };
    void setDegreeProjectTitle(const std::string &degreeProjectTitle) {
        _degreeProjectTitle = degreeProjectTitle;
    };

//methods
    void toString() const {
        Student::toString();
        std::cout << "Degree project title: " << _degreeProjectTitle << "\n";
    };

};
