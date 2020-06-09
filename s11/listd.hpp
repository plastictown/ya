#pragma once

#ifndef __LISTD_HPP__
#define __LISTD_HPP__

#include <string>
#include <iostream>

template<typename T>
struct NodeD {
  NodeD* prev = nullptr;
  NodeD* next = nullptr;
  T data;
};

template<typename T>
NodeD<T>* listd_push_front(NodeD<T>* head, const T& data) {
  using node_type = NodeD<T>;
  node_type* n = new node_type;

  // create new list if empty
  if (head == nullptr) {
    n->prev = nullptr;
    n->next = nullptr;
    n->data = data;
    return n;
  }

  head->prev = n;
  n->next = head;
  n->prev = nullptr;
  n->data = data;
  return n;
}

template<typename T>
NodeD<T>* listd_pop_front(NodeD<T>* head) {
  // null pointer
  if (head == nullptr) return nullptr;
  // single object
  if (head->next == nullptr) { delete head; return nullptr; }
  // general case
  NodeD<T>* ret = head->next;
  ret->prev = nullptr; 
  delete head;
  return ret;
}

template<typename T>
void listd_clear(NodeD<T>* head) {
  if (head == nullptr) return;
  if (head->next == nullptr) { delete head; return; }

  NodeD<T>* h = head;

  do {
    NodeD<T>* next = h->next;
    delete h;
    h = next;
  } while (h);
}

template<typename T>
void listd_print(NodeD<T>* head, bool newline) {
  if (head == nullptr) return;
  if (head->next == nullptr)
  { std::cout << head->data; return; }

  NodeD<T>* h = head;
  do {
    if (newline) std::cout << h->data << std::endl;
    else std::cout << h->data << " ";
    h = h->next;
  } while (h);
  if (!newline)std::cout << std::endl;
}

#endif // !__LISTD_HPP__
