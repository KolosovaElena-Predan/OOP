// Array.cpp : "Этот файл содержит функции для работы с массивом

#include <time.h>
#include <iostream>
#include <fstream>
#include <string> 
using namespace std;

template <typename T>
/// заполняет массив случайными числами
/// \param arr массив
/// \param n размер массива
/// \param min минимально возможное число в массиве
/// \param max максимально возможное число в массве
/// \return ничего
void array_fill_randomly(T* arr, unsigned n, T min, T max) {
    //srand(time(NULL));
    T Mrange = max - min; //диапазон рандома
    for (unsigned i = 0; i < n; i++)
        arr[i] = (((float)rand() / RAND_MAX) * Mrange) + min;
}

template <typename T>
/// выводит массив в файл
/// \param arr массив
/// \param n размер массива
/// \param FileName файл, куда выводится массив
/// \return ничего, но в файл выводиться массив
void output_to_file(const T* arr, unsigned n, const std::string& FileName) {
    std::ofstream file;
    file.open(FileName);
    if (file.is_open()) {
        for (unsigned i = 0; i < n; i++) {
            file << arr[i];
            if (i != n - 1)
                file << endl;
        }
    }
    else
        throw invalid_argument("File not found");
    file.close();

}

template <typename T>
/// проверяет отсортирован ли массив по возрастанию
/// \param arr массив
/// \param n размер массива
/// \return ничего, но в файл выводиться массив
bool checking_for_increasing(const T* arr, unsigned n) {
    for (unsigned int i = 1; i < n; i++) {
        if (arr[i] < arr[i - 1])
            return false;
    }
    return true;
}

template <typename T>
/// проверяет отсортирован ли массив по убыванию
/// \param arr массив
/// \param n размер массива
/// \return ничего, но в файл выводиться массив
bool checking_for_descending(const T* arr, unsigned n) {
    for (unsigned int i = 1; i < n; i++) {
        if (arr[i] > arr[i - 1])
            return false;
    }
    return true;
}




int main()
{


}
