#include "calc.h"

namespace calculate {
    /// <summary>
    /// ‘ункци€ дл€ вычислени€ количества пустых отверстий в тройниках.
    /// </summary>
    /// <param name="NumTroinik"> Ч unsigned int переменна€ количества тройников.</param>
    /// <param name="Troinik"> Ч целочисленный массив количества разъЄмов.</param>
    /// <return> - int значение количества пустых разъЄмов.</returns>
    int calcMaxTeapot(int NumTroinik, int* Troinik) {
        int NumTeapot = 0;
        for (int i = 0; i < NumTroinik; i++) {
            NumTeapot += Troinik[i];
        }
        return NumTeapot - (NumTroinik - 1);
    }
}