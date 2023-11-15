///Разработала Колосова Елена
#pragma once
#include <string>
#include <cmath>

//тип вид прогрессии
enum class ProgressionType {
	Arithmetic,
	Geometric
};

// Прогрессии
class Progression
{
private:
	//поля:

	/// первый элемент
	double FirstElem;

	///шаг прогрессии
	double Step;

	///тип прогрессии
	ProgressionType PType;

public:

	///Конструктор
	Progression(double first = 1, double StepP = 0);

	/// геттер первого элемента
	///const сообщает о том, что нельзя изменять поля класса
	double get_FirstElem() const;

	/// геттер шага прогрессии
	///const сообщает о том, что нельзя изменять поля класса
	double get_Step() const;

	///геттер типа прогрессии
	///const сообщает о том, что нельзя изменять поля класса
	ProgressionType get_PType() const;

	///сеттер для первого элемента
	void set_FirstElem(double new_value);

	///сеттер для шага прогрессии
	void set_Step(double new_value);

	///сеттер для вида прогрессии
	void set_PType(ProgressionType new_type);

	///поиск значения элемента с номером number
	double Value_n_element(int number) const;

	///поиск суммы первых quantity элементов
	double Find_the_sum(int quantity) const;

	///преобразование данных класса в строку
	std::string To_String() const;

};

///проверка правильности выполнения функций Value_n_element и Find_the_sum 
void Progression_Test();

///вывод информации о пргрессии в файл
void print_in_file(std::string FileName, Progression ProgressionName);

///заполнение данных для прогрессии из файла
void fill_from_file(std::string FileName, Progression &ProgressionName);

