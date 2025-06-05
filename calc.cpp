#include "calc.h"

namespace calculate {
    /// <summary>
    /// ������� ��� ���������� ���������� ������ ��������� � ���������.
    /// </summary>
    /// <param name="NumTroinik"> � unsigned int ���������� ���������� ���������.</param>
    /// <param name="Troinik"> � ������������� ������ ���������� ��������.</param>
    /// <return> - int �������� ���������� ������ ��������.</returns>
    int calcMaxTeapot(int NumTroinik, int* Troinik) {
        int NumTeapot = 0;
        for (int i = 0; i < NumTroinik; i++) {
            NumTeapot += Troinik[i];
        }
        return NumTeapot - (NumTroinik - 1);
    }
}