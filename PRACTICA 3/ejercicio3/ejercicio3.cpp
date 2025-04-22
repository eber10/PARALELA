
#include <iostream>
#include <chrono>
#include <thread>

using namespace std;

void independentThread(){
    cout << "Empezando el hilo concurrente.\n";
    std::this_thread::sleep_for(std::chrono::seconds(2));
    cout << "Saliendo del hilo concurrente.\n";

}

void threadCaller(){
    std::cout << "Empezando e llamar al hilo.\n";
    std::thread t(independentThread);
    t.detach();
    std::this_thread::sleep_for(std::chrono::seconds(1));
    std::cout << "Saliendo de la llamada al hilo.\n";

}

int main(){
    threadCaller();
    std::this_thread::sleep_for(std::chrono::seconds(5));
    return 0;
}
