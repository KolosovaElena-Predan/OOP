//Выполнила Колосова Е.К.

#include "HuntingDog.h"



///Конструктор
HuntingDog::HuntingDog(std::string dog_name, std::string dog_breed, int dog_age, std::string dog_TypePrey) {
	name = dog_name;
	breed = dog_breed;
	age = dog_age;
	TypePrey = dog_TypePrey;
}

///сеттер для вида добычи
void HuntingDog::set_TypePrey(const std::string new_TypePrey) {
	if (new_TypePrey != "")
		TypePrey = new_TypePrey;
	else throw std::invalid_argument("Impossible type prey");
}

///геттер для вида добычи
std::string HuntingDog::get_TypePrey() {
	return TypePrey;
}

///возвращает строку типа "Имя собаки is looking for вид добычи"
std::string HuntingDog::Search() {
	return name + " is looking for "+TypePrey;
}

///возвращает строку типа "Имя собаки is brought of вид добычи"
std::string HuntingDog::Bring() {
	return name + " is brought of " + TypePrey;
}