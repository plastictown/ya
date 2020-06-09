#pragma once
#ifndef __TASK_P_QUEUE_HPP__
#define __TASK_P_QUEUE_HPP__

#include <string>
#include <iostream>
#include "double-linked-list.hpp"

struct TaskPQueue {
public:
  void read_and_execute() {
    bool empty = data.empty();
    std::string cmd;
    int val = 0;
    std::cin >> cmd;
    if (cmd == "put") {
      std::cin >> val;
      data.push_front(val);
      return;
    }
    if (cmd == "get") {
      if (empty) {
        std::cout << "error\n";
        return;
      }
      std::cout << *data.back() << "\n";
      data.pop_back();
      return;
    }

    // size

    std::cout << data.size() << "\n";
  }
private:
  DomchenkovMA::DoubleLinkedList<int> data;
};

#endif // !__TASK_P_QUEUE_HPP__
