//Выполнила Колосова Елена ВМК-22
// 136. Даны натуральное число n, действительные числа a1,..., an. Вычислить:
// ж) a1 - a2 + a3 - ... + (-1)^(n+1)*an;
#include <iostream>
#include <iomanip> //для округления
#include <cassert>                  // для assert
#include <vector>			   //для масивов
#include <cmath>                    // для assert
#include <fstream>			   //для работы с файлами
#include <string> 			   //для работы со строками
#include "module_arrays.h"          //модуль для работы с массивами
#include "module_file.h" 		   //модуль для работы с файлами
#include "module_binfile.h"


//using namespace std;


int main (){

	srand(time(nullptr));

	// округление в выводе
	std::cout << std::setw(12) << std::fixed << std::setprecision(2);		// 12 позиций на всё число; человекочитаемый формат (без e); два знака после запятой
	
	system("chcp 65001 > nul"); //подключение русского языка Источник:https://www.cyberforum.ru/cpp/thread2263304.html
	
	//проверка функции sum_array_formul;
	std::vector<float> a1{1, 2, 3, 4};
	assert(sum_array_formul(a1)==-2);
	//v
	a1={-8.0, 2.3, 6.0, 43.8, 69.0};
	
	
	assert(sum_array_formul(a1)-20.9<0.00001); //почему-то функция работает с погрешностью, хотя не должна
	a1={-20.00, 4.32, -106.98, 4.00, 65.532};
	assert(abs(sum_array_formul(a1)-(-69.768))<0.00001); //почему-то функция работает с погрешностью, хотя не должна


	int n;//размер массива
	std::string NameFile; //строка, содержащая имя файла

	//ввод размера массива
	std::cout<<"Введите размер массива: ";
	std::cin>>n;
	
	//выделение памяти под создаваемый массив		
	std::vector<float> a(n);
	
	//заполнение массива случайными числами
	array_fill_randomly(a, n);
	
	try{
	// создать объект для записи в файл
	// и открыть текстовый файл для записи
	std::cout<<"Введите имя файла: ";
	std::cin>>NameFile;
	


	//вывод массива в файл
	ArrayAndTextFile::output_to_file(a, NameFile);}
	catch (const std::invalid_argument& error) {
	std::cout<<error.what();}
	
	try{
	//открытие файла для чтения и записи
	std::cout<<"Введите имя файла: ";
	std::cin>>NameFile;
	
	int n2=ArrayAndTextFile::str_file(NameFile);
		
	//выделение памяти под считываемый массив
	std::vector<float> b(n2);
	
	ArrayAndTextFile::file_to_array(b, n2, NameFile);

			
	//вывод суммы
	std::cout<<sum_array_formul(b);

	

	}
	catch (const std::invalid_argument& error) {
	std::cout<<error.what();
	}	
	
	std::cout<<std::endl;
	try{
	//вывод в бинарный файл
	std::cout<<"Введите имя файла: ";
	std::cin>>NameFile;
	ArrayAndBinFile::output_to_file(a, NameFile);
	}
	catch (const std::invalid_argument& error) {
	std::cout<<error.what();}

	try{
	//выделение памяти под считываемый массив
	std::vector<float> c(n);

	
	//считывание с бинарного файла
	std::cout<<"Введите имя файла: ";
	std::cin>>NameFile;
	ArrayAndBinFile::file_to_array(c, n, NameFile);
	
	//вывод суммы
	std::cout<<sum_array_formul(c);
	}	
	catch (const std::invalid_argument& error) {
	std::cout<<error.what();}



}
