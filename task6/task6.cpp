#include <iostream>
#include <vector>
#include <algorithm>

int main() {
  int n = 0;
  std::cout << "Введите количество запросов: ";
  std::cin >> n; // читаем количество запросов

  std::vector<std::vector<int>> requests(n, std::vector<int>(4)); // массив для хранения всех запросов

  std::cout << "Введите запросы (a, b, x ,y): ";
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < 4; j++) {
      std::cin >> requests[i][j]; // считываем a, b, x, y для каждого запроса
    }
  }
  std::cout << "Результат: ";
  for (int i = 0; i < n; i++) {
    std::vector<int> req = requests[i]; // текущий запрос
    int a = req[0]; // количество контроллеров a
    int b = req[1]; // количество контроллеров b
    int x = req[2]; // количество модулей типа 1
    int y = req[3]; // количество модулей типа 2

    int used_b = 0;

    // сначала подключаем b к модулю типа 1 (совместимость только с ними)
    if (b >= x) {
      used_b = x; // b хватает на все x
      x = 0; // все модули типа 1 заняты
    } else {
      used_b = b; // используем все b
      x -= b; // оставшиеся модули типа 1
    }

    // затем подключаем a к оставшимся модулям типа 1 и ко всем модулям типа 2
    int used_a = std::min(a, x + y);

    std::cout << used_b + used_a << ' ';
  }
  return 0;
}
