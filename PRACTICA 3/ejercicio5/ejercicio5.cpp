#include <iostream>
#include <thread>
#include <chrono>

using namespace std;

void proceso(int id) {
    for(int i = 1; i <= 3; i++) {
        int espera = 100 + (rand() % 400);
        this_thread::sleep_for(chrono::milliseconds(espera));
        cout << "Proceso " << id << " - Ejec " << i << " (esperó " << espera << "ms)\n";
    }
}

int main() {
    thread t1(proceso, 1);
    thread t2(proceso, 2);
    thread t3(proceso, 3);

    t1.join();
    t2.join();
    t3.join();

    cout << "Todos los procesos terminaron\n";
    return 0;
}
