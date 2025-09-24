#include <iostream>
#include <cctype>

int main() {
  std::string plate;
  std::cout << "введите строку из 6 символов: ";
  std::cin >> plate; // читаем ввод

  bool format_ok = true; // предполагаем, что всё верно

  // проверяем первую букву
  if (!std::isalpha(plate[0])) format_ok = false;
  // проверяем три цифры
  if (!std::isdigit(plate[1]) || !std::isdigit(plate[2]) || !std::isdigit(plate[3])) format_ok = false;
  // проверяем две последние буквы
  if (!std::isalpha(plate[4]) || !std::isalpha(plate[5])) format_ok = false;

  std::cout << "результат: " << (format_ok ? "Yes" : "No");
  return 0;
}
