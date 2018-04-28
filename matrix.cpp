#include <iostream>
#include <string>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

//Construtor
Matrix::Matrix(int n_linhas, int n_colunas):n_lin_(n_linhas),n_col_(n_colunas)
 {
    //Alocação dinamica da matriz
    if(n_linhas < 1 || n_colunas < 1){
        std::cout << "Erro: Parametros invalidos \n";
    }
    matrix = new double *[n_linhas];
    if(matrix == NULL){
        std::cout << "Erro: Memoria Insuficiente - Linhas \n";
    }
    for(int i = 0; i < n_linhas; i++){
        matrix[i] = new double [n_colunas];
        if(matrix == NULL){
            std::cout << "Erro: Memoria Insuficiente - Colunas \n";
        }
    }
    //Todos os termos iguais a Zero
    for (int i = 0; i < n_linhas; i++) {
        for (int j = 0; j < n_colunas; j++) {
            matrix[i][j] = 0;
        }
    }
    std::cout << "Construtor" << '\n';
}
Matrix::Matrix(){
  n_lin_ =0;
  n_col_=0;
  matrix =NULL;
}

//Destrutor
Matrix::~Matrix(){
    if(matrix == NULL)
        std::cout << "Erro: Não foi passado um ponteiro para matriz \n";
    if(n_lin_< 1 || n_col_< 1){
        std::cout << "Erro: Parametros invalidos \n";
    }
    for(int i = 0; i < n_lin_; ++i){
        delete[] matrix[i];
    }
    delete[] matrix;
    std::cout << "Destruiu" << '\n';

}
Matrix::Matrix(const Matrix &outro) : n_lin_(outro.n_lin_),n_col_(outro.n_col_)
{
  std::cout << "-------------------Construtor de cópia ! ----------------" << '\n';
  //Alocação dinamica da matriz
  //if(outro.n_lin_< 1 || outro.n_col_< 1){
    //  std::cout << "Erro: Parametros invalidos \n";
  //}
  this->matrix = new double *[outro.n_lin_];
  if(this->matrix == NULL){
      std::cout << "Erro: Memoria Insuficiente - Linhas \n";
  }
  for(int i = 0; i < outro.n_lin_; i++){
      this->matrix[i] = new double [outro.n_col_];
      if(this->matrix == NULL){
          std::cout << "Erro: Memoria Insuficiente - Colunas \n";
      }
  }
  int i,j;
  for (i = 0; i < outro.n_lin_; i++) {
    for (j = 0; j < outro.n_col_; j++) {
      matrix[i][j]=outro.matrix[i][j];
    }
  }


}

//Zera todos os elementos da Matriz
void Matrix::zeros(){
    for (int i = 0; i < n_lin_; i++) {
        for (int j = 0; j < n_col_; j++) {
            matrix[i][j]= 0;
        }
    }
}

//Torma a matriz uma matriz identidade
void Matrix::unit(){
    int i,j;
    for (i = 0; i < n_lin_; i++) {
        for (j = 0; j < n_col_; j++) {
            if (i == j) {
                matrix[i][j]=1;
            }else
              matrix[i][j]=0;
        }
    }
}

//Preenche a matriz com um em todos os elementos
void Matrix::ones(){
    int i,j;
    for (i = 0; i < n_lin_; ++i) {
        for (j = 0; j < n_col_; ++j) {
            matrix[i][j] = 1;
        }
    }
}

//Imprime a Matriz
void Matrix::imprime_matrix(){
    int i,j;
    std::cout << "Imprimindo Matriz \n";
    for (i = 0; i < n_lin_; ++i) {
        for (j = 0; j < n_col_; ++j) {
        std::cout << matrix[i][j];
        }
        std::cout<< '\n';
    }
}

int Matrix::getRows(){
    int n_linhas = n_lin_;
    return n_linhas;
}


int Matrix::getCols(){
    int n_colunas = n_col_;
    return n_colunas;
}


Matrix& Matrix::operator = (const Matrix& b) {
    if (this == &b) return *this;
    
    n_lin_  = b.n_lin_;
    n_col_ = b.n_col_;
    
    delete matrix;

    matrix = new double *[n_lin_];
    if(matrix == NULL){
        std::cout << "Erro: Memoria Insuficiente - Linhas \n";
    }
    for(int i = 0; i < n_lin_; i++){
        matrix[i] = new double [n_col_];
        if(matrix == NULL){
            std::cout << "Erro: Memoria Insuficiente - Colunas \n";
        }
    }
    for (int i = 0; i < b.n_lin_; ++i) {
            for (int j = 0; j < b.n_col_; ++j) {
              matrix[i][j] = b.matrix[i][j];
            }
        }
    return *this;
}

Matrix Matrix::operator += (Matrix& b) const{
    if (n_lin_== b.n_lin_&& n_col_== b.n_col_) {
        for (int i = 0; i < b.n_lin_; i++) {
            for (int j = 0; j < b.n_col_; ++j) {
                matrix[i][j] = matrix[i][j] + b.matrix[i][j];
            }
        }
        return *this;
    }else{
      std::cout << " ERRO: Impossivel fazer a soma" << '\n';
    }
}
Matrix Matrix::operator -= (Matrix& b) const{
    if (n_lin_== b.n_lin_&& n_col_== b.n_col_) {
        for (int i = 0; i < b.n_lin_; ++i) {
            for (int j = 0; j < b.n_col_; ++j) {
                matrix[i][j] = matrix[i][j] - b.matrix[i][j];
            }
        }
        return *this;
    }else{
      std::cout << " ERRO: Impossivel fazer a subtração" << '\n';
    }
}





Matrix Matrix::operator + ( Matrix& b)const{
    if (n_lin_== b.n_lin_&& n_col_== b.n_col_) {
        Matrix sum(n_lin_, n_col_);
        for (int i = 0; i < n_lin_; i++) {
          for (int j = 0; j < n_col_; j++) {
                sum.matrix[i][j] = matrix[i][j] + b.matrix[i][j];
          }
        }
        return sum;
    }else{
      std::cout << " ERRO: Impossivel fazer a soma" << '\n';
    }
}

Matrix Matrix::operator - (Matrix& b) const{
    if (n_lin_== b.n_lin_&& n_col_== b.n_col_) {
        Matrix sum(n_lin_, n_col_);
        for (int i = 0; i < n_lin_; ++i) {
            for (int j = 0; j < n_col_; ++j) {
                sum.matrix[i][j] = matrix[i][j] - b.matrix[i][j];
            }
            std::cout << '\n';
        }
        return sum;
    }else{
        std::cout << " ERRO: Impossivel fazer a subtração" << '\n';
    }
}

Matrix Matrix::operator * (Matrix& b) const{
    if (n_col_==b.n_lin_) {
        Matrix sum(n_lin_, b.n_col_);
        for (int i=0;i< n_lin_;i++){
            for(int j=0; j < b.n_col_;j++){
                for (int k = 0; k < n_col_; k++) {
                    sum.matrix[i][j] = sum.matrix[i][j] + ((matrix[i][k]) * (b.matrix[k][j]) );
                }
            }
        }
        return sum;
    }else{
        std::cout << " ERRO: Impossivel fazer a multiplicação" << '\n';
    }
}




Matrix Matrix::operator *= (const Matrix& b) {
    if (n_col_==b.n_lin_) {
        Matrix sum(n_lin_, b.n_col_);

        for (int i=0;i< n_lin_;i++){
            for(int j=0; j < b.n_col_;j++){
                for (int k = 0; k < n_col_; k++) {
                    sum.matrix[i][j] = sum.matrix[i][j] + ((matrix[i][k]) * (b.matrix[k][j]));
                }
            }
        }

        n_col_ = b.n_col_;
        
        delete matrix;
        
        matrix = new double *[n_lin_];
        if(matrix == NULL){
            std::cout << "Erro: Memoria Insuficiente - Linhas \n";
        }
        for(int i = 0; i < n_lin_; i++){
            matrix[i] = new double [n_col_];
            if(matrix == NULL){
                std::cout << "Erro: Memoria Insuficiente - Colunas \n";
            }
        }

        *this = sum;

        return *this;

    }else{
        std::cout << " ERRO: Impossivel fazer a multiplicação" << '\n';
    }
}
