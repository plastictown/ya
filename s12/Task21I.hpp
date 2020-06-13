#pragma once
#ifndef __TASK21I_HPP__
#define __TASK21I_HPP__

#include <iostream>
#include <algorithm>
#include <set>

namespace DomchenkovMA {

  int solution() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    const char* _false = "False\n";
    const char* _true = "True\n";

    unsigned n;
    std::cin >> n;

    if (n < 1) {
      std::cout << _false;
      return 0;
    }

    long sum = 0;

    std::multiset<int> data;
    for (unsigned i = 0u; i < n; ++i) {
      int t; std::cin >> t;
      data.insert(t);
      sum += t;
    }

    if (sum % 2) {
      std::cout << _false;
      return 0;
    }

    long halfsum = sum / 2;

    //search for halfsum
    auto it = data.find(halfsum);
    if (it != data.cend()) {
      std::cout << _true;
      return 0;
    }

    auto rit = data.rbegin();

    for (; rit != data.crend(); ++rit) {
      long lsum = 0;
      for (auto i = rit; i != data.crend(); ++i) {
        if (lsum > halfsum) break;
        if (lsum + *i <= halfsum)
          lsum += *i;
        if (lsum == halfsum) {
          std::cout << _true;
          return 0;
        }
      }
    }

    auto lit = data.begin();
    for (; lit != data.cend(); ++lit) {
      if (*lit > halfsum) break;
      long lsum = 0;
      for (auto i = lit; i != data.cend(); ++i) {
        if (lsum > halfsum || *i > halfsum) break;
        if (lsum + *i <= halfsum)
          lsum += *i;
        if (lsum == halfsum) {
          std::cout << _true;
          return 0;
        }
      }
    }

    std::cout << _false;
    return 0;
  }

} // !namespace

#endif // !__TASK21I_HPP__