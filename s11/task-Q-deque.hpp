#pragma once
#ifndef __TASK_Q_DEQUE_HPP__
#define __TASK_Q_DEQUE_HPP__

#include <vector>

namespace DomchenkovMA {

  struct TaskQDeque {
  public:

    void read_and_execute() {
      std::string cmd;
      int val = 0;
      std::cin >> cmd;

      if (cmd == "push_front") {
        std::cin >> val;
        if (!push_front(val))
          std::cout << "error\n";
        return;
      }
      if (cmd == "push_back") {
        std::cin >> val;
        if (!push_back(val))
          std::cout << "error\n";
        return;
      }
      if (cmd == "pop_front") {
        auto val = front();
        if (!val) {
          std::cout << "error\n";
          return;
        }
        std::cout << *val << "\n";
        pop_front();
        return;
      }
      if (cmd == "pop_back") {
        auto val = back();
        if (!val) {
          std::cout << "error\n";
          return;
        }
        std::cout << *val << "\n";
        pop_back();
        return;
      }
    }

  public:

    TaskQDeque(unsigned sz) :
      max_size{ sz },
      size{ 0u },
      head{ 0u },
      tail{ 1u }
    { data.resize(sz); }

    bool push_back(int val) {
      if (full()) return false;
      data[tail] = val;
      tail = next(tail);
      ++size;
      return true;
    }
    bool push_front(int val) {
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

    const int* front() const {
      if (empty()) return nullptr;
      return (data.data() + next(head));
    }

    const int* back() const {
      if (empty()) return nullptr;
      return (data.data() + prev(tail));
    }

  private:

    //- methods -//

    unsigned next(unsigned i) const {
      return (i + 1) % max_size;
    }
    unsigned prev(unsigned i) const {
      return (max_size + i - 1u)%max_size;
    }
    bool full() const {
      return size == max_size;
    }
    bool empty() const {
      return size == 0u;
    }
    //- fields -//

    unsigned max_size;
    unsigned size;
    std::vector<int> data;
    unsigned head, tail;

  }; // ! TaskQDeque;

} // ! DomchenkovMA



#endif // !__TASK_Q_DEQUE_HPP__
