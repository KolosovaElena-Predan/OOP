//��������� �������� �.�.

#include "Dog.h"

///�����������
Dog::Dog(std::string dog_name, std::string dog_breed, int dog_age) {
	name = dog_name;
	breed = dog_breed;
	age = dog_age;
}

///������ ��� �����
void Dog::set_name(std::string new_name) {
	if (new_name != "")
		name = new_name;
	else throw std::invalid_argument("Impossible dog name");
}

///������ ��� �����
std::string Dog::get_name() {
	return name;
}

///������ ��� ������
void Dog::set_breed(std::string new_breed) {
	if (new_breed != "")
		breed = new_breed;
	else throw std::invalid_argument("Impossible dog breed");
}

///������ ��� ������
std::string Dog::get_breed() {
	return breed;
}

///������ ��� ��������
void Dog::set_age(int new_age) {
	if (new_age >= 0)
		age = new_age;
	else throw std::invalid_argument("Impossible dog age");
}

///������ ��� ��������
int Dog::get_age() {
	return age;
}

///���������� ������ ���� "��� ������: - Woof"
std::string Dog::Say() {
	return name + ": - woof";
}

///���������� ������ ���� "��� ������: - woof ..."
///number_of_woofs - ���-�� woof
std::string Dog::Say(int number_of_woofs) {
	if (number_of_woofs > 0) {
		std::string s = name + ": - ";
		for (int i = 0; i < number_of_woofs; i++)
			s = s + "woof ";
		return s;
	}
	else return "";
}

///���������� ������ ���� "��� ������ is run"
std::string Dog::Run() {
	return name+" is run";
}

///���������� ������ ���� "��� ������ is looking for something"
std::string Dog::Search() {
	return name + " is looking for something";
}
