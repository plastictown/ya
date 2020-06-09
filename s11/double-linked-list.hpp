#pragma once
#ifndef __DOUBLE_LINKED_LIST_HPP__
#define __DOUBLE_LINKED_LIST_HPP__

//#include "listd.hpp"
#include <iostream>

namespace DomchenkovMA {

  template<typename T>
  struct NodeD {
    NodeD* prev = nullptr;
    NodeD* next = nullptr;
    T data;
  };

  template<typename T>
  struct DoubleLinkedList {
    using node_type = NodeD<T>;
  public:
    DoubleLinkedList() :
      head{ nullptr },
      tail{ nullptr },
      sz{ 0u }
    {}

    ~DoubleLinkedList() {
      clear();
    }

    T* back() const {
      if (empty()) return nullptr;
      return &(tail->data);
    };

    T* front() const {
      if (empty()) return nullptr;
      return &head->data;
    }

    void push_front(const T& data) {
      if (empty()) { create_first(data); return; }
      node_type* n = new node_type;
      n->prev = nullptr;
      n->next = head;
      n->data = data;
      head->prev = n;
      head = n;
      ++sz;
    }
    void push_back(const T& data) {
      if (empty()) { create_first(data); return; }

      tail->next = new node_type;
      tail->next->prev = tail;
      tail->next->data = data;
      tail->next->next = nullptr;
      tail = tail->next;
      ++sz;
      return;
    }

    bool pop_front() {
      if (empty()) return false;

      if (head->next == nullptr) {
        delete head;
        head = nullptr;
        sz = 0u;
        return true;
      }
      node_type* thead = head->next;
      head->next->prev = nullptr;
      delete head;
      head = thead;
      --sz;
      return true;
    }
    bool pop_back() {
      if (empty()) return false;
      if (head->next == nullptr) {
        delete head;
        head = nullptr;
        sz = 0u;
        return true;
      }
      node_type* ttail = tail->prev;
      tail->prev->next = nullptr;
      delete tail;
      tail = ttail;
      --sz;
      return true;
    }

    size_t size() const { return sz; }
    bool  empty() const { return sz == 0u; }

    void print(bool newline) {
      if (head == nullptr) return;
      if (head->next == nullptr) {
        std::cout << head->data;
        if (newline) std::cout << "\n";
        return;
      }
      node_type* h = head;

      do {
        if (newline) std::cout << h->data << "\n";
        else std::cout << h->data << " ";
        h = h->next;
      } while (h);
    }

  private: // methods

    void create_first(const T& data) {
      head = new node_type;
      head->data = data;
      head->next = nullptr;
      head->prev = nullptr;
      tail = head;
      ++sz;
    }

    void clear() {
      if (head == nullptr) {
        head = nullptr;
        tail = nullptr;
        sz = 0;
        return;
      }
      node_type* h = head;
      do {
        node_type* next = h->next;
        delete h;
        h = next;
      } while (h);
      head = nullptr;
      tail = nullptr;
      sz = 0;
    }

  private: // fields
    node_type* head, * tail;
    size_t sz;
  };
}
#endif // !__DOUBLE_LINKED_LIST_HPP__
