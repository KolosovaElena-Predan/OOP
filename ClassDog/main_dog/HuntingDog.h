//Выполнила Колосова Е.К.

#pragma once
#include "Dog.h"
#include <iostream>
#include <cstring>

class HuntingDog : public Dog {

	//поля класса:
	private:

		///вид добычи
		std::string TypePrey;

	public:

		///Конструктор
		HuntingDog(std::string dog_name = "-", std::string dog_breed = "-", int dog_age = 0, std::string dog_TypePrey="-");

		///сеттер для вида добычи
		void set_TypePrey(const std::string new_TypePrey);

		///геттер для вида добычи
		std::string get_TypePrey();

		///возвращает строку типа "Имя собаки is brought of вид добычи"
		std::string Bring();

		///возвращает строку типа "Имя собаки is looking for вид добычи"
		std::string Search() override;
};