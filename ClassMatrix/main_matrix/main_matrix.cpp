// main_matrix.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//
#include <string>
#include <iostream>
#include "Matrix.h"
int main()
{
    test();
    //объявление матриц
    Matrix A({ {1,2,3},{4,5,6} });
    Matrix B({ {11,12,13},{14,15,16} });
    
    //пример сложения
    Matrix C = A + B;
    std::vector<std::vector<double> > m = C.get_matrix();
    for (int i = 0; i < C.get_rows(); i++) {
        for (int j = 0; j < C.get_column(); j++)
            std::cout << m[i][j] << " ";
        std::cout << std::endl;
    }
    std::cout << std::endl;

    A.transpose();

    //пример умножения
    C = B * A;
    m = C.get_matrix();
    for (int i = 0; i < C.get_rows(); i++) {
        for (int j = 0; j < C.get_column(); j++)
            std::cout << m[i][j] << " ";
        std::cout << std::endl;
    }
    std::cout << std::endl;

    /*//пример транспонирования
    A.transpose();

    m = A.get_matrix();
    for (int i = 0; i < A.get_rows(); i++) {
        for (int j = 0; j < A.get_column(); j++)
            std::cout << m[i][j] << " ";
        std::cout << std::endl;
    }
    std::cout << std::endl;


    //пример умножения на число
    A.multiplying_number(2);
    m = A.get_matrix();
    for (int i = 0; i < A.get_rows(); i++) {
        for (int j = 0; j < A.get_column(); j++)
            std::cout << m[i][j] << " ";
        std::cout << std::endl;
    }
    std::cout << std::endl;

    //пример заполнения матрицы случайными числами
    A.set_rows(2);
    A.set_column(2);
    A.fill_random(0, 10);
    m = A.get_matrix();
    for (int i = 0; i < A.get_rows(); i++) {
        for (int j = 0; j < A.get_column(); j++)
            std::cout << m[i][j] << " ";
        std::cout << std::endl;
    }
    std::cout << std::endl;

    //пример заполнения единицей
    A.fill_with_one_value(1);
    m = A.get_matrix();
    for (int i = 0; i < A.get_rows(); i++) {
        for (int j = 0; j < A.get_column(); j++)
            std::cout << m[i][j] << " ";
        std::cout << std::endl;
    }
    std::cout << std::endl;*/



}


