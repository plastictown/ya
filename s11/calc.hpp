#pragma once
#ifndef __CALC_HPP__
#define __CALC_HPP__

//#include "deque-fixed.hpp"
#include "task-final1-stack.hpp"

#include <string>
#include <sstream>

namespace DomchenkovMA {

  struct calc {
  public:
    calc(unsigned max):
      _data{max}
    {}
    int calculate(std::string& s) {
      std::stringstream ss(s);
      std::string tmp;

      while (ss >> s) {
        if (s.empty()) continue;
        if (is_val(s)) {
          int val = std::stoi(s);
          _data.push(val);
        }
        else {
          process_op(s[0]);
        }
      }// !while

      int ret;
      _data.pop(ret);
      return ret;

  }// !calculate

  private:

    bool is_val(const std::string& s) {
      for (auto c : s) {
        if (c >= '0' && c <= '9') return true;
      }
      return false;
    }

    void process_op(char op) {
      int larg, rarg, res = 0;

      _data.pop(rarg);
      _data.pop(larg);

      switch (op) {
      case '+':
        res = larg + rarg;
        break;
      case '-':
        res = larg - rarg;
        break;
      case '/':
        res = larg / rarg;
        break;
      case '*':
        res = larg * rarg;
        break;
      }
      _data.push(res);
    }

    stack<int> _data;
  };

}
#endif // !__CALC_HPP__
