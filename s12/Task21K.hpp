#pragma once
#pragma once
#ifndef __TASK21K_HPP__
#define __TASK21K_HPP__

#include <iostream>
#include <set>

namespace DomchenkovMA {

  int solution() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int n, sum;
    std::cin >> n >> sum;

    if (n < 1) {
      std::cout << 0 << '\n';
      return 0;
    }

    std::multiset<int> houses;

    for (int i = 0u; i < n; ++i) {
      int t; std::cin >> t;
      houses.insert(t);
    }

    int ctr = 0;
    long lsum = 0;

    for (const auto& h : houses) {
      if (lsum + h > sum) break;
      lsum += h;
      ++ctr;
    }

    std::cout << ctr << '\n';

    return 0;
  }

} // !namespace

#endif // !__TASK21K_HPP__