//
// Created by djazi on 21.02.2026.
//

#ifndef ST_C_R_HELPERS_H
#define ST_C_R_HELPERS_H
#include <string>
using namespace std;

class Helpers {
    public:
    Helpers() {}
    template<typename T>
    T GetDataFromUser(std::string message) const {
        T data;
        do {
            cout << message;
            cin >> data;
        } while (cin.fail());

        return data;
    }
};
#endif //ST_C_R_HELPERS_H