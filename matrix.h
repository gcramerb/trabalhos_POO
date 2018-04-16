
class Matrix {
    private:
        double **matrix;
        int n_lin;
        int n_col;
    public:
        Matrix(int n_lin, int n_col);
        ~Matrix();
        Matrix(const Matrix &outro);
        void imprime_matrix();
        void ones();
        void zeros();
        void unit();
        int getRows();
        int getCols();
        Matrix operator = (Matrix& b) const;
        Matrix& operator + (Matrix& b) const;
        Matrix operator - (Matrix& b) const;
        Matrix operator * (Matrix& b) const;
        Matrix operator -= (Matrix& b) const;
        Matrix operator += (Matrix& b) const;
        Matrix operator *= (Matrix& b) const;
};
