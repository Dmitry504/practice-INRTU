﻿#include <iostream>
#include <vector>
#include <iostream>
#include <vector>

int main() {
  int n, k;
  std::cin >> n >> k; // ввод

  std::vector<int> permutation(n);
  for (int i = 0; i < n; i++) {
    std::cin >> permutation[i]; // читаем перестановку
  }

  std::string encrypted;
  std::cin >> encrypted;

  // Обратная перестановка
  std::vector<int> inverse(n);
  for (int i = 0; i < n; i++) {
    inverse[permutation[i] - 1] = i + 1;
  }

  std::string result = encrypted;
  for (int iter = 0; iter < k; iter++) {
    std::string temp = result;
    for (int i = 0; i < n; i++) {
      temp[i] = result[inverse[i] - 1]; // переставляем
    }
    result = temp;
  }

  std::cout << result; // результат

  return 0;
}