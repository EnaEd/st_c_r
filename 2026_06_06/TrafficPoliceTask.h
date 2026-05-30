#ifndef TRAFFIC_POLICE_TASK_H
#define TRAFFIC_POLICE_TASK_H

#include <iostream>
#include <string>
#include <vector>
#include <map>

// Реалізація через бінарне дерево пошуку (BST) для бази даних ДАІ
class TrafficPoliceDB {
private:
    struct Violation {
        std::string description;
        std::string date;
        double amount;
    };

    struct Node {
        std::string carNumber;
        std::vector<Violation> violations;
        Node* left;
        Node* right;

        Node(const std::string& number) 
            : carNumber(number), left(nullptr), right(nullptr) {}
    };

    Node* root;

    void AddViolation(Node*& node, const std::string& number, const Violation& v) {
        if (!node) {
            node = new Node(number);
            node->violations.push_back(v);
            return;
        }

        if (number == node->carNumber) {
            node->violations.push_back(v);
        } else if (number < node->carNumber) {
            AddViolation(node->left, number, v);
        } else {
            AddViolation(node->right, number, v);
        }
    }

    void PrintAll(Node* node) const {
        if (!node) return;
        PrintAll(node->left);
        PrintNode(node);
        PrintAll(node->right);
    }

    void PrintNode(Node* node) const {
        std::cout << "Авто: " << node->carNumber << std::endl;
        for (const auto& v : node->violations) {
            std::cout << "  - [" << v.date << "] " << v.description << ": " << v.amount << " грн." << std::endl;
        }
    }

    Node* Find(Node* node, const std::string& number) const {
        if (!node || node->carNumber == number) return node;
        if (number < node->carNumber) return Find(node->left, number);
        return Find(node->right, number);
    }

    void PrintRange(Node* node, const std::string& start, const std::string& end) const {
        if (!node) return;
        if (node->carNumber > start) PrintRange(node->left, start, end);
        if (node->carNumber >= start && node->carNumber <= end) PrintNode(node);
        if (node->carNumber < end) PrintRange(node->right, start, end);
    }

    void Clear(Node* node) {
        if (!node) return;
        Clear(node->left);
        Clear(node->right);
        delete node;
    }

public:
    TrafficPoliceDB() : root(nullptr) {}
    ~TrafficPoliceDB() { Clear(root); }

    void Add(const std::string& number, const std::string& desc, const std::string& date, double amount) {
        Violation v = {desc, date, amount};
        AddViolation(root, number, v);
    }

    void PrintDatabase() const {
        std::cout << "--- Повна база даних ДАІ ---" << std::endl;
        if (!root) std::cout << "База порожня." << std::endl;
        PrintAll(root);
    }

    void PrintByNumber(const std::string& number) const {
        std::cout << "--- Дані за номером: " << number << " ---" << std::endl;
        Node* node = Find(root, number);
        if (node) PrintNode(node);
        else std::cout << "Номер не знайдено." << std::endl;
    }

    void PrintByRange(const std::string& start, const std::string& end) const {
        std::cout << "--- Дані за діапазоном: " << start << " - " << end << " ---" << std::endl;
        PrintRange(root, start, end);
    }
};

#endif // TRAFFIC_POLICE_TASK_H
