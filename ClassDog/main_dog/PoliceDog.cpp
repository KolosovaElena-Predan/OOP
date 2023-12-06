//Выполнила Колосова Е.К.

#include "PoliceDog.h"

///Конструктор
PoliceDog::PoliceDog(std::string dog_name, std::string dog_breed, int dog_age) {
	name = dog_name;
	breed = dog_breed;
	age = dog_age;
}


///возвращает строку типа "Имя собаки is looking for criminal"
std::string PoliceDog::Search() {
	return name + " is looking for criminal";
}

///возвращает строку типа "Имя собаки catches up with criminal"
std::string PoliceDog::catch_up() {
	return name + " catches up with criminal";
}

///возвращает строку типа "Имя собаки is guarding"
std::string PoliceDog::Guard() {
	return name + " is guarding";
}