#include <iostream>
#include <string>
#include "matrix.h"
#include "matrix.cpp"
using namespace std;

int main(int argc, char const *argv[]) {
    Matrix m(10,10);
    Matrix m2(10,10);
    Matrix m3(10,10);
    m.ones();
    m2.unit();
    m3.zeros();
    //m3=m+m2;
    //std::cout << m << '\n';
    m3.imprime_matrix();
    return 0;
}
