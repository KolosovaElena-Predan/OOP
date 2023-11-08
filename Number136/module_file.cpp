//Выполнила Колосова Елена ВМК-22


#include <fstream>
#include <iostream>
#include <string>
#include <vector>

using namespace std;
namespace ArrayAndTextFile{
//template <typename T>
/// выводит массив в текстовый файл
/// \param arr массив
/// \param n размер массива
/// \param file файл, куда выводится массив
/// \return ничего, но в файл выводиться массив
void output_to_file(const std::vector<float>&arr, const std::string &FileName){
std::ofstream file;
file.open(FileName);
if (file.is_open()){
  for (unsigned i = 0; i<arr.size(); i++){
    file<<arr[i];
    if (i!=arr.size()-1)
      file<<endl; }}
else 
   throw invalid_argument("File not found");
file.close();
}



//template <typename T>

/// считывает массив с текстового файла
/// \param arr массив
/// \param n размер массива
/// \param file файл, откуда считывается массив
/// \return ничего, но в файл выводиться массив	
void file_to_array(std::vector<float>&arr, unsigned n, const std::string &FileName){
arr.resize(n);
std::fstream file;
file.open(FileName);
if (file.is_open()){
	file.seekg( 0 );
	for (int i = 0; i<arr.size(); i++){
	string arrs;
		file >> arrs;
	arr[i]=stof(arrs);}
}
else 
   throw invalid_argument("File not found");
file.close();
}


/// считает кол-во строк в текстовом файле
/// \param file файл, откуда считывается массив
/// \return кол-во строк в файле
int str_file(const std::string &FileName){
std::ifstream file;
file.open(FileName);
int count=0;
if (file.is_open()){
  file.seekg( 0 );
  string buffer;
  while (!file.eof())
    {
      // Увеличить счетчик строк
      count++;
      // Считать одну строку в буфер
      getline(file, buffer);
    }}
 else 
   throw invalid_argument("File not found");
   
  file.close();
  return count;}
 
}

namespace ArrayAndBinFile{
//template <typename T>

/// считывает массив с бинарного файла
/// \param arr массив
/// \param n размер массива
/// \param file файл, откуда считывается массив
/// \return ничего, но заполняет массив числами из файла
void file_to_array(std::vector<float>&arr, unsigned n, const std::string &FileName){
arr.resize(n);
ifstream file(FileName, ios_base::binary);
if (file.is_open()){
  for (int i = 0; i<n; i++){
    file.read((char*)&arr[i], sizeof(float));
  //cout<<arr[i]<<endl;
  }
}
else 
  throw invalid_argument("File not found");
file.close();
}

//template <typename T>

/// выводит массив в бинарный файл
/// \param arr массив
/// \param n размер массива
/// \param file файл, куда выводится массив
/// \return ничего, но в файл выводиться массив
void output_to_file(const std::vector<float>&arr, const std::string &FileName){
ofstream file(FileName, ios_base::binary);
if (file.is_open()){
  for (int i = 0; i<arr.size(); i++){
    file.write((char*)&arr[i], sizeof(float));}
}
else 
  throw invalid_argument("File not found");
file.close();
}
}

 
