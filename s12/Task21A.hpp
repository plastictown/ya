#pragma once
#ifndef __TASK21A_HPP__
#define __TASK21A_HPP__

#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

namespace DomchenkovMA {

  struct lesson {
    double begin;
    double end;
    // sort by end
    bool operator < (const lesson& rhs) const {
      if (end == rhs.end) return begin < rhs.begin;
      return end < rhs.end;
    }
    bool operator == (const lesson& rhs)const {
      return (begin == rhs.begin && end == rhs.end);
    }
    // intersection
    bool boom(const lesson& rhs) const {
      // two null-time lessons-> no intersection
      if ((!*this) && (!rhs)) return false;
      // equal lessons -> intersection
      if (*this == rhs) return true;
      // At least one point in other lesson
      if (pt_in(rhs.begin) || pt_in(rhs.end))
        return true;
      if (rhs.pt_in(begin) || rhs.pt_in(end))
        return true;
      // no intersection
      return false;
    }
    // null-time lesson
    bool operator !() const {
      return begin == end;
    }
    // timepoint in me
    bool pt_in(double val) const {
      if (val > begin && val < end)
        return true;
      return false;
    }
  };

  void solution() {
    unsigned n;
    std::cin >> n;

    // lessons sorted by end
    std::multiset<lesson> lessons;

    // comparator for result vector
    auto comp = [](const lesson& l, const lesson& r)
    {
      if (l.begin == r.begin) return l.end < r.end;
      return l.begin < r.begin;
    };

    std::vector<lesson> results;
    std::vector<lesson> ntls;

    for (unsigned i = 0u; i < n; ++i) {
      lesson l;
      std::cin >> l.begin >> l.end;
      lessons.insert(l);
    }

    results.push_back(*lessons.cbegin());
    if (!(*lessons.cbegin())) ntls.push_back(*lessons.cbegin());
    lessons.erase(lessons.begin());

    for (const auto& l : lessons) {
      if (results.back().boom(l))
        continue;
      if (!l)ntls.push_back(l);
      results.push_back(l);
    }

    lessons.clear();
    std::set<lesson, decltype(comp)> out(comp);
    for (const auto& r : results) {
      if (!r) continue;
      out.insert(r);
    }
    results.clear();

    for (const auto& o : out) {
      results.push_back(o);
    }
    out.clear();
    for (const auto& n : ntls) {
      results.push_back(n);
    }
    ntls.clear();

    std::sort(
      results.begin(),
      results.end(),
      [](const lesson& l, const lesson& r) {
        if (l.begin == r.begin) return l.end < r.end;
        return l.begin < r.begin;
      });

    std::cout << results.size() << "\n";
    for (const auto& v : results) {
      std::cout << v.begin << " " << v.end << "\n";
    }
  }

} // !namespace

#endif // !__TASK21A_HPP__