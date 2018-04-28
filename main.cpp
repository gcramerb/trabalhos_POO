#include <iostream>
#include <string>
#include "matrix.h"
#include "matrix.cpp"
using namespace std;

int main(int argc, char const *argv[]) {
    Matrix m(10,10);
    Matrix m2(10,10);
    Matrix m3(10,10);
    Matrix m4(10,10);
    //std::cout <<" Matriz Identidade \n";
    m.unit();
    //std::cout <<" Matriz de Uns \n";
    m2.ones();
    //std::cout <<" Matriz de Zeros \n";
    m3.zeros();
    m4.ones();
    //std::cout <<" Soma de Matrizes \n";
    //std::cout << "Passou _ 1\n";
    m3.imprime_matrix();
    m = m2 + m4;  // PROBLEMAS COM PASSAGEM POR COPIA DA MATRIZ
    m.imprime_matrix();
    /*
    std::cout << "Passou _ 2\n";
    m += m2;
    std::cout << "Imprime m3 \n";
    m3.imprime_matrix();
    std::cout << "Imprime m\n";
    m.imprime_matrix();
    std::cout <<" FIM \n";
    delete[] &m;
    delete[] &m2;
    delete[] &m3;
    delete  &m4;
    */
}
