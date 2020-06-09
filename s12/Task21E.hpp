#pragma once
#pragma once
#ifndef __TASK21D_HPP__
#define __TASK21D_HPP__

#include <iostream>
#include <set>

namespace DomchenkovMA {

  void solution() {

    int n_crackers, n_children;
    std::multiset<int> crackers, children;

    std::cin >> n_children;

    for (int i = 0; i < n_children; ++i) {
      int t; std::cin >> t;
      children.insert(t);
    }

    std::cin >> n_crackers;
    for (int i = 0; i < n_crackers; ++i) {
      int t; std::cin >> t;
      crackers.insert(t);
    }

    int res = 0;

    for (const auto c : children) {
      if (crackers.empty())
        break;
      auto it = crackers.begin();
      for (; it != crackers.end(); ++it) {
        if (c <= *it) {
          ++res;
          crackers.erase(it);
          break;
        }
      }
    }

    std::cout << res;

  }
} // !namespace

#endif // !__TASK21D_HPP__