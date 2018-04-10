#include <iostream>
#include <string>
//#include "matrix.h"
using namespace std;

// implementação dos métodos
Matrix::Matrix(int lin, int c) {
  row=lin;
  col=c;
  std::cout << "alocar a Matrix" << '\n';
}
Matrix::~Matrix(){
  std::cout << "destruiu" << '\n';
}
void Matrix::imprime_matrix(){
  int i,j;
  for (i = 0; i < row ; i++) {
    for (j = 0; j < col ; j++) {
      std::cout << "0";
    }
    std::cout<< '\n';
  }
}
