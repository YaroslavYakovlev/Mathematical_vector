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

std::vector<double> vec_add(std::vector<coordinates_vector>& vec) {
  std::vector<double> result_A_B;
  result_A_B.push_back(vec[0].point_A + vec[0].point_B);
  result_A_B.push_back(vec[1].point_A + vec[1].point_B);
  return result_A_B;
}

std::vector<double> vec_subtract(std::vector<coordinates_vector>& vec) {
  std::vector<double> result_A_B;
  result_A_B.push_back(vec[0].point_A + vec[0].point_B);
  result_A_B.push_back(vec[1].point_A + vec[1].point_B);
  return result_A_B;
}

std::vector<double> vec_scale(std::vector<coordinates_vector>& vec, double& scale) {
  std::vector<double> result_scale_A_B;
  result_scale_A_B.push_back(std::abs(vec[0].point_A) * scale);
  result_scale_A_B.push_back(std::abs(vec[1].point_B) * scale);
  return result_scale_A_B;
}

double vec_length(std::vector<coordinates_vector>& vec) {
  double result_length = std::sqrt(std::pow((vec[1].point_A - vec[0].point_A), 2) + std::pow((vec[1].point_B - vec[0].point_B), 2));
  return result_length;
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
  int countVec;
  math_command math_command;
  std::string command;
  double scale;
  double Ax;
  double Ay;
  std::vector<coordinates_vector> tmp_vector;
  std::cout << "Enter the command over the vector" << std::endl;
  std::cin >> command;
  if (command == math_command.add) {
    countVec = 2;
    for (int i = 0; i < countVec; i++) {
      std::cout << "Enter vector coordinates" << std::endl;
      std::cin >> Ax >> Ay;
      tmp_vector.push_back({Ax, Ay});
    }
    std::cout << "Summ vec = " << vec_add(tmp_vector)[0] << " and " << vec_add(tmp_vector)[1] << std::endl;
  } else if (command == math_command.subtract) {
    countVec = 2;
    for (int i = 0; i < countVec; i++) {
      std::cout << "Enter vector coordinates" << std::endl;
      std::cin >> Ax >> Ay;
      tmp_vector.push_back({Ax, Ay});
    }
    std::cout << "Summ vec = " << vec_subtract(tmp_vector)[0] << " and " << vec_subtract(tmp_vector)[1] << std::endl;
  } else if (command == math_command.scale) {
    countVec = 1;
    std::cout << "Enter vector coordinates" << std::endl;
    std::cin >> Ax >> Ay;
    tmp_vector.push_back({Ax, Ay});
    std::cout << "Enter the scale" << std::endl;
    std::cin >> scale;
    std::cout << "Scale vec = " << vec_scale(tmp_vector, scale)[0] << " and " << vec_scale(tmp_vector, scale)[1] << std::endl;
  } else if (command == math_command.length) {
    countVec = 2;
    for (int i = 0; i < countVec; i++) {
      std::cout << "Enter vector coordinates" << std::endl;
      std::cin >> Ax >> Ay;
      tmp_vector.push_back({Ax, Ay});
    }
    std::cout << "Length vec = " << vec_length(tmp_vector) << std::endl;
  } else if (command == math_command.normalize) {
    countVec = 2;
    for (int i = 0; i < countVec; i++) {
      std::cout << "Enter vector coordinates" << std::endl;
      std::cin >> Ax >> Ay;
      tmp_vector.push_back({Ax, Ay});
    }
    std::cout << "Normalize vec = " << tmp_vector[0].point_A / vec_length(tmp_vector) << " , " << tmp_vector[0].point_B / vec_length(tmp_vector) << " and "
              << tmp_vector[1].point_A / vec_length(tmp_vector) << " , " << tmp_vector[1].point_B / vec_length(tmp_vector) << std::endl;
  }

  return 0;
}
