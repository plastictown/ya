#pragma once
#ifndef __LISTS_HPP__
#define __LISTS_HPP__

#include <string>
#include <iostream>

struct Node {
  std::string data;
  struct Node* next = nullptr;
};

Node* list_get_tail(Node* h) {
  if (h == nullptr) return nullptr;
  if (h->next == nullptr) return h;
  Node* head = h;
  while (head->next) head = head->next;
  return head;
}

Node* list_push_back(Node* head, const std::string& s) {
  Node* tail = list_get_tail(head);
  if (tail == nullptr) return nullptr;

  tail->next = new Node;
  tail->next->data = s;
  return tail->next;
}

void list_clear(Node* head) {
  if (head == nullptr) return;
  if (head->next == nullptr) { delete head; return; }
  Node* h = head;
  while (h->next) {
    Node* next = h->next;
    delete h;
    h = next;
  }
  delete h;
}

Node* list_reverse(Node* head) {

  if (head == nullptr) return nullptr;
  if (head->next == nullptr) return head;

  Node* prev = nullptr;
  Node* cur = head;
  Node* next = head->next;

  while (cur->next) {
    next = cur->next;
    cur->next = prev;
    prev = cur;
    cur = next;
  }
  cur->next = prev;
  return cur;
}

size_t list_size(Node* head) {
  if (head == nullptr) return 0u;

  size_t cnt = 0;
  Node* h = head;
  do {
    ++cnt;
    h = h->next;
  } while (h);

  return cnt;
}

Node* list_remove_at(Node* head, size_t pos) {
  // illegal pointer
  if (head == nullptr) return nullptr;
  // invalid index
  if (head->next == nullptr && pos != 0u) return nullptr;

  // remove first
  if (head->next == nullptr || pos == 0u) {
    Node* next = head->next;
    delete head;
    return next;
  }

  //size_t sz = list_size(head);

  Node* h = head;
  Node* prev = nullptr;
  // Node* next = head->next;

  size_t cnt = 0;
  do {
    if (cnt == pos) {
      prev->next = h->next;
      delete h;
      break;
    }
    ++cnt;
    prev = h;
    h = h->next;
  } while (h);
  return head;
}

void list_print(Node* head, bool newline = false) {
  if (head == nullptr) return;
  Node* h = head;

  do {
    if (newline)std::cout << h->data << std::endl;
    else std::cout << h->data << " ";
    h = h->next;
  } while (h);
  if (!newline) std::cout << std::endl;
}

Node* list_push_front(Node* head, const std::string& data) {
  if (head == nullptr) return nullptr;

  Node* n = new Node;
  n->data = data;
  n->next = head;
  return n;
}

int list_find_at(Node* head, const std::string& data) {

  if (head == nullptr) return -1;

  Node* h = head;
  int cnt = 0;

  do {
    if (h->data == data)
      return cnt;
    ++cnt;
    h = h->next;
  } while (h);

  return -1;
}

#endif // !__LISTS_HPP__