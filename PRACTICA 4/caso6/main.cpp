v\#include <iostream>
#include <thread>
using namespace std;

class Task {
public:
    void execute(string command) {
        for (int i = 0; i < 5; i++) {
            cout << command << " :: " << i << "\n";
        }
    }
};

int main() {
    Task *taskPtr = new Task();
    std::thread th(&Task::execute, taskPtr, "Ejecutando trabajo");
    th.join();
    delete taskPtr;
    return 0;
}
