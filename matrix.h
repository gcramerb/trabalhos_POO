
class Matrix {
    private:
        double **matrix;
        int n_lin;
        int n_col;
    public:
        Matrix(int n_lin, int n_col);
        ~Matrix();
        void imprime_matrix();
        void ones();
        void zeros();
        void unit();
        Matrix operator + (Matrix b) const; 
        /*{
            if (n_lin == b.n_lin && n_col == b.n_col) {
                Matrix sum(b.n_lin, b.n_col);
                //sum.zeros();
                for (int i = 0; i < b.n_lin; i++) {
                    for (int j = 0; j < b.n_col; j++) {
                        sum.matrix[i][j] = matrix[i][j] + b.matrix[i][j];
                        std::cout << sum.matrix[i][j];
                    }
                std::cout << '\n';
                }
                return sum;
            }
            else{
                std::cout <<"Matrizes com dimensoes diferentes"<< '\n';
            }
        }*/
};
