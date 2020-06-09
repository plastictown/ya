#pragma once
#ifndef __TASK_FINAL1_STACK_HPP__
#define __TASK_FINAL1_STACK_HPP__

#include <vector>

namespace DomchenkovMA
{

  template<typename T>
  struct stack {
  public:
    stack(unsigned sz)
    {
      data.reserve(sz);
    }

    void push(const T& val) {
      data.push_back(val);
    }
    bool pop(T& out) {
      if (data.empty())
        return false;
      out = data.back();
      data.pop_back();
      return true;
    }
    bool empty() const { return data.empty(); }
    unsigned get_size() const {
      return data.size();
    }
  private:
    std::vector<T> data;
  };

}

#endif // !__TASK_FINAL1_STACK_HPP__
