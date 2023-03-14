#include <iostream>
using namespace::std;


class Matrix {
    private:
        int row;
        int col;
        char** matrix;

        Matrix(int r, int c);
        ~Matrix();
        int operator()(int row, int col);
        bool operator==(const Matrix& other) const;
        Matrix operator-(const Matrix& other) const;
        Matrix operator+(const Matrix& other) const;
        Matrix operator*(const Matrix& other) const;
        Matrix copy(const Matrix& other) const;
        friend Matrix transpose(const Matrix& matrix);
        friend void print(const Matrix& matrix);

};

Matrix::Matrix(int r, int c) {
    row = r;
    col = c;
    matrix = new char*[r];

    for (int i = 0; i < row; i++)
    {
        matrix[i] = new char[col];
    };
};

Matrix::~Matrix() {
    for (size_t i = 0; i < row; i++)
    {
        delete[i] matrix;
    }

    delete[] matrix;
    matrix = nullptr;
    col = 0;
    row = 0;
};

bool Matrix::operator==(const Matrix& other) const {
    for (int i = 0; i < row; i++)
    {
        for (int p = 0; p < col; p++) {
            if (matrix[i][p] != other.matrix[i][p]) {
                return false;
            }
        };
    };

    return true;
};

Matrix Matrix::operator+(const Matrix& other) const {
    Matrix newMatrix(row, col);

 for (int i = 0; i < row; i++)
    {
        for (int p = 0; p < col; p++) {
            newMatrix.matrix[i][p] = matrix[i][p] + other.matrix[i][p];
        };
    };

    return newMatrix;
};

Matrix Matrix::copy(const Matrix& other) const {
    Matrix newMatrix(row, col);

    for (int i = 0; i < row; i++)
    {
        for (int p = 0; p < col; p++) {
            newMatrix.matrix[i][p] = matrix[i][p] + other.matrix[i][p];
        };
    };

    return newMatrix;
};

Matrix Matrix::operator-(const Matrix& other) const {
    Matrix newMatrix(row, col);
    for (int i = 0; i < row; i++)
    {
        for (int p = 0; p < col; p++) {
            newMatrix.matrix[i][p] = matrix[i][p] - other.matrix[i][p];
        };
    };

    return newMatrix;
};


Matrix Matrix::operator*(const Matrix& other) const {

    if (row != other.row && col != other.col) {

      throw std::exception("");
    }

    Matrix newMatrix(row, col);
    for (int i = 0; i < row; i++)
    {
        for (int p = 0; p < col; p++) {
            newMatrix.matrix[i][p] = matrix[i][p] * other.matrix[i][p];
        };
    };

    return newMatrix;
};

int Matrix::operator()(int row, int col) {
    return matrix[row][col];
};

Matrix transpose(const Matrix& matrix)
{
    Matrix newMatrix(matrix.col, matrix.row);

    for (int i = 0; i < matrix.row; i++)
    {
        for (int p = 0; p < matrix.col; p++) {
            newMatrix.matrix[i][p] = matrix.matrix[p][i];
        };
    };

    return newMatrix;
}

void print(const Matrix& matrix)
{
    for (int i = 0; i < matrix.row; i++)
    {
        for (int p = 0; p < matrix.col; p++) {
            cout << matrix.matrix[i][p] << " ";
        };

        cout << endl;
    };
}


int main()
{
    std::cout << "Hello World!\n";
}

