//��������� �������� �.�.

#pragma once
#include "Dog.h"
class PoliceDog :
    public Dog
{
	//���� ������:

	public:

		///�����������
		PoliceDog(std::string dog_name = "-", std::string dog_breed = "-", int dog_age = 0);


		///���������� ������ ���� "��� ������ catches up with criminal"
		std::string catch_up();

		///���������� ������ ���� "��� ������ is guarding"
		std::string Guard();

		///���������� ������ ���� "��� ������ is looking for criminal"
		std::string Search() override;
};

