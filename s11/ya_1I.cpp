#include <iostream>
#include <string>
#include <cstdint>
#include <list>
#include <cstring>
#include <set>
#include <sstream>
#include <map>
#include <vector>
#include <algorithm>
#include <locale>

#include <cstdio>

#include "lists.hpp"
#include "misc.hpp"
//#include "listd.hpp"
//#include "stack-max.hpp"
//#include "stack-unique.hpp"
//#include "double-linked-list.hpp"
//#include "task-Q-deque.hpp"
#include "deque-fixed.hpp"
#include "calc.hpp"

bool is_anagram(const std::string& l, std::multiset<char>& r) {
  std::multiset<char>
    m1(l.cbegin(), l.cend());
  if (m1.size() != r.size()) return false;
  return (m1 == r);
}

int main() { //--------MAIN---------//

  std::cin.tie(nullptr);
  std::ios_base::sync_with_stdio(false);

  unsigned ncmd;
  std::string s;
  std::cin >> ncmd;
  std::getline(std::cin, s);

  DomchenkovMA::DoubleStackQueue<int> q{ ncmd };

  for (unsigned i = 0u; i < ncmd; ++i) {
    std::string cmd;
    int val;
    std::cin >> cmd;
    if (cmd == "put") {
      std::cin >> val;
      q.push(val);
      continue;
    }
    if (cmd == "get") {
      if (q.pop(val)) std::cout << val << "\n";
      else std::cout << "error\n";
      continue;
    }
    // get_size
    std::cout << q.get_size() << "\n";
  }

  return 0;
} //-!------MAIN---------//