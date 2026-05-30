#ifndef INHERITANCE_AND_EXCEPTIONS_HOMEWORK_H
#define INHERITANCE_AND_EXCEPTIONS_HOMEWORK_H

#include "../Base.h"
#include "ExceptionsTasks.h"
#include "VirtualFunctionsTask.h"
#include "AbstractClassesTask.h"
#include "TemplateInheritanceTask.h"
#include <memory>
#include <vector>

class InheritanceAndExceptionsTask : public Base {
public:
    void Run() override {
        std::cout << "--- Inheritance and Exceptions Homework ---\n" << std::endl;

        // Exceptions Task 1 & 2
        std::cout << "Task: String to Int with overflow handling" << std::endl;
        try {
            std::string s = "2147483647";
            std::cout << "Converting '" << s << "': " << StringToInt(s) << std::endl;
            s = "2147483648";
            std::cout << "Converting '" << s << "': ";
            std::cout << StringToInt(s) << std::endl;
        } catch (const std::exception& e) {
            std::cerr << "Caught: " << e.what() << std::endl;
        }

        std::cout << "\nTask: Stack with exceptions" << std::endl;
        try {
            Stack<int> stack(2);
            stack.Push(10);
            stack.Push(20);
            std::cout << "Popped: " << stack.Pop() << std::endl;
            std::cout << "Popped: " << stack.Pop() << std::endl;
            stack.Pop(); // Should throw underflow
        } catch (const std::exception& e) {
            std::cerr << "Caught: " << e.what() << std::endl;
        }

        std::cout << "\nTask: Double Linked List with exceptions" << std::endl;
        try {
            DoubleLinkedList<int> list;
            list.AddTail(1);
            list.AddTail(2);
            list.Display();
            list.RemoveTail();
            list.RemoveTail();
            list.RemoveTail(); // Should throw
        } catch (const std::exception& e) {
            std::cerr << "Caught: " << e.what() << std::endl;
        }

        // Virtual Functions Task 1
        std::cout << "\nTask: File display hierarchy" << std::endl;
        const char* filename = "test_file.txt";
        {
            std::ofstream out(filename);
            out << "Hello World!";
        }
        try {
            FileDisplayBase* displays[] = { new FileDisplayBase(), new FileDisplayASCII(), new FileDisplayBinary() };
            for (auto d : displays) {
                d->Display(filename);
                delete d;
            }
        } catch (const std::exception& e) {
            std::cerr << "Caught: " << e.what() << std::endl;
        }

        // Abstract Classes Task 1
        std::cout << "\nTask: Equations" << std::endl;
        LinearEquation lin(2, -4);
        lin.Solve();
        QuadraticEquation quad(1, -5, 6);
        quad.Solve();

        // Abstract Classes Task 2
        std::cout << "\nTask: Shapes and Serialization" << std::endl;
        std::vector<Shape*> shapes;
        shapes.push_back(new Square(0, 0, 5));
        shapes.push_back(new Rectangle(10, 10, 20, 30));
        shapes.push_back(new Circle(5, 5, 10));
        shapes.push_back(new Ellipse(0, 0, 15, 25));

        std::cout << "Original shapes:" << std::endl;
        for (auto s : shapes) s->Show();

        const char* shapeFile = "shapes.dat";
        std::ofstream ofs(shapeFile, std::ios::binary);
        if (ofs.is_open()) {
            for (auto s : shapes) s->Save(ofs);
            ofs.close();
        }

        // Load into another array
        std::vector<Shape*> loadedShapes;
        std::ifstream ifs(shapeFile, std::ios::binary);
        if (ifs.is_open()) {
            while (ifs.peek() != EOF) {
                int type;
                ifs.read((char*)&type, sizeof(type));
                Shape* s = nullptr;
                switch (type) {
                    case 1: s = new Square(); break;
                    case 2: s = new Rectangle(); break;
                    case 3: s = new Circle(); break;
                    case 4: s = new Ellipse(); break;
                }
                if (s) {
                    s->Load(ifs);
                    loadedShapes.push_back(s);
                }
            }
            ifs.close();
        }

        std::cout << "\nLoaded shapes:" << std::endl;
        for (auto s : loadedShapes) s->Show();

        for (auto s : shapes) delete s;
        for (auto s : loadedShapes) delete s;

        // Template Inheritance Task
        std::cout << "\nTask: Template Inheritance" << std::endl;
        Child2Template<int, double, std::string, char, bool, float> c2(1, 2.5, "test", 'A', true, 1.1f);
        c2.Display();
    }
};

#endif // INHERITANCE_AND_EXCEPTIONS_HOMEWORK_H
