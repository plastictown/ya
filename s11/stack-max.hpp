#pragma once
#ifndef __STACK_MAX_HPP__
#define __STACK_MAX_HPP__

#include "listd.hpp"

#include <iostream>
#include <string>

struct StackMax {
public:
  void push(int data) {
    bool first = (head == nullptr);
    if (first) {
      max = data; max_cached = true;
    }
    head = listd_push_front(head, data);
    if (!first && max_cached)
    {
      max = (data > max) ? data : max;
    }
  }
  bool pop(){
    max_cached = false;
    if (head == nullptr) return false;
    head = listd_pop_front(head);   
  }
  void read_and_execute() {
    std::string cmd;
    int val = 0;
    std::cin >> cmd;
    if (cmd == "push") {
      std::cin >> val;
      push(val);
      return;
    }
    if (cmd == "pop") {
      if (head == nullptr)
        std::cout << "error\n";
      else head = listd_pop_front(head);
      return;
    }
    // getmax;
    if (head == nullptr) {
      std::cout << "None\n"; 
      return;
    }
    max = head->data;
    NodeD<int>* h = head;
    do {
      if (h->data > max) { max = h->data; max_cached = true; }
      h = h->next;
    } while (h);

    std::cout << max << "\n";
  }
  ~StackMax() {
    listd_clear(head);
  }

private:
  NodeD<int>* head = nullptr;
  int max = 0;
  bool max_cached = false;
};


#endif // !__STACK_MAX_HPP__
