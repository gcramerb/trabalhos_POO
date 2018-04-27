
class Matrix {
    private:
        double **matrix;
        int n_lin_;
        int n_col_;
    public:
        Matrix(int n_lin, int n_col);
        Matrix();
        ~Matrix();
        Matrix(const Matrix &);
        void imprime_matrix();
        void ones();
        void zeros();
        void unit();
        int getRows();
        int getCols();
        void operator = (Matrix& b) const;
        Matrix Matrix::operator + (const Matrix& b)const;
        Matrix operator - (Matrix& b) const;
        Matrix operator * (Matrix& b) const;
        Matrix operator -= (Matrix& b) const;
        Matrix operator += (Matrix& b) const;
        Matrix operator *= (Matrix& b) const;
};
