//��������� �������� �.�.

#include "PoliceDog.h"

///�����������
PoliceDog::PoliceDog(std::string dog_name, std::string dog_breed, int dog_age) {
	name = dog_name;
	breed = dog_breed;
	age = dog_age;
}


///���������� ������ ���� "��� ������ is looking for criminal"
std::string PoliceDog::Search() {
	return name + " is looking for criminal";
}

///���������� ������ ���� "��� ������ catches up with criminal"
std::string PoliceDog::catch_up() {
	return name + " catches up with criminal";
}

///���������� ������ ���� "��� ������ is guarding"
std::string PoliceDog::Guard() {
	return name + " is guarding";
}