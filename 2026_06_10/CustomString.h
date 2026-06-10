#include <iostream>
using namespace std;

#define uint unsigned int

class CustomString {
private:
    char* text = nullptr;
    uint length = 0;
    uint capacity = 0;

    void ensure_capacity(const char* new_text) {
        length = strlen(new_text);

        if (capacity > length) {
            return;
        }

        capacity = length* 1.5 + 1;

        this->capacity = capacity;

        delete[] this->text;
        this->text = new char[capacity];
    }

public:
    CustomString() : CustomString("", 1) {}

    CustomString(const char* text) : CustomString(text, 1) {
        this->text = new char[capacity];
        set_string(text);
    }

    CustomString(uint capacity) : CustomString("", capacity) {}

    CustomString(const CustomString& original) : CustomString(original.text, original.capacity) {}

    CustomString(const char* text, uint capacity) {
        this->text = new char[capacity];
        set_string(text, capacity);
    }

    ~CustomString() {
        if (text != nullptr) {
            delete[] text;
            text = nullptr;
        }
    }

    CustomString get_string() const {
        CustomString copy = text;
        return copy;
    }

    void set_string(const char* new_text, uint capacity = 0) {
        if (this->text == new_text) {
            return;
        }

        ensure_capacity(new_text);
        strcpy_s(this->text, length + 1, new_text);
    }

    int get_length() const {
        return length;
    }

    // методу set_length не має бути!

    int get_capacity() const {
        return capacity;
    }

    void clear() {
        text[0] = 0;
        length = 0;
    }

    void shrink_to_fit() {
        if (length + 1 <= capacity) {
            return;
        }

        capacity = length + 1;
        char* temp = new char[capacity];
        strcpy_s(temp, capacity, text);
        delete[] text;
        text = temp;
    }

    void print() const {
        cout << "text: " << text << "\n";
        cout << "length: " << length << "\n";
        cout << "memory reserve: " << capacity << "\n";
    }


    void trim_to_size()
    {
        length = strlen(this->text);

        const auto buffer = new char[capacity+1];

        strcpy_s(buffer, length + 1, text);

        delete[] this->text;

        this->text = buffer;
        this->capacity = length;
    }
};
