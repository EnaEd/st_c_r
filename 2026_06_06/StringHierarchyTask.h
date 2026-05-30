#ifndef STRING_HIERARCHY_TASK_H
#define STRING_HIERARCHY_TASK_H

#include <iostream>
#include <cstring>
#include <algorithm>

class String {
protected:
    char* str;
    int length;

public:
    String() : str(nullptr), length(0) {
        str = new char[1];
        str[0] = '\0';
    }

    String(const char* s) {
        if (s) {
            length = std::strlen(s);
            str = new char[length + 1];
            std::strcpy(str, s);
        } else {
            length = 0;
            str = new char[1];
            str[0] = '\0';
        }
    }

    String(const String& other) {
        length = other.length;
        str = new char[length + 1];
        std::strcpy(str, other.str);
    }

    virtual ~String() {
        delete[] str;
    }

    String& operator=(const String& other) {
        if (this != &other) {
            delete[] str;
            length = other.length;
            str = new char[length + 1];
            std::strcpy(str, other.str);
        }
        return *this;
    }

    int GetLength() const {
        return length;
    }

    void Clear() {
        delete[] str;
        length = 0;
        str = new char[1];
        str[0] = '\0';
    }

    String operator+(const String& other) const {
        char* newStr = new char[length + other.length + 1];
        std::strcpy(newStr, str);
        std::strcat(newStr, other.str);
        String res(newStr);
        delete[] newStr;
        return res;
    }

    String& operator+=(const String& other) {
        char* newStr = new char[length + other.length + 1];
        std::strcpy(newStr, str);
        std::strcat(newStr, other.str);
        delete[] str;
        str = newStr;
        length += other.length;
        return *this;
    }

    bool operator==(const String& other) const {
        return std::strcmp(str, other.str) == 0;
    }

    bool operator!=(const String& other) const {
        return !(*this == other);
    }

    const char* GetCStr() const {
        return str;
    }
};

class BitString : public String {
public:
    BitString() : String() {}

    BitString(const char* s) : String() {
        if (s) {
            bool valid = true;
            for (int i = 0; s[i] != '\0'; ++i) {
                if (s[i] != '0' && s[i] != '1') {
                    valid = false;
                    break;
                }
            }
            if (valid) {
                delete[] str;
                length = std::strlen(s);
                str = new char[length + 1];
                std::strcpy(str, s);
            }
        }
    }

    BitString(const BitString& other) : String(other) {}

    BitString& operator=(const BitString& other) {
        String::operator=(other);
        return *this;
    }

    ~BitString() override = default;

    void ChangeSign() {
        if (length == 0) return;
        
        // Інверсія
        for (int i = 0; i < length; ++i) {
            str[i] = (str[i] == '0' ? '1' : '0');
        }
        
        // Додавання 1
        for (int i = length - 1; i >= 0; --i) {
            if (str[i] == '0') {
                str[i] = '1';
                break;
            } else {
                str[i] = '0';
            }
        }
    }

    BitString operator+(const BitString& other) const {
        // Складання бітових рядків як чисел
        int maxLen = std::max(length, other.length);
        char* resStr = new char[maxLen + 1];
        resStr[maxLen] = '\0';
        
        int carry = 0;
        for (int i = 0; i < maxLen; ++i) {
            int b1 = (i < length) ? (str[length - 1 - i] - '0') : (str[0] - '0'); // sign extension assumed
            int b2 = (i < other.length) ? (other.str[other.length - 1 - i] - '0') : (other.str[0] - '0');
            
            int sum = b1 + b2 + carry;
            resStr[maxLen - 1 - i] = (sum % 2) + '0';
            carry = sum / 2;
        }
        
        BitString res(resStr);
        delete[] resStr;
        return res;
    }

    BitString& operator+=(const BitString& other) {
        *this = *this + other;
        return *this;
    }

    bool operator==(const BitString& other) const {
        return String::operator==(other);
    }

    bool operator!=(const BitString& other) const {
        return String::operator!=(other);
    }
};

#endif // STRING_HIERARCHY_TASK_H
