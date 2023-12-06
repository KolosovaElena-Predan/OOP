//��������� �������� �.�.

#include "HuntingDog.h"



///�����������
HuntingDog::HuntingDog(std::string dog_name, std::string dog_breed, int dog_age, std::string dog_TypePrey) {
	name = dog_name;
	breed = dog_breed;
	age = dog_age;
	TypePrey = dog_TypePrey;
}

///������ ��� ���� ������
void HuntingDog::set_TypePrey(const std::string new_TypePrey) {
	if (new_TypePrey != "")
		TypePrey = new_TypePrey;
	else throw std::invalid_argument("Impossible type prey");
}

///������ ��� ���� ������
std::string HuntingDog::get_TypePrey() {
	return TypePrey;
}

///���������� ������ ���� "��� ������ is looking for ��� ������"
std::string HuntingDog::Search() {
	return name + " is looking for "+TypePrey;
}

///���������� ������ ���� "��� ������ is brought of ��� ������"
std::string HuntingDog::Bring() {
	return name + " is brought of " + TypePrey;
}