#include <iostream>
#include <vector>
#include <climits>

int main() {
  int h, w;
  std::cin >> h >> w; // размерность матрицы

  std::vector<std::vector<int>> matrix(h, std::vector<int>(w));

  for (int i = 0; i < h; i++) {
    for (int j = 0; j < w; j++) {
      std::cin >> matrix[i][j];
    }
  }

  int min_row = INT_MAX, max_row = -1;
  int min_col = INT_MAX, max_col = -1;

  for (int i = 0; i < h; i++) {
    for (int j = 0; j < w; j++) {
      if (matrix[i][j] == 1) { // если часть фигуры
        if (i < min_row) min_row = i;
        if (i > max_row) max_row = i;
        if (j < min_col) min_col = j;
        if (j > max_col) max_col = j;
      }
    }
  }

  // выводим координаты
  std::cout << min_row << " " << min_col << " ";
  std::cout << max_row << " " << max_col << std::endl;

  return 0;
}