#include <iostream>
#include <string>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

//Construtor
Matrix::Matrix(int n_linhas, int n_colunas) { 
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

    n_lin = n_linhas;
    n_col = n_colunas;
    std::cout << "Construtor" << '\n';
}

//Destrutor
Matrix::~Matrix(){
    if(matrix == NULL)
        std::cout << "Erro: Não foi passado um ponteiro para matriz \n";
    if(n_lin < 1 || n_col < 1){
        std::cout << "Erro: Parametros invalidos \n";
    }
    for(int i = 0; i < n_lin; ++i){
        delete[] matrix[i];
    }
    delete[] matrix;
    std::cout << "Destruiu" << '\n';

}

//Zera todos os elementos da Matriz
void Matrix::zeros(){
    for (int i = 0; i < n_lin; i++) {
        for (int j = 0; j < n_col; j++) {
            matrix[i][j]= 0;
        }
    } 
}

//Torma a matriz uma matriz identidade
void Matrix::unit(){ 
    int i,j;
    for (i = 0; i < n_lin; i++) {
        for (j = 0; j < n_col; j++) {
            if (i == j) {
                matrix[i][j]=1;
            }
        }
    }
}

//Preenche a matriz com um em todos os elementos
void Matrix::ones(){ 
    int i,j;
    for (i = 0; i < n_lin; ++i) {
        for (j = 0; j < n_col; ++j) {
            matrix[i][j] = 1;
        }
    }
}

//Imprime a Matriz
void Matrix::imprime_matrix(){
    int i,j;
    std::cout << "Imprimindo Matriz \n";
    for (i = 0; i < n_lin; ++i) {
        for (j = 0; j < n_col; ++j) {
        std::cout << matrix[i][j];
        }
        std::cout<< '\n';
    }
}

Matrix Matrix::operator + (Matrix b) const{
    Matrix sum(b.n_lin, b.n_col);
    if (n_lin == b.n_lin && n_col == b.n_col) {
        for (int i = 0; i < b.n_lin; ++i) {
            for (int j = 0; j < b.n_col; ++j) {
                sum.matrix[i][j] = matrix[i][j] + b.matrix[i][j];
                std::cout << sum.matrix[i][j];
            }
            std::cout << '\n';
        }
        return sum;
    }else{
        return sum;
    }
}