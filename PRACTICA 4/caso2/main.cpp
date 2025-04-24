#include <iostream>
#include <thread>
#include <algorithm>
#include <vector>
#include <functional>
using namespace std;

void hacer_trabajo(unsigned id) {
    cout << id << "\n";
}

void captura(int variable) {
    vector<thread> hilos;
    for (unsigned i = 0; i < variable; i++) {
        hilos.push_back(thread(hacer_trabajo, i));
    }
    for_each(hilos.begin(), hilos.end(), mem_fn(&thread::join));
}

int main() {
    int val;
    cout << "Introduce un n�mero: ";
    cin >> val;
    captura(val);
    return 0;
}
