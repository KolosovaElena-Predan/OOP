///Разработала Колосова Елена
#include <string>
#include <cmath>
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
	double Progression::Value_n_element(int number) {              //проверка на положительность
		if (PType == ProgressionType::Arithmetic)
			return FirstElem + Step * (number - 1);

		else
			if (Step != 1)
				return FirstElem * pow(Step, number - 1);
			//else throw std::exception("Incorrect progression step value");

	}

	///поиск суммы первых quantity элементов
	double Progression::Find_the_sum(int quantity){
		if (PType == ProgressionType::Arithmetic) //проверка на положительность
			return (2 * FirstElem + Step * (quantity - 1)) / 2.0 * quantity;

		else
			if (Step != 1)
				return (FirstElem * (pow(Step, quantity) - 1)) / (Step - 1);
			//else throw std::exception("Incorrect progression step value");
	}

	///преобразование данных класса в строку
	std::string Progression::To_String() {
		if (PType == ProgressionType::Arithmetic)
			return "This is an arithmetic progression with steps " + std::to_string(Step) + " and the value of the first element " + std::to_string(FirstElem);
		else
			return "This is an geometric progression with steps " + std::to_string(Step) + " and the value of the first element " + std::to_string(FirstElem);
	}

	///проверка правильности выполнения функций Value_n_element и Find_the_sum 
	void Progression_Test() {
		Progression P;
		P.set_FirstElem(1);
		P.set_Step(1);
		assert(P.Find_the_sum(3)==6);
	}
