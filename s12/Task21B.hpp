#pragma once
#ifndef __TASK21B_HPP__
#define __TASK21B_HPP__

#include <iostream>
#include <vector>

namespace DomchenkovMA {

  void solution() {
    unsigned n;
    std::cin >> n;

    if (n < 2) {
      std::cout << 0;
      return;
    }

    std::vector<int> data;
    data.reserve(n);

    for (unsigned i = 0; i < n; ++i) {
      int t; std::cin >> t;
      data.push_back(t);
    }

    // first iteration
    bool have_a_thing = false;
    int price = INT_MAX;

    int sum = 0;
    for (unsigned i = 0; i < n - 1u; ++i) {
      if (have_a_thing) {
        if (price < data[i]) {
          sum += (data[i] - price);
          have_a_thing = false;
        }
        else continue;
      }
      if (data[i] < data[i + 1]) {
        have_a_thing = true;
        price = data[i];
      }
    }

    if (have_a_thing && price < data.back())
      sum += (data.back() - price);

    std::cout << sum;
  }

} // !namespace

#endif // !__TASK21B_HPP__