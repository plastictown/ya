#pragma once

#ifndef __MISC_HPP__
#define __MISC_HPP__

#include <list>
#include <string>
#include <vector>

void normalize(std::list<unsigned>& l, std::list<unsigned>& r);
bool list_sum(std::list<unsigned>& l, std::list<unsigned>& r, unsigned radix);
void remove_zeros(std::list<unsigned>& l);
bool is_anagram(const std::string& l, const std::string& r);
bool next(std::map<unsigned, std::string>& keys, std::vector<unsigned>& in, std::vector<unsigned>& cur);

bool next(std::map<unsigned, std::string>& keys, std::vector<unsigned>& in, std::vector<unsigned>& cur) {
  bool cf = true;
  for (int i = cur.size() - 1; i >= 0; --i) {

    if (i == 0 && cur[i] == (keys[in[i]].size() - 1) && cf)
      return false;

    if (cf) {
      if (cur[i] != (keys[in[i]].size() - 1))
      {
        ++cur[i]; return true;
      }
      else
      {
        cur[i] = 0; cf = true;
      }
    }

  }
  return true;
}

bool is_anagram(const std::string& l, const std::string& r) {
  if (l.size() != r.size()) return false;
  std::multiset<char>
    m1(l.cbegin(), l.cend()),
    m2(r.cbegin(), r.cend());
  return (m1 == m2);
}

void normalize(std::list<unsigned>& l, std::list<unsigned>& r) {
  if (l.size() == r.size())
    return;
  if (l.size() > r.size()) {
    size_t delta = l.size() - r.size();
    r.insert(r.begin(), delta, 0);
  }
  else {
    size_t delta = r.size() - l.size();
    l.insert(l.begin(), delta, 0);
  }
}

void remove_zeros(std::list<unsigned>& l) {
  if (l.empty()) return;
  auto it = l.begin();
  for (; it != l.cend(); ++it) {
    if (*it != 0) break;
  }
  l.erase(l.begin(), it);
}

bool list_sum(std::list<unsigned>& l, std::list<unsigned>& r, unsigned radix) {
  if (radix < 2) return false;
  if (l.size() != r.size()) normalize(l, r);

  bool cf = false;
  auto li = l.rbegin();
  auto ri = r.rbegin();

  for (; li != l.rend(); ++li, ++ri) {
    unsigned t = *li + *ri;
    if (cf) ++t, cf = false;
    if (t >= radix) t = t % radix, cf = true;
    *li = t;
  }
  if (cf) l.push_front(1);
  return true;
}

int type(char b) {
  if (b == '(' || b == ')') return 1;
  if (b == '{' || b == '}') return 2;
  if (b == '[' || b == ']') return 3;
  return -1;
}

int direction(char b) {
  if (b == '(' || b == '{' || b == '[') return 1;
  if (b == ')' || b == '}' || b == ']') return 2;
  return -1;
}

bool is_correct_bracket_seq(const std::string& s) {
  if (s.empty()) return true;
  std::vector<char> v;
  v.reserve(s.length());

  for (auto c : s) {
    if (direction(c) == 1)
      v.push_back(c);
    else {
      if (v.empty()) return false;
      if (type(c) != type(v.back())) return false;
      v.pop_back();
    }
  }
  return v.empty();
}


#endif // !__MISC_HPP__
