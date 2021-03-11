#include <iostream>
#include "sudoku.h"

void Sudoku::enterDigits()
{
  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < N; ++j) {
        std::cin >> grid[i][j];
    }
  }
  std::cout << std::endl;
}

bool Sudoku::isCorrectCol(int col, int num)
{
  for (int i = 0; i < N; ++i) {
    if (grid[i][col] == num) {
       return false;
    }
  }
  return true;
}

bool Sudoku::isCorrectRow(int row, int num)
{
  for (int i = 0; i < N; ++i) {
    if (grid[row][i] == num) {
      return false;
    } 
  }
  return true;
}

bool Sudoku::isCorrectBox(int col, int row, int num)
{
  int startCol = col - col % 3;
  int startRow = row - row % 3;

  for (int i = 0; i < 3; ++i) {
    for (int j = 0; j < 3; ++j) {
      if (grid[i + startRow][j + startCol] == num) {
        return false;
      }
    }
  }
  return true;  
}

bool Sudoku::isCorrect(int col, int row, int num) 
{
  if (!isCorrectRow(row, num)) {
    return false;
  }

  if (!isCorrectCol(col, num)) {
    return false;
  }

  if (!isCorrectBox(col, row, num)) {
    return false;
  }
  return true;
}

bool Sudoku::Solve(int row, int col)
{
  if (row == N - 1 && col == N) {
    return true;
  }

  if (col == N) {
    row++;
    col = 0;
  }

  if (grid[row][col] > 0) {
    return Solve(row, col + 1);
  }

  for (int num = 1; num <= N; ++num) {
    if (isCorrect(col, row, num)) {
      grid[row][col] = num;
      if (Solve(row, col + 1)) {
        return true;
      }
    }
    grid[row][col] = 0;
  }
  return false;
}

void Sudoku::Print() 
{
  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < N; ++j) {
      std::cout << grid[i][j] << " ";
    }
    std::cout << std::endl;
  }
}

