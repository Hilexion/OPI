#include "output.h"
#include <iostream>


/// <summary>
/// Функция для вывода числа чайников, которых можно подключить.
/// </summary>
void output::outputData(int NumTeapot) {
    std::cout << "Максимальное количество чайников, которых можно использовать: " << NumTeapot;
}