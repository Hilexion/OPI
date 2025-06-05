#include "pch.h"
#include "input.h"
#include <iostream>

/// <summary>
/// ������� ��� ����� ���������� ��������� � ���������� ��������.
/// </summary>
/// <param name="NumTroinik> - ������ �� ���������� ���� unsigned int, � ������� ����� ��������� ���������� ���������.</param>
/// <param name="Troinik> - ������ �� ������ ���� int, � ������� ����� ��������� ���������� ��������.</param>
void getInput(unsigned int& NumTroinik, int*& Troinik) {
    double input;
    unsigned int i;

    std::cout << "������� ���������� ���������: ";
    std::cin >> input;

    if (std::cin.fail() || input < 1 || input > 1000 || input != static_cast<unsigned int>(input)) {
        std::cout << "������� �������� ���������� ���������. ������� ����� ����� � ��������� �� 1 �� 1000.";
        throw std::invalid_argument("�������� ���������� ���������.");
    }

    NumTroinik = static_cast<unsigned int>(input);

    Troinik = new int[NumTroinik];

    for (i = 0; i < NumTroinik; ++i) {
        std::cout << "������� " << i + 1 << ": ";
        std::cin >> Troinik[i];
        if ((Troinik[i] < 1) || (Troinik[i] > 1000)) {
            std::cout << "������� �������� ���������� ��������. ������� ����� � ��������� �� 1 �� 1000.";
            throw std::invalid_argument("�������� ���������� ��������.");
        }
    }
}
