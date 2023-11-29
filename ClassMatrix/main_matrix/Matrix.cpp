///Разработала Колосова Елена
///Класс Matrix предназначен для работы с матрицами
#include <cmath>
#include <iostream>
#include <assert.h>
#include <vector>
#include "Matrix.h"



///Конструктор
Matrix::Matrix(std::vector<std::vector<double>> matr) {
	matrix = matr;
}

///геттер для элемента матрицы
///i - номер строки 
///j -  номер столбца
double Matrix::get_element(int i, int j) const {
	if (i < get_rows() && j < get_column()) {
		return matrix[i][j];
	}
	else throw std::invalid_argument("Invalid index value");

}

///сеттер для элемента матрицы
///i - номер строки 
///j -  номер столбца
/// new_value - новое значение
void Matrix::set_element(int i, int j, double new_value) {
	if (i < get_rows() && j < get_column()) {
		matrix[i][j]= new_value;
	}
	else throw std::invalid_argument("Invalid index value");
}

/// геттер кол-ва строк матрицы
double Matrix::get_rows() const {
	return matrix.size();
}

/// геттер кол-ва столбцов матрицы
double Matrix::get_column() const
{
	return matrix[0].size();
}

///геттер матрицы
std::vector<std::vector<double> > Matrix::get_matrix() const {
	return matrix;
}

///сеттер для кол-ва строк
///new_value - новое кол-во строк
void Matrix::set_rows(double new_value) {
	if (new_value > 0)
		matrix.resize(new_value);
	else throw std::invalid_argument("Invalid rows count value");
}

///сеттер для кол-ва столбцов
///new_value - новое кол-во столбцов
void Matrix::set_column(double new_value) {
	if (new_value > 0) {
		for (int i=0;i<get_rows();i++)
			matrix[i].resize(new_value);
	}

	else throw std::invalid_argument("Invalid columns count value");
}

///сеттер для матрицы
///new_value - новое значение матрицы
void Matrix::set_matrix(std::vector<std::vector<double> > new_value) {
	matrix = new_value;
}

///заполнение матрицы одним значением
///value - значение, которму должны быть равны все элементы матрицы
void Matrix::fill_with_one_value(double value) {
		for (int i = 0; i < matrix.size(); i++)
			for (int j = 0; j < matrix[0].size(); j++)
				matrix[i][j] = value;
	
}

///заполнение матрицы случайными числами
///min - минимально возможное число
///max - максимально возможное число
void Matrix::fill_random(double min, double max) {
		for (int i = 0; i < matrix.size(); i++)
			for (int j = 0; j < matrix.size(); j++)
				matrix[i][j] = (double)rand() / RAND_MAX * (max-min) + min;
		;
}

/*///оператор
///умножение матрицы на число
///number - число-множитель
void Matrix::multiplying_number(double number) {
	for (int i = 0; i < matrix.size(); i++)
		for (int j = 0; j < matrix.size(); j++)
			matrix[i][j] = matrix[i][j]* number;
	;
}*/
	
///транспонирование матрицы
void Matrix::transpose() {
	std::vector<std::vector<double> > t;
	t.resize(matrix[0].size());
	for (int k = 0; k < matrix[0].size(); k++)
		t[k].resize(matrix.size());
	for (int i = 0; i < t.size();i++)
		for (int j = 0; j < t[0].size(); j++)
			t[i][j] = matrix[j][i];
	matrix = t;
}

///сложение матриц
Matrix Matrix::operator+(Matrix& A) const{
	if ((matrix.size() == A.get_rows()) && (matrix[0].size() == A.get_column())) {
		Matrix result = Matrix(A);
		for (int i = 0; i < result.matrix.size(); i++)
			for (int j = 0; j < result.matrix[0].size(); j++)
				result.matrix[i][j] = matrix[i][j]+ A.matrix[i][j];
		return result;
	}
	else throw std::invalid_argument("Matrices have different sizes");
}

/// вычитание матриц
Matrix Matrix::operator-(Matrix& A) const {
	if ((matrix.size() == A.get_rows()) && (matrix[0].size() == A.get_column())) {
		Matrix result = Matrix(A);
		for (int i = 0; i < result.matrix.size(); i++)
			for (int j = 0; j < result.matrix[0].size(); j++)
				result.matrix[i][j] = matrix[i][j] - A.matrix[i][j];
		return result;
	}
	else throw std::invalid_argument("Matrices have different sizes");
}

/*///умножение матрицы на число
///number - число-множитель
Matrix Matrix::operator*(double a)
{
	for (int i = 0; i < matrix.size(); i++)
		for (int j = 0; j < matrix[0].size(); j++)
			matrix[i][j] = matrix[i][j] * a;
}*/

/// умножение матриц
Matrix Matrix::operator*(Matrix& A) const {
	if (matrix[0].size() == A.get_rows()) {
		Matrix result = Matrix(A);
		result.set_rows(matrix.size());
		for (int i = 0; i < matrix.size(); i++)
			for (int j = 0; j < A.matrix[0].size(); j++) {
				result.matrix[i][j] = 0;
				for (int k = 0; k < matrix[0].size(); k++)
					result.matrix[i][j] += matrix[i][k] * A.matrix[k][j];
			}
		return result;
	}
	else throw std::invalid_argument("Matrices have invalid sizes");
}


///вывод матрицы н аэкран
void print_matrix(Matrix& A) {
	std::vector<std::vector<double> > m = A.get_matrix();
	for (int i = 0; i < A.get_rows(); i++) {
		for (int j = 0; j < A.get_column(); j++)
			std::cout << m[i][j] << " ";
		std::cout << std::endl;
	}
	std::cout << std::endl;
}

///проверка работы функций программы
void test() {
	Matrix A({ {1,2,3},{4,5,6} });

	//проверка работы метода get_element
	assert(A.get_element(0, 1) == 2);

	//проверка работы метода get_column
	assert(A.get_column() == 3);
	
	//проверка работы метода get_rows
	assert(A.get_rows() == 2);
	
	Matrix B;
	
	//проверка работы метода set_rows
	B.set_rows(2);
	assert(B.get_rows() == 2);
	
	//проверка работы метода set_column
	B.set_column(3);
	assert(B.get_column() == 3);

	//проверка работы метода fill_with_one_value
	B.fill_with_one_value(1);
	std::vector<std::vector<double> > m = { {1, 1, 1}, {1, 1, 1} };
	assert(B.get_matrix() == m);

	//проверка работы оператора суммы двух матриц
	Matrix C = A + B;
	m = { {2, 3, 4}, {5, 6, 7} };
	assert(C.get_matrix() == m);

	//проверка работы оператора вычитания двух матриц
	C = A - B;
	m = { {0, 1, 2}, {3, 4, 5} };
	assert(C.get_matrix() == m);

	//проверка работы метода transpose
	A.transpose();
	m = { {1,4},{2,5},{3,6} };
	assert(A.get_matrix() == m);
	
	//проверка работы оператора произведения двух матриц
	C = B * A;
	m = { {6,15},{6,15} };
	assert(C.get_matrix() == m);


}

