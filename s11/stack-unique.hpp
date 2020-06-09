#pragma once
#ifndef __STACK_UNIQUE_HPP__
#define __STACK_UNIQUE_HPP__

#include "listd.hpp"

#include <iostream>
#include <string>
#include <unordered_set>

struct StackSet {
public:

  StackSet():
    head{nullptr},
    size{0u}
  {}

  StackSet(unsigned sz):
    head{ nullptr },
    size{ 0u }
  {
    vals.reserve(sz);
  }

  void push(int data) {
    auto [it, b] = vals.insert(data);
    if (!b) return;
    head = listd_push_front(head, data);
    ++size;
  }
  bool pop(){
    if (head == nullptr) return false;
    vals.erase(head->data);
    head = listd_pop_front(head);
    --size;
    return true;
  }

  void read_and_execute() {
    bool empty = (head == nullptr);
    std::string cmd;
    int val = 0;
    std::cin >> cmd;
    if (cmd == "push") {
      std::cin >> val;
      push(val);
      return;
    }
    if (cmd == "pop") {
      /*
      if (empty)
        std::cout << "error\n";
      else head = listd_pop_front(head);
      */
      if (!pop()) std::cout << "error\n";
      return;
    }
    if (cmd == "peek") {
      if (empty) std::cout << "error\n";
      else std::cout << head->data << "\n";
      return;
    }
   // size
    std::cout << size << "\n";
  }
  ~StackSet() {
    listd_clear(head);
    size = 0u;
  }

private:
  NodeD<int>* head = nullptr;
  size_t size = 0u;
  std::unordered_set<int> vals;
};


#endif // !__STACK_UNIQUE_HPP__
