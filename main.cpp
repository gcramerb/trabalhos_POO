#include <iostream>
#include <string>
#include "matrix.h"
#include "matrix.cpp"
using namespace std;

int main(int argc, char const *argv[]) {
    Matrix m(10,10);
    Matrix m2(10,10);
    Matrix m3(10,10);
    std::cout <<" Matriz Identidade \n";
    m.unit();
    std::cout <<" Matriz de Uns \n";
    m2.ones();
    std::cout <<" Matriz de Zeros \n";
    //m3.zeros();
    std::cout <<" Soma de Matrizes \n";
    m3 = m + m2;
    std::cout << "Passou";
    m3.imprime_matrix();
    std::cout <<" FIM \n";
    delete[] &m;
    delete[] &m2;
    delete[] &m3;
}
