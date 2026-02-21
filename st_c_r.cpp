#include "TaskFactory.h"
#include "2026_02_21/Greeting.h"
#include "Enums/Enums.h"
using namespace std;

int main() {
    /// Choose task theme to test program behavior
    /// naming rule: ThemeTask has the same Name as target class with postfix Task
    /// <sample> auto task = TaskTheme::GreetingTask; </sample>
    /// by defaulttask has pointer to lastest work
    auto taskTheme = static_cast<TaskTheme>(static_cast<int>(TaskTheme::LastOneMark) - 1);

    TaskFactory factory;
    auto task = factory.GetTask(taskTheme);
    if (task == nullptr) {
        cout << "Task theme not found\n";
        return 0;
    }
    task->Run();
}


