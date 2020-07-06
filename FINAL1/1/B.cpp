
//------  solution id 33353111  ------//

#include "solution.h"
#include <memory>

bool HasCycle(std::shared_ptr<Node> head) {
    if (!head) return false;
    if (head->next.expired()) return false;
    if (head->next.lock() == nullptr) return false;

    auto p1 = head, p2 = head;

    do {
      if (p1->next.expired()) return false;
      p1 = p1->next.lock();
      if (p1 == nullptr) return false;

      if (p2->next.expired()) return false;
      p2 = p2->next.lock();
      if (p2 == nullptr) return false;
      if (p2->next.expired()) return false;
      p2 = p2->next.lock();
      if (p2 == nullptr) return false;

      if (p1 == p2) return true;
    } while (p1 && p2);
    return false;
  }