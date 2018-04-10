#include <iostream>
#include <string>
#include "matrix.h"
#include "matrix.cpp"
using namespace std;

int main(int argc, char const *argv[]) {
  Matrix m(10,10);
  m.imprime_matrix();
  return 0;
}
