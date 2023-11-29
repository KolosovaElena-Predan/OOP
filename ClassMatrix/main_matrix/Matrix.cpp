///����������� �������� �����
///����� Matrix ������������ ��� ������ � ���������
#include <cmath>
#include <iostream>
#include <assert.h>
#include <vector>
#include "Matrix.h"



///�����������
Matrix::Matrix(std::vector<std::vector<double>> matr) {
	matrix = matr;
}

///������ ��� �������� �������
///i - ����� ������ 
///j -  ����� �������
double Matrix::get_element(int i, int j) const {
	if (i < get_rows() && j < get_column()) {
		return matrix[i][j];
	}
	else throw std::invalid_argument("Invalid index value");

}

///������ ��� �������� �������
///i - ����� ������ 
///j -  ����� �������
/// new_value - ����� ��������
void Matrix::set_element(int i, int j, double new_value) {
	if (i < get_rows() && j < get_column()) {
		matrix[i][j]= new_value;
	}
	else throw std::invalid_argument("Invalid index value");
}

/// ������ ���-�� ����� �������
double Matrix::get_rows() const {
	return matrix.size();
}

/// ������ ���-�� �������� �������
double Matrix::get_column() const
{
	return matrix[0].size();
}

///������ �������
std::vector<std::vector<double> > Matrix::get_matrix() const {
	return matrix;
}

///������ ��� ���-�� �����
///new_value - ����� ���-�� �����
void Matrix::set_rows(double new_value) {
	if (new_value > 0)
		matrix.resize(new_value);
	else throw std::invalid_argument("Invalid rows count value");
}

///������ ��� ���-�� ��������
///new_value - ����� ���-�� ��������
void Matrix::set_column(double new_value) {
	if (new_value > 0) {
		for (int i=0;i<get_rows();i++)
			matrix[i].resize(new_value);
	}

	else throw std::invalid_argument("Invalid columns count value");
}

///������ ��� �������
///new_value - ����� �������� �������
void Matrix::set_matrix(std::vector<std::vector<double> > new_value) {
	matrix = new_value;
}

///���������� ������� ����� ���������
///value - ��������, ������� ������ ���� ����� ��� �������� �������
void Matrix::fill_with_one_value(double value) {
		for (int i = 0; i < matrix.size(); i++)
			for (int j = 0; j < matrix[0].size(); j++)
				matrix[i][j] = value;
	
}

///���������� ������� ���������� �������
///min - ���������� ��������� �����
///max - ����������� ��������� �����
void Matrix::fill_random(double min, double max) {
		for (int i = 0; i < matrix.size(); i++)
			for (int j = 0; j < matrix.size(); j++)
				matrix[i][j] = (double)rand() / RAND_MAX * (max-min) + min;
		;
}

/*///��������
///��������� ������� �� �����
///number - �����-���������
void Matrix::multiplying_number(double number) {
	for (int i = 0; i < matrix.size(); i++)
		for (int j = 0; j < matrix.size(); j++)
			matrix[i][j] = matrix[i][j]* number;
	;
}*/
	
///���������������� �������
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

///�������� ������
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

/// ��������� ������
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

/*///��������� ������� �� �����
///number - �����-���������
Matrix Matrix::operator*(double a)
{
	for (int i = 0; i < matrix.size(); i++)
		for (int j = 0; j < matrix[0].size(); j++)
			matrix[i][j] = matrix[i][j] * a;
}*/

/// ��������� ������
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


///����� ������� � ������
void print_matrix(Matrix& A) {
	std::vector<std::vector<double> > m = A.get_matrix();
	for (int i = 0; i < A.get_rows(); i++) {
		for (int j = 0; j < A.get_column(); j++)
			std::cout << m[i][j] << " ";
		std::cout << std::endl;
	}
	std::cout << std::endl;
}

///�������� ������ ������� ���������
void test() {
	Matrix A({ {1,2,3},{4,5,6} });

	//�������� ������ ������ get_element
	assert(A.get_element(0, 1) == 2);

	//�������� ������ ������ get_column
	assert(A.get_column() == 3);
	
	//�������� ������ ������ get_rows
	assert(A.get_rows() == 2);
	
	Matrix B;
	
	//�������� ������ ������ set_rows
	B.set_rows(2);
	assert(B.get_rows() == 2);
	
	//�������� ������ ������ set_column
	B.set_column(3);
	assert(B.get_column() == 3);

	//�������� ������ ������ fill_with_one_value
	B.fill_with_one_value(1);
	std::vector<std::vector<double> > m = { {1, 1, 1}, {1, 1, 1} };
	assert(B.get_matrix() == m);

	//�������� ������ ��������� ����� ���� ������
	Matrix C = A + B;
	m = { {2, 3, 4}, {5, 6, 7} };
	assert(C.get_matrix() == m);

	//�������� ������ ��������� ��������� ���� ������
	C = A - B;
	m = { {0, 1, 2}, {3, 4, 5} };
	assert(C.get_matrix() == m);

	//�������� ������ ������ transpose
	A.transpose();
	m = { {1,4},{2,5},{3,6} };
	assert(A.get_matrix() == m);
	
	//�������� ������ ��������� ������������ ���� ������
	C = B * A;
	m = { {6,15},{6,15} };
	assert(C.get_matrix() == m);


}

