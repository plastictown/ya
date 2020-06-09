#pragma once
#ifndef __TASK_M_QUEUE_HPP__
#define __TASK_M_QUEUE_HPP__

#include <string>
#include <iostream>
#include "double-linked-list.hpp"

struct TaskMQueue { 
public:
  void read_and_execute() {
    bool empty = data.empty();
    std::string cmd;
    int val = 0;
    std::cin >> cmd;
    if (cmd == "push") {
      std::cin >> val;
      data.push_front(val);
      return;
    }
    if (cmd == "pop") {
      if (empty) {
        std::cout << "None\n";
        return;
      }
      std::cout << *data.back() << "\n";
      data.pop_back();
      return;
    }
    if (cmd == "peek") {
      if (empty) std::cout << "None\n";
      else std::cout << *data.back() << "\n";
      return;
    }
    // size

    std::cout << data.size() << "\n";
  }
private:
  DomchenkovMA::DoubleLinkedList<int> data;
};

#endif // !__TASK_M_QUEUE_HPP__
