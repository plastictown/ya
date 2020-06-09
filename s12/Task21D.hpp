#pragma once
#ifndef __TASK21D_HPP__
#define __TASK21D_HPP__

#include <iostream>
#include <set>

namespace DomchenkovMA {

  struct thing {
    int n;
    int size;
    int cost;
    bool operator < (const thing& rhs) const {

      if (cost == rhs.cost)
        if (size == rhs.size)
          return n < rhs.n;
        else
          return size < rhs.size;
      return cost > rhs.cost;

      return false;
    }
    void read(int _n) {
      n = _n;
      std::cin >> cost >> size;
    }
  };

  void solution() {
    int size, n;
    std::cin >> size >> n;

    std::multiset<struct thing> data;

    for (int i = 0; i < n; ++i) {
      thing t;
      t.read(i);
      data.insert(t);
    }

    int total_size = 0;

    auto comp = [](const thing& l, const thing& r) {
      return l.n < r.n;
    };
    std::multiset<thing, decltype(comp)> out(comp);

    for (const auto& i : data) {
      if (total_size + i.size <= size) {
        total_size += i.size;
        out.insert(i);
      }
    }

    for (const auto& i : out)
      std::cout << i.n << " ";

  }

} // !namespace

#endif // !__TASK21D_HPP__