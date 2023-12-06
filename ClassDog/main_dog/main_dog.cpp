//Выполнила Колосова Е.К.
#include "Dog.h"
#include "HuntingDog.h"
#include "PoliceDog.h"
#include <iostream>


int main()
{
	Dog A("Jack", "Husky", 2);
	std::cout << A.Run() << std::endl;
	std::cout << A.Search() << std::endl;
	std::cout << A.Say(5) << std::endl;

	HuntingDog B("Tom", "Dachshund", 5, "fox");
	std::cout << B.Search() << std::endl;
	std::cout << B.Bring() << std::endl;

	PoliceDog C("Mukhtar", "German Shepherd", 4);
	std::cout << C.catch_up() << std::endl;
	std::cout << C.Guard() << std::endl;
	std::cout << C.Search() << std::endl;






}
