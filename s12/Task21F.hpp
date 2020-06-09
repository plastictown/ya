#pragma once
#ifndef __TASK21F_HPP__
#define __TASK21F_HPP__

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

namespace DomchenkovMA {

  void solution() {
    int rows, cols;

    std::cin >> rows >> cols;
    std::vector<std::string> data;
    data.reserve(rows);

    if (rows == 1) {
      std::cout << 0;
      return;
    }

    std::string s;
    std::getline(std::cin, s);
    s.clear();

    for (int i = 0; i < rows; ++i) {
      std::getline(std::cin, s);
      data.emplace_back(s);
    }

    int ndel = 0;

    for (int j = 0; j < cols; ++j) {
      for (int i = 0; i < rows - 1; ++i) {
        if (data[i][j] != 0)
          if (data[i][j] > data[i + 1][j]) {
            ++ndel;
            break;
          }
      }
    }

    std::cout << ndel;
  }

} // !namespace

#endif // !__TASK21F_HPP__