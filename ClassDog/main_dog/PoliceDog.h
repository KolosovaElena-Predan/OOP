//Выполнила Колосова Е.К.

#pragma once
#include "Dog.h"
class PoliceDog :
    public Dog
{
	//поля класса:

	public:

		///Конструктор
		PoliceDog(std::string dog_name = "-", std::string dog_breed = "-", int dog_age = 0);


		///возвращает строку типа "Имя собаки catches up with criminal"
		std::string catch_up();

		///возвращает строку типа "Имя собаки is guarding"
		std::string Guard();

		///возвращает строку типа "Имя собаки is looking for criminal"
		std::string Search() override;
};

