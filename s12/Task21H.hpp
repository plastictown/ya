#pragma once
#ifndef __TASK21H_HPP__
#define __TASK21H_HPP__

#include<iostream>

namespace DomchenkovMA {

  int solution() {
    int size;
    std::cin >> size;

    if (size < 2) {
      std::cout << size;
      return 0;
    }

    int last; std::cin >> last;
    int max_sz = 1;
    int cur_sz = 1;

    for (unsigned i = 1; i < size; ++i) {
      int c; std::cin >> c;
      if (c > last) {
        ++cur_sz;
        if (cur_sz > max_sz)
          max_sz = cur_sz;
      }
      else {
        cur_sz = 1;
      }
      last = c;
    }

    std::cout << max_sz;
  }

} // !namespace

#endif // !__TASK21H_HPP__