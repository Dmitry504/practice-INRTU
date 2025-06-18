#include <iostream>
#include <vector>

void buildHeap(int n) {
  std::vector<std::vector<int>> heap;
  std::vector<std::vector<int>> original;

  int value = 1;

  for (int i = 0; i < n; ++i) {
    std::vector<int> row, copyRow;
    for (int j = 0; j < n; ++j) {
      if (j <= i) {
        row.push_back(value * 10 + i + j); // генерируем
        copyRow.push_back(value * 10 + i + j);
        value++;
      }
      else {
        row.push_back(0);
        copyRow.push_back(0);
      }
    }
    heap.push_back(row);
    original.push_back(copyRow);
  }

  // пирамида
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j <= i; ++j) {
      std::cout << original[i][j] << " ";
    }
    std::cout << std::endl;
  }

  // дп
  for (int i = n - 2; i >= 0; --i) {
    for (int j = 0; j <= i; ++j) {
      heap[i][j] += std::min(heap[i + 1][j], heap[i + 1][j + 1]);
    }
  }

  std::vector<int> path;
  int i = 0, j = 0;
  path.push_back(original[i][j]);
  while (i < n - 1) {
    if (heap[i + 1][j] < heap[i + 1][j + 1]) {
      ++i;
    }
    else {
      ++i;
      ++j;
    }
    path.push_back(original[i][j]);
  }

  std::cout << "\nPath: ";
  for (size_t k = 0; k < path.size(); ++k) {
    std::cout << path[k];
    if (k != path.size() - 1)
      std::cout << " ";
  }
  std::cout << std::endl;

  std::cout << "Min time: " << heap[0][0] << std::endl;
}

int main() {
  int n = 0;
  std::cout << "Enter height: ";
  std::cin >> n;
  buildHeap(n);
  return 0;
}




