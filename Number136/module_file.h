//Выполнила Колосова Елена ВМК-22

namespace ArrayAndTextFile{

/// выводит массив в текстовый файл
/// \param arr массив
/// \param n размер массива
/// \param file файл, куда выводится массив
/// \return ничего, но в файл выводиться массив
void output_to_file(const std::vector<float>&arr, const std::string &FileName);

/// считывает массив с текстового файла
/// \param arr массив
/// \param n размер массива
/// \param file файл, откуда считывается массив
/// \return ничего, но заполняет массив числами из файла
void file_to_array(std::vector<float>&arr,unsigned n, const std::string &FileName);

/// считает кол-во строк в текстовом файле
/// \param file файл, откуда считывается массив
/// \return кол-во строк в файле
int str_file(const std::string &FileName);
}

namespace ArrayAndBinFile{

/// считывает массив с бинарного файла
/// \param arr массив
/// \param n размер массива
/// \param file файл, откуда считывается массив
/// \return ничего, но заполняет массив числами из файла
void file_to_array(std::vector<float>&arr, unsigned n, const std::string &FileName);

/// выводит массив в бинарный файл
/// \param arr массив
/// \param n размер массива
/// \param file файл, куда выводится массив
/// \return ничего, но в файл выводиться массив
void output_to_file(const std::vector<float>&arr, const std::string &FileName);
}
