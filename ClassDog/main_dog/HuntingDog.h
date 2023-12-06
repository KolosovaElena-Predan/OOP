//��������� �������� �.�.

#pragma once
#include "Dog.h"
#include <iostream>
#include <cstring>

class HuntingDog : public Dog {

	//���� ������:
	private:

		///��� ������
		std::string TypePrey;

	public:

		///�����������
		HuntingDog(std::string dog_name = "-", std::string dog_breed = "-", int dog_age = 0, std::string dog_TypePrey="-");

		///������ ��� ���� ������
		void set_TypePrey(const std::string new_TypePrey);

		///������ ��� ���� ������
		std::string get_TypePrey();

		///���������� ������ ���� "��� ������ is brought of ��� ������"
		std::string Bring();

		///���������� ������ ���� "��� ������ is looking for ��� ������"
		std::string Search() override;
};