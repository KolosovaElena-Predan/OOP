//Выполнила Колосова Елена ВМК-22

#include <time.h>
#include <iostream>
#include <vector>
using namespace std;

/// заполняет массив случайными числами
/// \param arr массив
/// \param n размер массива
/// \param min минимально возможное число в массиве
/// \param max максимально возможное число в массве
/// \return ничего
void array_fill_randomly(std::vector<float>&arr, unsigned n, float min=-100, float max=100){
arr.resize(n);
float Mrange = max - min; //диапазон рандома
for(unsigned i = 0; i < arr.size(); i ++)
arr[i]=(float)rand()/RAND_MAX*Mrange+min;
}

//template <typename T>
/// вычисляет сумму элементов массива по формуле a1 - a2 + a3 - ... + (-1)^(n+1)*an
/// \param arr массив
/// \param n размер массива
/// \return сумму элементов массива, вычисленную по формуле a1 - a2 + a3 - ... + (-1)^(n+1)*an
float sum_array_formul(const std::vector <float>&arr){
float s = 0.0;
float sign =1.0;
for (unsigned i = 0; i<arr.size(); i++){
s += arr[i]*sign;
sign=sign*(-1.0);}
return s; }



