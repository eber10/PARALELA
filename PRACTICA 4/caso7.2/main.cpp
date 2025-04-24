#include <iostream>
#include <thread>
#include <string>
#include <chrono>

using namespace std;

class Saludador {
    public:
        Saludador(string mens, int retardo, int veces);
    Saludador();
    void run();

    string mens;
    int retardo, veces;
};
Saludador::Saludador(string mens, int retardo, int veces) {
        this->mens = mens;
        this->retardo = retardo;
        this->veces = veces;
};
Saludador::Saludador() {
        mens = "";
        retardo = 0;
        veces = 0;
};
void Saludador::run() {
        for (int i = 1; i <= veces; i++) {
            cout << mens + "\n";
            this_thread::sleep_for(chrono::milliseconds(retardo));
        }
};

int main() {

    Saludador s1("Mensaje 1", 100, 20),
              s2("Mensaje 2", 150, 15),
              s3("Mensaje 3", 10, 40);

    Saludador s4;
    s4.mens = {\t\t\t"Mensaje 4", 2,12};
    cout<<" veces : "<<s4.veces <<"\n";

    thread th_1 = thread (&Saludador::run, &s1); // Puntero al objeto s1
    thread th_2 = thread (&Saludador::run, &s2);
    thread th_3 = thread (&Saludador::run, &s3);
    thread th_4 = thread (&Saludador::run, &s4);

    th_1.join();
    th_2.join();
    th_3.join();
    th_4.join();

    return 0;
}
