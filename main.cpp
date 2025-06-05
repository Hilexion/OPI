#include "input.h"
#include "calc.h"
#include "output.h"
#include <iostream>

using namespace calculate;

/// <summary>
/// ������� �������, ������� ��������� ���������� � �������� �������� �������.
/// </summary>
int main() {
    setlocale(LC_ALL, "RU");
    int NumTeapot;
    unsigned int NumTroinik;
    int* Troinik;

    getInput(NumTroinik, Troinik);
    NumTeapot = calcMaxTeapot(NumTroinik, Troinik);
    output::outputData(NumTeapot);

    delete[] Troinik;

    return 0;
}