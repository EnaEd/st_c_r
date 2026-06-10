// #ifndef HOMEWORK_06_06_H
// #define HOMEWORK_06_06_H
//
// #include "../Base.h"
// #include "PetsTask.h"
// #include "StringHierarchyTask.h"
// #include "ArrayContainerTask.h"
// #include "TrafficPoliceTask.h"
// #include <iostream>
//
// class InheritanceAndTemplatesTask : public Base {
// public:
//     void Run() override {
//         std::cout << "--- Inheritance and Templates Homework 2026-06-06 ---\n" << std::endl;
//
//         // Task 1: Pets
//         std::cout << ">>> Завдання 1: Домашні тварини" << std::endl;
//         Dog dog("Рекс");
//         Cat cat("Мурка");
//         Parrot parrot("Кеша");
//
//         dog.Show();
//         cat.Show();
//         parrot.Show();
//         std::cout << std::endl;
//
//         // Task 2: Strings
//         std::cout << ">>> Завдання 2: Рядки та Бітові рядки" << std::endl;
//         String s1("Hello ");
//         String s2("World");
//         String s3 = s1 + s2;
//         std::cout << "String 1: " << s1.GetCStr() << std::endl;
//         std::cout << "String 2: " << s2.GetCStr() << std::endl;
//         std::cout << "Concatenated: " << s3.GetCStr() << std::endl;
//
//         BitString bs1("1010"); // 10 decimal
//         BitString bs2("0101"); // 5 decimal
//         BitString bs3 = bs1 + bs2;
//         std::cout << "BitString 1: " << bs1.GetCStr() << std::endl;
//         std::cout << "BitString 2: " << bs2.GetCStr() << std::endl;
//         std::cout << "BitString Sum: " << bs3.GetCStr() << std::endl;
//
//         bs1.ChangeSign();
//         std::cout << "BitString 1 after ChangeSign (Two's complement): " << bs1.GetCStr() << std::endl;
//         std::cout << std::endl;
//
//         // Task 3: Array Template
//         std::cout << ">>> Завдання 3: Шаблонний контейнер Array (на списку)" << std::endl;
//         Array<int> arr;
//         arr.SetSize(5, 2);
//         std::cout << "Array size: " << arr.GetSize() << std::endl;
//         arr.Add(10);
//         arr.Add(20);
//         arr[2] = 30;
//         std::cout << "Array[0]: " << arr[0] << ", Array[1]: " << arr[1] << ", Array[2]: " << arr[2] << std::endl;
//         std::cout << "Upper bound: " << arr.GetUpperBound() << std::endl;
//         arr.RemoveAt(1);
//         std::cout << "After RemoveAt(1), Array[1]: " << arr[1] << std::endl;
//         std::cout << std::endl;
//
//         // Task 4: Traffic Police
//         std::cout << ">>> Завдання 4: База даних ДАІ (BST)" << std::endl;
//         TrafficPoliceDB db;
//         db.Add("AA1111AA", "Перевищення швидкості", "2026-05-30", 340.0);
//         db.Add("BB2222BB", "Проїзд на червоне", "2026-06-01", 510.0);
//         db.Add("AA1111AA", "Паркування в недозволеному місці", "2026-06-05", 255.0);
//         db.Add("CC3333CC", "Без ременя безпеки", "2026-06-06", 170.0);
//
//         db.PrintDatabase();
//         std::cout << std::endl;
//         db.PrintByNumber("AA1111AA");
//         std::cout << std::endl;
//         db.PrintByRange("AA0000AA", "BB9999BB");
//     }
// };
//
// #endif // HOMEWORK_06_06_H
