///Разработала Колосова Елена
///Класс Matrix предназначен для работы с матрицами
#pragma once
#include <string>
#include <cmath>
#include <vector>

// ДЛя работы с матрицами
class Matrix
{
private:
	//поля:

	/// матрица
	std::vector<std::vector<double> > matrix;


public:

	///Конструктор
	Matrix(std::vector<std::vector<double>> matr = { {0,0},{0,0} });

	///геттер для элемента матрицы
	///i - номер строки 
	///j -  номер столбца
	double get_element(int i, int j) const;

	///сеттер для элемента матрицы
	///i - номер строки 
	///j -  номер столбца
	///new_value - новое значение
	void set_element(int i, int j, double new_value);

	/// геттер кол-ва строк матрицы
	double get_rows() const; //const сообщает о том, что нельзя изменять поля класса

	/// геттер кол-ва столбцов матрицы
	double get_column() const; //const сообщает о том, что нельзя изменять поля класса

	///геттер матрицы
	std::vector<std::vector<double> > get_matrix() const; //const сообщает о том, что нельзя изменять поля класса

	///сеттер для кол-ва строк
	///new_value - новое кол-во строк
	void set_rows(double new_value);

	///сеттер для кол-ва столбцов
	///new_value - новое кол-во столбцов
	void set_column(double new_value);

	///сеттер для матрицы
	///new_value - новое значение матрицы
	void set_matrix(const std::vector<std::vector<double> >& new_value);

	///заполнение матрицы одним значением
	///value - значение, которму должны быть равны все элементы матрицы
	void fill_with_one_value(double value);

	///заполнение матрицы случайными числами
	///min - минимально возможное число
	///max - максимально возможное число
	void fill_random(double min, double max);

	/*///умножение матрицы на число
	friend Matrix operator*(double a);*/

	/*///number - число-множитель
	void multiplying_number(double number);*/

	///транспонировать матрицу
	void transpose();

	///сложение матриц
	Matrix operator+(const Matrix& A) const;

	/// вычитание матриц
	Matrix operator-(const Matrix& A) const;
	
	/// умножение матриц
	Matrix operator*(const Matrix& A) const;
	

};

	///вывод матрицы н аэкран
	void print_matrix(const Matrix& A);

	///проверка работы функций программы
	void test();
