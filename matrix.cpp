#include <iostream>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <sstream>

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
}
Matrix::Matrix()
{
  n_lin_ =0;
  n_col_=0;
  matrix =NULL;
}

//Destrutor
Matrix::~Matrix()
{
    //Desaloca toda a matriz
    if(matrix == NULL)
        std::cout << "Erro: Não foi passado um ponteiro para matriz \n";
    if(n_lin_< 1 || n_col_< 1){
        std::cout << "Erro: Parametros invalidos \n";
    }
    for(int i = 0; i < n_lin_; ++i){
        delete[] matrix[i];
    }
    delete[] matrix;

}

//construtor de copia:
Matrix::Matrix(const Matrix &outro) : n_lin_(outro.n_lin_),n_col_(outro.n_col_)
{
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
void Matrix::zeros()
{
    for (int i = 0; i < n_lin_; i++) {
        for (int j = 0; j < n_col_; j++) {
            matrix[i][j]= 0;
        }
    }
}

//Torma a matriz uma matriz identidade
void Matrix::unit()
{
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
void Matrix::ones()
{
    int i,j;
    for (i = 0; i < n_lin_; ++i) {
        for (j = 0; j < n_col_; ++j) {
            matrix[i][j] = 1;
        }
    }
}

//retorna o numero de linhas da matriz
int Matrix::getRows()
{
    int n_linhas = n_lin_;
    return n_linhas;
}

//retorna o numero de colunas da matriz
int Matrix::getCols()
{
    int n_colunas = n_col_;
    return n_colunas;
}

//sobrecarga do operador =
Matrix& Matrix::operator = (const Matrix& b)
{
    if (this == &b) return *this;

    n_lin_  = b.n_lin_;
    n_col_ = b.n_col_;

    //Desaloca a matriz corrente (o destrutor é chamado)
    delete matrix;
    //A matriz corrente é criada novamente com as dimesões novas
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

// sobrecarga do operador +=
Matrix Matrix::operator += (const Matrix& b)
{
    //testa se as dimensões são compativeis à operação
    if (n_lin_== b.n_lin_&& n_col_== b.n_col_) {
        for (int i = 0; i < b.n_lin_; i++) {
            for (int j = 0; j < b.n_col_; ++j) {
                matrix[i][j] = matrix[i][j] + b.matrix[i][j];
            }
        }
        return *this;
    }else{
      std::cout << " ERRO: Impossivel fazer a soma" << '\n';
      return *this;
    }
}

//sobrecarga do operador -=
Matrix Matrix::operator -= (const Matrix& b)
{
    //testa se as dimensões são compativeis à operação
    if (n_lin_== b.n_lin_&& n_col_== b.n_col_) {
        for (int i = 0; i < b.n_lin_; ++i) {
            for (int j = 0; j < b.n_col_; ++j) {
                matrix[i][j] = matrix[i][j] - b.matrix[i][j];
            }
        }
        return *this;
    }else{
        std::cout << " ERRO: Impossivel fazer a subtração" << '\n';
        return *this;
    }
}

//sobrecarga do operador +
Matrix Matrix::operator + (const  Matrix& b)
{
    //testa se as dimensões são compativeis à operação
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
        return *this;
    }
}

//sobrecarga do operador -
Matrix Matrix::operator - (const Matrix& b)
{
    //testa se as dimensões são compativeis à operação
    if (n_lin_== b.n_lin_&& n_col_== b.n_col_) {
        Matrix sum(n_lin_, n_col_);
        for (int i = 0; i < n_lin_; ++i) {
            for (int j = 0; j < n_col_; ++j) {
                sum.matrix[i][j] = matrix[i][j] - b.matrix[i][j];
            }
        }
        return sum;
    }else{
        std::cout << " ERRO: Impossivel fazer a subtração" << '\n';
        return *this;
    }
}

//sobrecarga do operador *
Matrix Matrix::operator * (const Matrix& b)
{
    //testa se as dimensões são compativeis à operação
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
        return *this;
    }
}



//sobrecarga do operador *=
Matrix Matrix::operator *= (const Matrix& b)
{
    //testa se as dimensões são compativeis à operação
    if (n_col_==b.n_lin_) {
        //cria-se uma matriz auxiliar para receber o resultado da operação
        Matrix sum(n_lin_, b.n_col_);

        for (int i=0;i< n_lin_;i++){
            for(int j=0; j < b.n_col_;j++){
                for (int k = 0; k < n_col_; k++) {
                    sum.matrix[i][j] = sum.matrix[i][j] + ((matrix[i][k]) * (b.matrix[k][j]));
                }
            }
        }

        //o numero de colunas da matriz corrente deve se adequar à resposta da operação
        n_col_ = b.n_col_;

        //Desaloca a matriz corrente
        delete matrix;

        //aloca a matriz corrente de acordo com as novas dimensões
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
        // A matriz corrente recebe o resultado da operação de multiplicação
        *this = sum;
        return *this;

    }else{
        std::cout << " ERRO: Impossivel fazer a multiplicação" << '\n';
        return *this;
    }
}
// sobrecarga do operador *= (para a multiplicação por escalar)
Matrix Matrix::operator *= (const double es)
{
    int i,j;
    //cada elemento é multiplicado pelo escalar
    for (i = 0; i < n_lin_; i++) {
    for ( j = 0; j < n_col_; j++) {
      matrix[i][j] = matrix[i][j] * es;
    }
  }
  return *this;
}

//sobrecarga do operador ~ (trasnposição)
Matrix Matrix::operator ~()
{
    //cria-se uma matriz auxiliar para receber o resultado da operação
    Matrix sum(n_col_, n_lin_);
    for (int i=0;i< n_lin_;i++){
        for(int j=0; j < n_col_;j++){
            sum.matrix[j][i] = matrix[i][j];
        }
    }
    //as dimensões da matriz corrente são alterados
    n_lin_ = n_col_;
    n_col_ = n_lin_;

    // a matriz corrente é desalocada
    delete matrix;
    //a matriz corrente é alocada com as novas dimensões
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
}

//sobrecarga do operador ( )
double& Matrix::operator() (int i_lin, int i_col) const
{
    if (i_lin >= n_lin_ || i_col >= n_col_)
        std::cout << "Os valores estão fora da matrix";
    std::cout <<"um \n";
    //retorna o elemento desejado
    return matrix[i_lin][i_col];
}

// sobrecarga do operador <<
std::ostream& operator<< (std::ostream& os, const Matrix& b)
{
    int i,j;
    std::string print;
    print = "Imprimindo Matriz: \n\n";
    //A string "print" recebe todos os elementos da matriz diagramados corretamente
    for (i = 0; i < b.n_lin_; ++i) {
        for (j = 0; j < b.n_col_; ++j) {
        print = print + "  " + toString(b.matrix[i][j]);
        }
        print = print + '\n';
    }
    os << print;
    return os;
}
//função auxiliar para transformar um doube em string
std::string toString(double val){
    std::stringstream ss(" ");
    ss << val;
    return ss.str();
}
