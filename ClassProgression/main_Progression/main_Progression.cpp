//выполнила Колосова Елена

#include <iostream>
#include "Progression.h"
int main()

{
    //проверка правильности работы некоторых функций
    Progression_Test();

    ///объявление статического объекта
    Progression A1;

    A1.set_FirstElem(2);//задание первого элемента
    A1.set_Step(2);//задание шага

    std::cout << "Exemple 1" << std::endl;
	std::cout<<"First element: "<<A1.get_FirstElem() << std::endl; //вывод значения первго элемента на экран
	std::cout << "Step: " << A1.get_Step() << std::endl; //вывод значения шага прогрессии на экран 
    std::cout <<"3 element: " << A1.Value_n_element(3) << std::endl; //вывод значения 3-го элемента прогрессии
    std::cout << "Sum of first 4 elements: "<<A1.Find_the_sum(4) << std::endl; //вывод значения суммы 4 элементов
    std::cout << A1.To_String()<< std::endl; //вывод данных в строку
    std::cout << std::endl;




    ///объявление константного статического объекта
    const Progression A2;

    std::cout << "Exemple 2" << std::endl;
    std::cout << "First element: " << A2.get_FirstElem() << std::endl; //вывод значения первго элемента на экран
    std::cout << "Step: " << A2.get_Step() << std::endl; //вывод значения шага прогрессии на экран 
    std::cout << "5 element: " << A2.Value_n_element(5) << std::endl; //вывод значения 3-го элемента прогрессии
    std::cout << "Sum of first 2 elements: " << A2.Find_the_sum(2) << std::endl; //вывод значения суммы 4 элементов
    std::cout << A2.To_String() << std::endl; //вывод данных в строку
    std::cout << std::endl;

    ///объявление динамического объекта
    Progression * A3 = new Progression;

    A3->set_FirstElem(3);//задание первого элемента
    A3->set_Step(0.5);//задание шага
    A3->set_PType(ProgressionType::Geometric); //задание типа прогрессии

    std::cout << "Exemple 3" << std::endl;
    std::cout << "First element: " << A3->get_FirstElem() << std::endl; //вывод значения первго элемента на экран
    std::cout << "Step: " << A3->get_Step() << std::endl; //вывод значения шага прогрессии на экран 
    std::cout << "5 element: " << A3->Value_n_element(5) << std::endl; //вывод значения 3-го элемента прогрессии
    std::cout << "Sum of first 6 elements: " << A3->Find_the_sum(6) << std::endl; //вывод значения суммы 4 элементов
    std::cout << A3->To_String() << std::endl; //вывод данных в строку
    std::cout << std::endl;
}
