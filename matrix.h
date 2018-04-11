
class Matrix {
  private:
    double **matrix;
    int row;
    int col;
  public:
    Matrix(int l, int c);
    ~Matrix();
    void imprime_matrix();
    void ones();
    void zeros();
    void unit();
    /*Matrix operator+(const Matrix& b) {
      int i,j;
       Matrix box(b.row,b.col);// devo inicializar zerada ?
       if (this->row== b.row && this->col == b.col) {
         for (i = 0; i < b.row; i++) {
           for (j = 0; j < b.col; j++) { // tem que alocar essa nova matriz?
             box.matrix[i][j]== this->matrix[i][j] + b.matrix[i][j];
           }
         }
          return box;
       }else
        std::cout << "Matrizes com dimensoes diferentes" << '\n';
    }*/
  };
