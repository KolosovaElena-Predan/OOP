//выполнила Колосова Елена

#include <iostream>
#include "Progression.h"
int main()

{
    Progression_Test();
    Progression A;
    A.set_FirstElem(2);
    A.set_Step(2);
	std::cout<<A.get_FirstElem()<< std::endl;
	std::cout << A.get_FirstElem() << std::endl;
    A.set_PType(ProgressionType::Geometric);
    std::cout << A.Value_n_element(3) << std::endl;
    std::cout << A.Find_the_sum(4) << std::endl;
    std::cout << A.To_String();

}
