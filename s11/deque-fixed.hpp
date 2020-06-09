#pragma once
#ifndef __DEQUE_FIXED_HPP__
#define __DEQUE_FIXED_HPP__

#include <vector>
#include "task-final1-stack.hpp"

namespace DomchenkovMA {

template<typename T>
  struct deque {

  public:

    deque(unsigned sz) :
      max_size{ sz },
      size{ 0u },
      head{ 0u },
      tail{ 1u }
    { data.resize(sz); }

    bool push_back(const T& val) {
      if (full()) return false;
      data[tail] = val;
      tail = next(tail);
      ++size;
      return true;
    }
    bool push_front(const T& val) {
      if (full()) return false;
      data[head] = val;
      head = prev(head);
      ++size;
      return true;
    }

    bool pop_back() {
      if (empty()) return false;
      tail = prev(tail);
      --size;
      return true;
    }
    bool pop_front() {
      if (empty()) return false;
      head = next(head);
      --size;
      return true;
    }

    const T* front() const {
      if (empty()) return nullptr;
      return (data.data() + next(head));
    }

    const T* back() const {
      if (empty()) return nullptr;
      return (data.data() + prev(tail));
    }
    bool empty() const {
      return size == 0u;
    }

    unsigned get_size() const { return size; }

  private:

    //- methods -//

    unsigned next(unsigned i) const {
      return (i + 1) % max_size;
    }
    unsigned prev(unsigned i) const {
      return (max_size + i - 1u) % max_size;
    }
    bool full() const {
      return size == max_size;
    }

    //- fields -//

    unsigned max_size;
    unsigned size;
    std::vector<T> data;
    unsigned head, tail;

  }; // ! deque;

  /*template<typename T>
  struct stack {
  public:
    stack(unsigned sz) 
      : data{sz}{}

    bool push(const T& val) {
      return data.push_back(val);
    }
    bool pop(T& out) {
      if (data.empty())
        return false;
      out = *data.back();
      data.pop_back();
      return true;
    }
    bool empty() const { return data.empty(); }
    unsigned get_size() const { 
      return data.get_size(); 
    }
  private:
    deque<T> data;
  };*/

  template<typename T>
  struct DoubleStackQueue {
  public:

    DoubleStackQueue(unsigned sz):
      left{sz},
      right{ sz }
    {}

    void push(const T& val) {
      left.push(val);
    }
    bool pop(T& val) {
      if (left.empty() && right.empty())
        return false;
      if (right.empty()) {
        T temp;
        while (left.pop(temp))
          right.push(temp);
      }
      right.pop(val);
      return true;
    }

    unsigned get_size() const{
      return left.get_size() + right.get_size();
    }
  private:
    stack<T> left, right;
  };

} // ! DomchenkovMA

#endif // !__DEQUE_FIXED_HPP__
