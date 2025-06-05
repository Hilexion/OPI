#include "pch.h"
#include "input.h"
#include <iostream>

/// <summary>
/// Функция для ввода количества тройников и количества разъемов.
/// </summary>
/// <param name="NumTroinik> - ссылка на переменную типа unsigned int, в которую будет сохранено количество тройников.</param>
/// <param name="Troinik> - ссылка на массив типа int, в который будут сохранены количество разъемов.</param>
void getInput(unsigned int& NumTroinik, int*& Troinik) {
    double input;
    unsigned int i;

    std::cout << "Введите количество тройников: ";
    std::cin >> input;

    if (std::cin.fail() || input < 1 || input > 1000 || input != static_cast<unsigned int>(input)) {
        std::cout << "Введено неверное количество тройников. Введите целое число в диапазоне от 1 до 1000.";
        throw std::invalid_argument("Неверное количество тройников.");
    }

    NumTroinik = static_cast<unsigned int>(input);

    Troinik = new int[NumTroinik];

    for (i = 0; i < NumTroinik; ++i) {
        std::cout << "Тройник " << i + 1 << ": ";
        std::cin >> Troinik[i];
        if ((Troinik[i] < 1) || (Troinik[i] > 1000)) {
            std::cout << "Введено неверное количество разъёмов. Введите число в диапазоне от 1 до 1000.";
            throw std::invalid_argument("Неверное количество разъёмов.");
        }
    }
}
