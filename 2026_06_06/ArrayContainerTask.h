#ifndef ARRAY_CONTAINER_TASK_H
#define ARRAY_CONTAINER_TASK_H

#include <iostream>
#include <stdexcept>

template <typename T>
class Array {
private:
    struct Node {
        T data;
        Node* next;
        Node* prev;
        Node(const T& d) : data(d), next(nullptr), prev(nullptr) {}
    };

    Node* head;
    Node* tail;
    int currentSize; // Кількість фактичних елементів
    int allocatedSize; // Виділений розмір (логічний)
    int growAmount;

    void FreeNodes() {
        Node* curr = head;
        while (curr) {
            Node* next = curr->next;
            delete curr;
            curr = next;
        }
        head = tail = nullptr;
        currentSize = 0;
    }

public:
    Array() : head(nullptr), tail(nullptr), currentSize(0), allocatedSize(0), growAmount(1) {}

    ~Array() {
        FreeNodes();
    }

    int GetSize() const {
        return allocatedSize;
    }

    void SetSize(int size, int grow = 1) {
        growAmount = grow;
        if (size < currentSize) {
            // Видаляємо "зайві" елементи з кінця
            while (currentSize > size) {
                RemoveAt(currentSize - 1);
            }
        }
        allocatedSize = size;
    }

    int GetUpperBound() const {
        return currentSize - 1;
    }

    bool IsEmpty() const {
        return currentSize == 0;
    }

    void FreeExtra() {
        allocatedSize = currentSize;
    }

    void RemoveAll() {
        FreeNodes();
        allocatedSize = 0;
    }

    T GetAt(int index) const {
        if (index < 0 || index >= currentSize) {
            throw std::out_of_range("Index out of range");
        }
        Node* curr = head;
        for (int i = 0; i < index; ++i) curr = curr->next;
        return curr->data;
    }

    void SetAt(int index, const T& value) {
        if (index < 0 || index >= allocatedSize) {
            throw std::out_of_range("Index out of range");
        }
        
        // Якщо індекс в межах allocatedSize, але більше currentSize, треба додати вузли
        while (index >= currentSize) {
            Add(T()); 
        }

        Node* curr = head;
        for (int i = 0; i < index; ++i) curr = curr->next;
        curr->data = value;
    }

    T& operator[](int index) {
        if (index < 0 || index >= allocatedSize) {
            throw std::out_of_range("Index out of range");
        }
        
        while (index >= currentSize) {
            Add(T());
        }

        Node* curr = head;
        for (int i = 0; i < index; ++i) curr = curr->next;
        return curr->data;
    }

    const T& operator[](int index) const {
        return GetAt(index);
    }

    void Add(const T& value) {
        if (currentSize >= allocatedSize) {
            allocatedSize += growAmount;
        }

        Node* newNode = new Node(value);
        if (!head) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
        currentSize++;
    }

    void Append(const Array& other) {
        Node* curr = other.head;
        while (curr) {
            Add(curr->data);
            curr = curr->next;
        }
    }

    Array& operator=(const Array& other) {
        if (this != &other) {
            RemoveAll();
            allocatedSize = other.allocatedSize;
            growAmount = other.growAmount;
            Append(other);
        }
        return *this;
    }

    T* GetData() {
        // Оскільки це список, GetData (повернення адреси масиву) не має прямого сенсу.
        // Зазвичай це повертає T*. Можна було б створити тимчасовий масив, але це небезпечно.
        // Повернемо nullptr або реалізуємо як "не підтримується" для списку.
        return nullptr; 
    }

    void InsertAt(int index, const T& value) {
        if (index < 0 || index > currentSize) throw std::out_of_range("Index out of range");

        if (currentSize >= allocatedSize) {
            allocatedSize += growAmount;
        }

        Node* newNode = new Node(value);
        if (index == 0) {
            if (!head) {
                head = tail = newNode;
            } else {
                newNode->next = head;
                head->prev = newNode;
                head = newNode;
            }
        } else if (index == currentSize) {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        } else {
            Node* curr = head;
            for (int i = 0; i < index; ++i) curr = curr->next;
            newNode->prev = curr->prev;
            newNode->next = curr;
            curr->prev->next = newNode;
            curr->prev = newNode;
        }
        currentSize++;
    }

    void RemoveAt(int index) {
        if (index < 0 || index >= currentSize) throw std::out_of_range("Index out of range");

        Node* toDelete = head;
        for (int i = 0; i < index; ++i) toDelete = toDelete->next;

        if (toDelete->prev) toDelete->prev->next = toDelete->next;
        else head = toDelete->next;

        if (toDelete->next) toDelete->next->prev = toDelete->prev;
        else tail = toDelete->prev;

        delete toDelete;
        currentSize--;
    }
};

#endif // ARRAY_CONTAINER_TASK_H
