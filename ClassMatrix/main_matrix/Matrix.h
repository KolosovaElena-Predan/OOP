///����������� �������� �����
///����� Matrix ������������ ��� ������ � ���������
#pragma once
#include <string>
#include <cmath>
#include <vector>

// ��� ������ � ���������
class Matrix
{
private:
	//����:

	/// �������
	std::vector<std::vector<double> > matrix;


public:

	///�����������
	Matrix(std::vector<std::vector<double>> matr = { {0,0},{0,0} });

	///������ ��� �������� �������
	///i - ����� ������ 
	///j -  ����� �������
	double get_element(int i, int j) const;

	///������ ��� �������� �������
	///i - ����� ������ 
	///j -  ����� �������
	///new_value - ����� ��������
	void set_element(int i, int j, double new_value);

	/// ������ ���-�� ����� �������
	double get_rows() const; //const �������� � ���, ��� ������ �������� ���� ������

	/// ������ ���-�� �������� �������
	double get_column() const; //const �������� � ���, ��� ������ �������� ���� ������

	///������ �������
	std::vector<std::vector<double> > get_matrix() const; //const �������� � ���, ��� ������ �������� ���� ������

	///������ ��� ���-�� �����
	///new_value - ����� ���-�� �����
	void set_rows(double new_value);

	///������ ��� ���-�� ��������
	///new_value - ����� ���-�� ��������
	void set_column(double new_value);

	///������ ��� �������
	///new_value - ����� �������� �������
	void set_matrix(const std::vector<std::vector<double> >& new_value);

	///���������� ������� ����� ���������
	///value - ��������, ������� ������ ���� ����� ��� �������� �������
	void fill_with_one_value(double value);

	///���������� ������� ���������� �������
	///min - ���������� ��������� �����
	///max - ����������� ��������� �����
	void fill_random(double min, double max);

	/*///��������� ������� �� �����
	friend Matrix operator*(double a);*/

	/*///number - �����-���������
	void multiplying_number(double number);*/

	///��������������� �������
	void transpose();

	///�������� ������
	Matrix operator+(const Matrix& A) const;

	/// ��������� ������
	Matrix operator-(const Matrix& A) const;
	
	/// ��������� ������
	Matrix operator*(const Matrix& A) const;
	

};

	///����� ������� � ������
	void print_matrix(const Matrix& A);

	///�������� ������ ������� ���������
	void test();
