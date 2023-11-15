///Разработала Колосова Елена
#include <string>
#include <fstream>
#include <cmath>
#include <iostream>
#include <assert.h>
#include "Progression.h"
//#include "Progression.h"



	///Конструктор
	Progression::Progression(double first, double StepP) {
		FirstElem = first;
		Step = StepP;
		PType = ProgressionType::Arithmetic;
	}

	/// геттер первого элемента
	///const сообщает о том, что нельзя изменять поля класса
	double Progression::get_FirstElem() const{
		return FirstElem;
	}

	/// геттер шага прогрессии
	///const сообщает о том, что нельзя изменять поля класса
	double Progression::get_Step() const{
		return Step;
	}

	///геттер типа прогрессии
	///const сообщает о том, что нельзя изменять поля класса
	ProgressionType Progression::get_PType() const{
		return PType;
	}

	///сеттер для первого элемента
	void Progression::set_FirstElem(double new_value) {
		FirstElem = new_value;
	}

	///сеттер для шага прогрессии
	void Progression::set_Step(double new_value) {    //шаг геом.прогресии не должен быть равен 0 и 1
		Step = new_value;
	}

	///сеттер для вида прогрессии
	void Progression::set_PType(ProgressionType new_type) {
		PType = new_type;
	}

	///поиск значения элемента с номером number
	double Progression::Value_n_element(int number) const{             
		if (PType == ProgressionType::Arithmetic)
			return FirstElem + Step * (number - 1);

		else
				return FirstElem * pow(Step, number - 1);


	}

	///поиск суммы первых quantity элементов
	double Progression::Find_the_sum(int quantity) const{
		if (PType == ProgressionType::Arithmetic) 
			return (2 * FirstElem + Step * (quantity - 1)) / 2.0 * quantity;

		else
			if (Step==1) {
				return FirstElem* quantity;
			}
			else 
				return (FirstElem * (pow(Step, quantity) - 1)) / (Step - 1);
				
	}

	///преобразование данных класса в строку
	std::string Progression::To_String() const{
		if (PType == ProgressionType::Arithmetic)
			return "Arithmetic " + std::to_string(Step) + " " + std::to_string(FirstElem);
		else
			return "Geometric " + std::to_string(Step) + " " + std::to_string(FirstElem);
	}

	///проверка правильности выполнения функций Value_n_element и Find_the_sum 
	void Progression_Test() {

		Progression P; 
		
		//1 проверка с целыми числами арифметической прогрессии
		P.set_FirstElem(1);
		P.set_Step(1);
		assert(P.Find_the_sum(3)==6);
		assert(P.Value_n_element(4) == 4);

		//2 проверка с вещественными числами арифметической прогрессии
		P.set_FirstElem(2.3);
		P.set_Step(0.93);
		assert(P.Find_the_sum(5) == 20.8);
		assert(P.Value_n_element(3) == 4.16);

		//3 проверка с отрицательными вещественными числами арифметической прогрессии
		P.set_FirstElem(-2.3);
		P.set_Step(-0.93);
		assert(P.Find_the_sum(6) == -27.75);
		assert(P.Value_n_element(7) == -7.88);

		//1 проверка с целыми числами геометрической прогрессии
		P.set_FirstElem(1);
		P.set_Step(2);
		P.set_PType(ProgressionType::Geometric);
		assert(P.Find_the_sum(3) == 7);
		assert(P.Value_n_element(4) == 8);

		//2 проверка с вещественными числами геометрической прогрессии
		P.set_FirstElem(2.3);
		P.set_Step(0.93);
		assert(P.Find_the_sum(5) - 9.99881 < 0.00001);
		assert(P.Value_n_element(3) == 1.98927);

		//3 проверка с отрицательными вещественными числами геометрической прогрессии
		P.set_FirstElem(-2.3);
		P.set_Step(-0.93);
		assert(abs(P.Find_the_sum(6) - ( - 0.42068)) < 0.00001);
		assert(abs(P.Value_n_element(7) - ( - 1.48807)) < 0.00001);


	}


	///вывод информации о пргрессии в файл
	void print_in_file(std::string FileName, Progression ProgressionName) {
		std::fstream file;
		file.open(FileName);
		if (file.is_open()) {
			file.seekg(0);
			file<<ProgressionName.To_String();
		}
		else
			throw std::invalid_argument("File not found");
		file.close();
	}


	///заполнение данных для прогрессии из файла
	void fill_from_file(std::string FileName, Progression &ProgressionName) {
		std::fstream file;
		std::string s; //содержит строку, считанную с файла
		std::string s1;
		file.open(FileName);
		if (file.is_open()) {
			file.seekg(0);
			std::getline(file, s);
			int i = 0;
			while (s[i] != ' ') {
				s1 = s1 + s[i];
				i = i + 1;
			}
			if (s1 == "Arithmetic")
				ProgressionName.set_PType(ProgressionType::Arithmetic);
			else ProgressionName.set_PType(ProgressionType::Geometric);
			i = i + 1;
			s1 = "";
			while (s[i] != ' ') {
				s1 = s1 + s[i];
				i = i + 1;
			}
			float m = stof(s1);
			ProgressionName.set_Step(m);
			i = i + 1;
			s1 = "";
			while (s[i] != '\0') {
				s1 = s1 + s[i];
				i = i + 1;
			}
			m = stof(s1);
			ProgressionName.set_FirstElem(m);
		}
		else
			throw std::invalid_argument("File not found");
		file.close();
	}
