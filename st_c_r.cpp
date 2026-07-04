#include <iostream>
#include <ostream>

#include "app/Entities/Aspirant/Aspirant.h"
//TODO EE: Question Как правильно подключать файлі чтобі не біло циркулярніх зависимостей как в єтом случае.
// получаю ошибку 'ambiguous symbol Student' если раскоментировать подключение файла студента
//#include "app/Entities/Aspirant/Student.h"

using namespace std;

int main() {
    cout<<"Hello World!"<<endl;
    const Student student("John", "Doe", "CS-1", 1);
    student.toString();
    const Aspirant aspirant("Jane", "Doe", "CS-2", "Degree Project", 2);
    aspirant.toString();
}


