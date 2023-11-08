//Выполнила Колосова Елена ВМК-22

/// заполняет массив случайными числами
/// \param arr массив
/// \param n размер массива
/// \param min минимально возможное число в массиве
/// \param max максимально возможное число в массве
/// \return ничего
void array_fill_randomly(std::vector<float>&arr, unsigned n, float min=-100, float max=100);

/// вычисляет сумму элементов массива по формуле a1 - a2 + a3 - ... + (-1)^(n+1)*an
/// \param arr массив
/// \param n размер массива
/// \return сумму элементов массива, вычисленную по формуле a1 - a2 + a3 - ... + (-1)^(n+1)*an
float sum_array_formul(const std::vector<float>&arr);
