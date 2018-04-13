#include <iostream>
#include <string>
#include <stdio.h>
#include <stdlib.h>
//#include "matrix.h"
using namespace std;

// implementação dos métodos
Matrix::Matrix(int lin, int c) {
    row=lin;
    col=c;
    std::cout << "alocar a Matrix ?" << '\n';
}
Matrix::~Matrix(){
    int i;
    std::cout << "destruiu" << '\n';
    for (i=0; i<row; i++)
        free (matrix[i]); /* libera as linhas da matriz */
    free (matrix);
}
void Matrix::zeros(){ // será do tipo void ou tipo double **
    int i,j;
    matrix = (double **) calloc (row, sizeof(double *));
    /* aloca as colunas da matriz */
    for ( i = 0; i < row; i++ ) {
        matrix[i] = (double*) calloc (col, sizeof(double));
        }
}
void Matrix::unit(){ // será do tipo void ou tipo double **
    int i,j;
    matrix = (double **) calloc (row, sizeof(double *));
    /* aloca as colunas da matriz */
    for ( i = 0; i < row; i++ ) {
        matrix[i] = (double*) calloc (col, sizeof(double));
        }
        for (i = 0; i < row; i++) {
            for (j = 0; j < col; j++) {
            if (i==j) {
                matrix[i][j]=1;
            }
            }
        }
}
void Matrix::ones(){ // será do tipo void ou tipo double **
    int i,j;
    matrix = (double **) calloc (row, sizeof(double *));
    /*if (matrix == NULL) {
        cout<<"** Erro: Memoria Insuficiente **"<< '\n';
        return (NULL);
    }*/
    /* aloca as colunas da matriz */
    for ( i = 0; i < row; i++ ) {
        matrix[i] = (double*) calloc (col, sizeof(double));
        /*  if (matrix[i] == NULL) {
            cout<<"** Erro: Memoria Insuficiente **"<<'\n';
            return (NULL);
        }*/
        }
    for (size_t i = 0; i < row; i++) {
        for (size_t j = 0; j < col; j++) {
        matrix[i][j]=1;
        }
    }
}
    /*
    std::ostream& operator<<(std::ostream& os, const Matrix& obj)
    {
        os << obj.matrix[0][0];
        return os;
    }*/
void Matrix::imprime_matrix(){
    int i,j;
    for (i = 0; i < row ; i++) {
        for (j = 0; j < col ; j++) {
        std::cout << matrix[i][j];
        }
        std::cout<< '\n';
    }
}
