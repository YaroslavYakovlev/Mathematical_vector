#include <stdio.h>
#include <iomanip>
#include <iostream>
#include <sstream>

int main() {
  std::cout << "Realization of mathematical vector" << std::endl;
  const std::string add = "add";
  const std::string subtract = "subtract";
  const std::string scale = "scale";
  const std::string length = "length";
  const std::string normalize = "normalize";
  std::string command;

  std::cout << "Enter the command over the vector" << std::endl;
  std::cin >> command;
  if (command == "add") {
    std::cout << "add" << std::endl;
  } else if (command == "subtract") {
    std::cout << "subtract" << std::endl;
  } else if (command == "scale") {
    std::cout << "scale" << std::endl;
  } else if (command == "length") {
    std::cout << "length" << std::endl;
  } else if (command == "normalize") {
    std::cout << "normalize" << std::endl;
  }

  return 0;
}
