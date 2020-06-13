#pragma once
#ifndef __TASK21L_HPP__
#define __TASK21L_HPP__

#include <iostream>
#include <vector>

namespace DomchenkovMA {

  int solution() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int n;
    std::cin >> n;

    if (n < 1) {
      std::cout << "True\n";
      return 0;
    }

    std::vector<int> data;
    data.reserve(n);

    for (int i = 0; i < n; ++i) {
      int t; std::cin >> t;
      data.push_back(t);
    }

    int max_index = 0;

    for (int i = 0; i < data.size(); ++i) {
      if (i + data[i] > max_index)
        max_index = i + data[i];
      if (max_index >= data.size()) {
        std::cout << "True\n";
        return 0;
      }
      if (i >= max_index)
        break;
    }

    std::cout << "False\n";

    return 0;
  }

} // !namespace

#endif // !__TASK21L_HPP__