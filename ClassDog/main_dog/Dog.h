//Выполнила Колосова Е.К.

#pragma once
#include <iostream>
#include <cstring>


class Dog
{
	protected:
		//поля:

		/// кличка собаки
		std::string name;

		///возраст собаки в годах
		int age;

		///порода собаки
		std::string breed;

	public:

		///Конструктор
		Dog(std::string dog_name = "-", std::string dog_breed="-", int dog_age=0);

		///сеттер для клички
		void set_name(std::string new_name);
		
		///геттер для клички
		std::string get_name();

		///сеттер для породы
		void set_breed(std::string new_breed);

		///геттер для породы
		std::string get_breed();

		///сеттер для возраста
		void set_age(int new_age);

		///геттер для возраста
		int get_age();

		///возвращает строку типа "<name>: -woof"
		std::string Say();

		///возвращает строку типа "<name>: - woof ..."
		///number_of_woofs - кол-во woof
		std::string Say(int number_of_woofs);

		///возвращает строку типа "Имя собаки is run"
		std::string Run();

		///возвращает строку типа "Имя собаки is looking for something"
		virtual std::string Search();




};