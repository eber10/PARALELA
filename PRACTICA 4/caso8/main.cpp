#include <iostream>
#include <fstream>
#include <thread>
using namespace std;

void generaarchivo() {
    std::ofstream outfile("NombreArchivo.TXT");
    outfile << "Nombre del archivo \n";
    outfile.close();
}

int main() {
    std::thread nombre(generaarchivo);
    nombre.join();
    return 0;
}
