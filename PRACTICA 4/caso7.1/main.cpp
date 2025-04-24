#include <iostream>
#include <thread>
using namespace std;

class Task {
public:
    static void test(string command) {
        for (int i = 0; i < 5; i++) {
            cout << command << " :: " << i << endl;
        }
    }
};

int main() {
    std::thread th(&Task::test, "Usando funciones estáticas");
    th.join();
    return 0;
}
