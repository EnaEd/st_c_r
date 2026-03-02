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
    T GetDataFromUser(string message) const {
        T data;
        while (true) {
            cout << message;
            cin >> data;

            if (!cin.fail()) {
                return data;
            }

            cout << "Invalid input. Try again.\n";

            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }
};
#endif //ST_C_R_HELPERS_H