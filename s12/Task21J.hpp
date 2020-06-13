#pragma once
#ifndef __TASK21J_HPP__
#define __TASK21J_HPP__

#include <iostream>
#include <string>
#include <algorithm>
#include <sstream>

namespace DomchenkovMA {

  int solution() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    std::string s, s1;
    std::getline(std::cin, s);
    std::reverse(s.begin(), s.end());
    std::stringstream ss(s);
    s.clear();
    ss >> s1;
    ss.clear();

    std::cout << s1.length();

    return 0;
  }

} // !namespace

#endif // !__TASK21J_HPP__