//выполнила Колосова Елена
#include <string>
#include <iostream>
#include "Progression.h"
int main()

{
    //проверка правильности работы некоторых функций
    Progression_Test();


    ///объявление статического объекта
    Progression A1;
    std::string str = "1.txt";
    A1.set_FirstElem(2);//задание первого элемента
    A1.set_Step(2);//задание шага

    std::cout << "Exemple 1" << std::endl;
	std::cout<<"First element: "<<A1.get_FirstElem() << std::endl; //вывод значения первго элемента на экран
	std::cout << "Step: " << A1.get_Step() << std::endl; //вывод значения шага прогрессии на экран 
    std::cout <<"3 element: " << A1.Value_n_element(3) << std::endl; //вывод значения 3-го элемента прогрессии
    std::cout << "Sum of first 4 elements: "<<A1.Find_the_sum(4) << std::endl; //вывод значения суммы 4 элементов
    std::cout << A1.To_String()<< std::endl; //вывод данных в строку
    std::cout << std::endl;
    
    print_in_file(str, A1);

    //для демонстрации работы функции fill_from_file
    Progression B1;
    std::cout << "Exemple 1.1" << std::endl;
    fill_from_file(str, B1);
    std::cout << B1.To_String() << std::endl; //вывод данных в строку
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
    delete A3;

    ///статический массив
    Progression A4[3]{ Progression(1, 2),
                        Progression(2, 0.5),
                        Progression(3, 2) };

    std::cout << "Exemple 4" << std::endl;
    std::cout<<A4[0].get_FirstElem()<<" "<< A4[1].get_FirstElem()<<" "<< A4[2].get_FirstElem()<< std::endl;
    std::cout << std::endl;


    ///массив из указателей на объекты
    Progression *A5[2];

    A5[0] = new Progression(2, 3);
    A5[1] = new Progression(1, 0.5);
    std::cout << "Exemple 5" << std::endl;
    std::cout << "Steps: " << A5[0]->get_Step() << " " << A5[1]->get_Step() << std::endl;
    std::cout << std::endl;
    delete A5[0];
    delete A5[1];

    ///дин. массив из указателей на объекты 
    Progression* *A6 = new Progression* [2];
    for (int i = 0; i < 2; i++)
        A6[i] = new Progression();

    for (int i = 0; i < 2; i++)
        delete A6[i];
    delete[] A6;





}
