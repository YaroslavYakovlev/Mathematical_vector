#include <stdio.h>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <sstream>

double result_A;
double result_B;
double result_length;
double result_scale_Ax;
double result_scale_Ay;

void vec_add(double& Ax, double& Ay, double& Bx, double& By) {
  result_A = Ax + Bx;
  result_B = Ay + By;
}
void vec_subtract(double& Ax, double& Ay, double& Bx, double& By) {
  result_A = Ax - Bx;
  result_B = Ay - By;
}

void vec_scale(double& Ax, double& Ay, double& scale) {
  result_scale_Ax = std::abs(Ax) * scale;
  result_scale_Ay = std::abs(Ay) * scale;
}

void vec_length(double& Coordinate_Ax, double& Coordinate_Point_Ay, double& Coordinate_Point_Bx, double& Coordinate_Point_By) {
  result_length = std::sqrt(std::pow((Coordinate_Point_Bx - Coordinate_Ax), 2) + std::pow((Coordinate_Point_By - Coordinate_Point_Ay), 2));
}

void vec_normalize() {}

struct math_command {
  const std::string add = "add";
  const std::string subtract = "subtract";
  const std::string scale = "scale";
  const std::string length = "length";
  const std::string normalize = "normalize";
};

int main() {
  std::cout << "Realization of mathematical vector" << std::endl;
  math_command math_command;
  std::string command;
  double Ax;
  double Ay;
  double Bx;
  double By;
  double scale;

  std::cout << "Enter the command over the vector" << std::endl;
  std::cin >> command;
  if (command == math_command.add) {
    std::cout << "Enter the first vector coordinates" << std::endl;
    std::cin >> Ax >> Ay;
    std::cout << "Enter the second vector coordinates" << std::endl;
    std::cin >> Bx >> By;
    vec_add(Ax, Ay, Bx, By);
    std::cout << "Summ vec = " << result_A << " and " << result_B << std::endl;
  } else if (command == math_command.subtract) {
    std::cout << "Enter the first vector coordinates" << std::endl;
    std::cin >> Ax >> Ay;
    std::cout << "Enter the second vector coordinates" << std::endl;
    std::cin >> Bx >> By;
    vec_subtract(Ax, Ay, Bx, By);
    std::cout << "Subtract vec = " << result_A << " and " << result_B << std::endl;
  } else if (command == math_command.scale) {
    std::cout << "Enter the first vector coordinates" << std::endl;
    std::cin >> Ax >> Ay;
    std::cout << "Enter the scale" << std::endl;
    std::cin >> scale;
    vec_scale(Ax, Ay, scale);
    std::cout << "Scale vec = " << result_scale_Ax << " and " << result_scale_Ay << std::endl;
  } else if (command == math_command.length) {
    std::cout << "Enter the first vector coordinates" << std::endl;
    std::cin >> Ax >> Ay;
    std::cout << "Enter the second vector coordinates" << std::endl;
    std::cin >> Bx >> By;
    vec_length(Ax, Ay, Bx, By);
    std::cout << "Length vec = " << result_length << std::endl;
  } else if (command == math_command.normalize) {
    std::cout << "Enter the first vector coordinates" << std::endl;
    std::cin >> Ax >> Ay;
    std::cout << "Enter the second vector coordinates" << std::endl;
    std::cin >> Bx >> By;
    vec_length(Ax, Ay, Bx, By);
    std::cout << "Normalize vec = " << Ax / result_length << " , " << Ay / result_length << " and " << Bx / result_length << " , " << By / result_length << std::endl;
  }

  return 0;
}
