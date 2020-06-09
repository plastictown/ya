#pragma once
#ifndef __TASK21C_HPP__
#define __TASK21C_HPP__

#include <iostream>
#include <string>

namespace DomchenkovMA {

  void solution() {
    std::string small, big;
    std::getline(std::cin, small);
    std::getline(std::cin, big);

    if (small.empty()) {
      std::cout << "True";
      return;
    }

    if (small.length() > big.length()) {
      std::cout << "False";
      return;
    }

    bool result = false;
    unsigned idx = 0u;

    for (auto c : big) {
      if (small[idx] == c)
        ++idx;
      if (idx == small.length()) {
        result = true;
        break;
      }
    }

    if (result) std::cout << "True";
    else std::cout << "False";
  }

} // !namespace

#endif // !__TASK21C_HPP__