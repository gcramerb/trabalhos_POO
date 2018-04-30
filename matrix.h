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
        void ones();
        void zeros();
        void unit();
        int getRows();
        int getCols();
        Matrix& operator = (const Matrix& b);
        Matrix operator + (const Matrix& b);
        Matrix operator - (const Matrix& b);
        Matrix operator * (const Matrix& b);
        Matrix operator -= (const Matrix& b);
        Matrix operator += (const Matrix& b);
        Matrix operator *= (const Matrix& b);
        Matrix operator *= (const double es);
        Matrix operator ~();
        double& operator() (int i_lin, int i_col) const;
        friend std::ostream& operator<< (std::ostream& os, const Matrix& b);
};
std::string toString(double val);

