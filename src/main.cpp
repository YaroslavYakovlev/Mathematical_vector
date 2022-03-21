#include <stdio.h>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <vector>

struct coordinates_vector {
  double point_A = 0;
  double point_B = 0;
};

coordinates_vector vec_add(coordinates_vector vec_1, coordinates_vector vec_2) {
  coordinates_vector vec;
  vec.point_A = vec_1.point_A + vec_2.point_A;
  vec.point_B = vec_1.point_B + vec_2.point_B;
  return vec;
}

coordinates_vector vec_subtract(coordinates_vector vec_1, coordinates_vector vec_2) {
  coordinates_vector vec;
  vec.point_A = vec_1.point_A - vec_2.point_A;
  vec.point_B = vec_1.point_B - vec_2.point_B;
  return vec;
}

coordinates_vector vec_scale(coordinates_vector vec_1, double& scale) {
  coordinates_vector vec;
  vec.point_A = vec_1.point_A * scale;
  vec.point_B = vec_1.point_B * scale;
  return vec;
}

double vec_length(coordinates_vector point_vec_1, coordinates_vector point_vec_2) {
  double result_length = std::sqrt(std::pow((point_vec_2.point_A - point_vec_1.point_A), 2) + std::pow((point_vec_2.point_B - point_vec_1.point_B), 2));
  return result_length;
}

// void vec_normalize() {}

void filling_vector(std::vector<coordinates_vector>& tmp_vector, int countVec) {
  double Ax, Ay;
  for (int i = 0; i < countVec; i++) {
    std::cout << "Enter vector coordinates" << std::endl;
    std::cin >> Ax >> Ay;
    tmp_vector.push_back({Ax, Ay});
  }
}

struct math_command {
  const std::string add = "add";
  const std::string subtract = "subtract";
  const std::string scale = "scale";
  const std::string length = "length";
  const std::string normalize = "normalize";
};

int main() {
  std::cout << "Realization of mathematical vector" << std::endl;
  int countVec;
  math_command math_command;
  std::string command;
  double scale;
  double Ax;
  double Ay;
  // std::vector<coordinates_vector> tmp_vector;
  coordinates_vector tmp_vector_1;
  coordinates_vector tmp_vector_2;

  std::cout << "Enter the command over the vector" << std::endl;
  std::cin >> command;
  if (command == math_command.add) {
    countVec = 2;
    // filling_vector(tmp_vector, countVec);
    std::cout << "Enter first vector coordinates" << std::endl;
    std::cin >> tmp_vector_1.point_A >> tmp_vector_1.point_B;
    std::cout << "Enter second vector coordinates" << std::endl;
    std::cin >> tmp_vector_2.point_A >> tmp_vector_2.point_B;
    std::cout << "Summ vec = " << vec_add(tmp_vector_1, tmp_vector_2).point_A << " and " << vec_add(tmp_vector_1, tmp_vector_2).point_B << std::endl;
  } else if (command == math_command.subtract) {
    countVec = 2;
    // filling_vector(tmp_vector, countVec);
    std::cout << "Enter first vector coordinates" << std::endl;
    std::cin >> tmp_vector_1.point_A >> tmp_vector_1.point_B;
    std::cout << "Enter second vector coordinates" << std::endl;
    std::cin >> tmp_vector_2.point_A >> tmp_vector_2.point_B;
    std::cout << "Subtract vec = " << vec_add(tmp_vector_1, tmp_vector_2).point_A << " and " << vec_add(tmp_vector_1, tmp_vector_2).point_B << std::endl;
  } else if (command == math_command.scale) {
    countVec = 1;
    std::cout << "Enter first vector coordinates" << std::endl;
    std::cin >> tmp_vector_1.point_A >> tmp_vector_1.point_B;
    std::cout << "Enter the scale" << std::endl;
    std::cin >> scale;
    std::cout << "Scale vec = " << vec_scale(tmp_vector_1, scale).point_A << " and " << vec_scale(tmp_vector_1, scale).point_B << std::endl;
  } else if (command == math_command.length) {
    countVec = 2;
    // filling_vector(tmp_vector, countVec);
    std::cout << "Enter point first vector coordinates" << std::endl;
    std::cin >> tmp_vector_1.point_A >> tmp_vector_1.point_B;
    std::cout << "Enter point second vector coordinates" << std::endl;
    std::cin >> tmp_vector_2.point_A >> tmp_vector_2.point_B;
    std::cout << "Length vec = " << vec_length(tmp_vector_1, tmp_vector_2) << std::endl;
  } else if (command == math_command.normalize) {
    countVec = 2;
    // filling_vector(tmp_vector, countVec);
    std::cout << "Enter first vector coordinates" << std::endl;
    std::cin >> tmp_vector_1.point_A >> tmp_vector_1.point_B;
    std::cout << "Enter second vector coordinates" << std::endl;
    std::cin >> tmp_vector_2.point_A >> tmp_vector_2.point_B;
    std::cout << "Normalize vec = " << tmp_vector_1.point_A / vec_length(tmp_vector_1, tmp_vector_2) << " , " << tmp_vector_1.point_B / vec_length(tmp_vector_1, tmp_vector_2) << " and "
              << tmp_vector_2.point_A / vec_length(tmp_vector_1, tmp_vector_2) << " , " << tmp_vector_2.point_B / vec_length(tmp_vector_1, tmp_vector_2) << std::endl;
  }
  return 0;
}
