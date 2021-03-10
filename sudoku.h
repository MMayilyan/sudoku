#include <iostream>

class Sudoku
{
public:
  Sudoku()
  {}

  ~Sudoku()
  {}

  void enterDigits();
  bool Solve(int row, int col);
  void Print();

protected:
  static const int N = 9;
  int grid[N][N];

  bool isCorrectCol(int col, int num);
  bool isCorrectRow(int row, int num);
  bool isCorrectBox(int col, int row, int num);
  bool isCorrect(int col, int row, int num);
};
