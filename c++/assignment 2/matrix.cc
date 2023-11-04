#include <iostream>
using namespace std;

class Matrix {
private:
    int** data;
    int rows;
    int cols;

public:
    Matrix(int numRows, int numCols) : rows(numRows), cols(numCols) {
        data = new int*[rows];
        for (int i = 0; i < rows; ++i) {
            data[i] = new int[cols];
            for (int j = 0; j < cols; ++j) {
                data[i][j] = 0;  // Initialize elements to 0
            }
        }
    }

    ~Matrix() {
        for (int i = 0; i < rows; ++i) {
            delete[] data[i];
        }
        delete[] data;
    }

    void setElement(int row, int col, int value) {
        data[row][col] = value;
    }

    int getElement(int row, int col) const {
        return data[row][col];
    }

    int getRows() const {
        return rows;
    }

    int getCols() const {
        return cols;
    }

    // Friend function to overload * operator for scalar multiplication
    friend Matrix operator*(int scalar, const Matrix& mat);

    // Display function
    void display() const {
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                cout << data[i][j] << " ";
            }
            cout << endl;
        }
    }
};

// Overloading * operator for scalar multiplication (friend function)
Matrix operator*(int scalar, const Matrix& mat) {
    Matrix result(mat.rows, mat.cols);
    for (int i = 0; i < mat.rows; ++i) {
        for (int j = 0; j < mat.cols; ++j) {
            result.data[i][j] = mat.data[i][j] * scalar;
        }
    }
    return result;
}

int main() {
    Matrix mat(3, 3);
    mat.setElement(0, 0, 1);
    mat.setElement(0, 1, 2);
    mat.setElement(0, 2, 3);
    mat.setElement(1, 0, 4);
    mat.setElement(1, 1, 5);
    mat.setElement(1, 2, 6);
    mat.setElement(2, 0, 7);
    mat.setElement(2, 1, 8);
    mat.setElement(2, 2, 9);

    cout << "Original Matrix:" << endl;
    mat.display();

    int scalar = 5;
    Matrix result = scalar * mat; // Scalar multiplication

    cout << "Matrix after scalar multiplication:" << endl;
    result.display();

    return 0;
}
