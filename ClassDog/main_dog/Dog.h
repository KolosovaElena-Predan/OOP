//��������� �������� �.�.

#pragma once
#include <iostream>
#include <cstring>


class Dog
{
	protected:
		//����:

		/// ������ ������
		std::string name;

		///������� ������ � �����
		int age;

		///������ ������
		std::string breed;

	public:

		///�����������
		Dog(std::string dog_name = "-", std::string dog_breed="-", int dog_age=0);

		///������ ��� ������
		void set_name(std::string new_name);
		
		///������ ��� ������
		std::string get_name();

		///������ ��� ������
		void set_breed(std::string new_breed);

		///������ ��� ������
		std::string get_breed();

		///������ ��� ��������
		void set_age(int new_age);

		///������ ��� ��������
		int get_age();

		///���������� ������ ���� "<name>: -woof"
		std::string Say();

		///���������� ������ ���� "<name>: - woof ..."
		///number_of_woofs - ���-�� woof
		std::string Say(int number_of_woofs);

		///���������� ������ ���� "��� ������ is run"
		std::string Run();

		///���������� ������ ���� "��� ������ is looking for something"
		virtual std::string Search();




};