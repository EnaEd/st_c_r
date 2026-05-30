#ifndef MATRIX_TASK_H
#define MATRIX_TASK_H

#include <iostream>
#include <vector>
#include <random>
#include <ctime>
#include <iomanip>
#include <type_traits>

template <typename T>
class Matrix {
private:
    T** data;
    int rows;
    int cols;

    void Allocate() {
        data = new T*[rows];
        for (int i = 0; i < rows; ++i) {
            data[i] = new T[cols]();
        }
    }

    void Free() {
        if (data) {
            for (int i = 0; i < rows; ++i) {
                delete[] data[i];
            }
            delete[] data;
            data = nullptr;
        }
    }

public:
    Matrix(int r, int c) : rows(r), cols(c) {
        Allocate();
    }

    Matrix(const Matrix& other) : rows(other.rows), cols(other.cols) {
        Allocate();
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                data[i][j] = other.data[i][j];
            }
        }
    }

    Matrix& operator=(const Matrix& other) {
        if (this != &other) {
            Free();
            rows = other.rows;
            cols = other.cols;
            Allocate();
            for (int i = 0; i < rows; ++i) {
                for (int j = 0; j < cols; ++j) {
                    data[i][j] = other.data[i][j];
                }
            }
        }
        return *this;
    }

    ~Matrix() {
        Free();
    }

    void FillFromKeyboard() {
        std::cout << "Enter matrix elements (" << rows << "x" << cols << "):" << std::endl;
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                std::cout << "[" << i << "][" << j << "]: ";
                std::cin >> data[i][j];
            }
        }
    }

    template <typename U = T>
    typename std::enable_if<std::is_integral<U>::value>::type
    FillRandomImpl(T minVal, T maxVal) {
        std::mt19937 rng(static_cast<unsigned>(time(nullptr)));
        std::uniform_int_distribution<T> dist(minVal, maxVal);
        for (int i = 0; i < rows; ++i)
            for (int j = 0; j < cols; ++j)
                data[i][j] = dist(rng);
    }

    template <typename U = T>
    typename std::enable_if<std::is_floating_point<U>::value>::type
    FillRandomImpl(T minVal, T maxVal) {
        std::mt19937 rng(static_cast<unsigned>(time(nullptr)));
        std::uniform_real_distribution<T> dist(minVal, maxVal);
        for (int i = 0; i < rows; ++i)
            for (int j = 0; j < cols; ++j)
                data[i][j] = dist(rng);
    }

public:
    void FillRandom(T minVal, T maxVal) {
        FillRandomImpl(minVal, maxVal);
    }

    void Display() const {
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                std::cout << std::setw(8) << data[i][j] << " ";
            }
            std::cout << std::endl;
        }
    }

    T FindMax() const {
        T maxV = data[0][0];
        for (int i = 0; i < rows; ++i)
            for (int j = 0; j < cols; ++j)
                if (data[i][j] > maxV) maxV = data[i][j];
        return maxV;
    }

    T FindMin() const {
        T minV = data[0][0];
        for (int i = 0; i < rows; ++i)
            for (int j = 0; j < cols; ++j)
                if (data[i][j] < minV) minV = data[i][j];
        return minV;
    }

    Matrix operator+(const Matrix& other) const {
        if (rows != other.rows || cols != other.cols) throw std::invalid_argument("Size mismatch");
        Matrix res(rows, cols);
        for (int i = 0; i < rows; ++i)
            for (int j = 0; j < cols; ++j)
                res.data[i][j] = data[i][j] + other.data[i][j];
        return res;
    }

    Matrix operator-(const Matrix& other) const {
        if (rows != other.rows || cols != other.cols) throw std::invalid_argument("Size mismatch");
        Matrix res(rows, cols);
        for (int i = 0; i < rows; ++i)
            for (int j = 0; j < cols; ++j)
                res.data[i][j] = data[i][j] - other.data[i][j];
        return res;
    }

    Matrix operator*(const Matrix& other) const {
        if (cols != other.rows) throw std::invalid_argument("Dimension mismatch for multiplication");
        Matrix res(rows, other.cols);
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < other.cols; ++j) {
                res.data[i][j] = 0;
                for (int k = 0; k < cols; ++k) {
                    res.data[i][j] += data[i][k] * other.data[k][j];
                }
            }
        }
        return res;
    }

    Matrix operator/(T scalar) const {
        if (scalar == 0) throw std::invalid_argument("Division by zero");
        Matrix res(rows, cols);
        for (int i = 0; i < rows; ++i)
            for (int j = 0; j < cols; ++j)
                res.data[i][j] = data[i][j] / scalar;
        return res;
    }
    
    int GetRows() const { return rows; }
    int GetCols() const { return cols; }
};

class MatrixTask {
public:
    static void Run() {
        int r, c;
        std::cout << "Enter matrix rows and cols: ";
        std::cin >> r >> c;
        Matrix<int> m1(r, c);
        m1.FillRandom(1, 100);
        std::cout << "Matrix 1 (Random):" << std::endl;
        m1.Display();

        Matrix<int> m2(r, c);
        m2.FillRandom(1, 10);
        std::cout << "Matrix 2 (Random):" << std::endl;
        m2.Display();

        std::cout << "Max in M1: " << m1.FindMax() << ", Min: " << m1.FindMin() << std::endl;

        std::cout << "M1 + M2:" << std::endl;
        (m1 + m2).Display();

        std::cout << "M1 - M2:" << std::endl;
        (m1 - m2).Display();

        if (m1.GetCols() == m2.GetRows()) {
             std::cout << "M1 * M2:" << std::endl;
             (m1 * m2).Display();
        }

        std::cout << "M1 / 2:" << std::endl;
        (m1 / 2).Display();
    }
};

#endif // MATRIX_TASK_H
