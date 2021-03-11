#include <iostream>
#include "sudoku.h"

int main()
{
  Sudoku sd;
  sd.enterDigits();

  if (sd.Solve(0, 0)) {
    sd.Print();
  }
  return 0;
}
