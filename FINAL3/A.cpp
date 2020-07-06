//------  solution id 33587352  ------//

#include <iostream>
#include <fstream>
#include <algorithm>
#include <cmath>
#include <set>

#ifdef TESTING
  #define INIT_INPUT
  #define INPUT_STREAM std::cin
#else
  #define INIT_INPUT std::ifstream ifs("input.txt");
  #define INPUT_STREAM ifs
#endif // TESTING

struct Comp {

  unsigned ndigits(unsigned long long n) const{
    unsigned divisor = 1u;
    unsigned ret = 0u;
    while (n / divisor) {
      ++ret;
      divisor *= 10u;
    }
    return ret;
  }

  bool operator()(const unsigned& l, const unsigned& r) const{
    if (l == r) return false;
    unsigned long long val[2] = { l,r };
    unsigned len[2] = { ndigits(l), ndigits(r) };

    if (len[0] == len[1])
      return l < r;

    //-find short--//
    unsigned min_idx = 0u;
    unsigned max_idx = 1u;

    if (len[1] < len[0]) {
      min_idx = 1u;
      max_idx = 0u;
    }

    //-black magic-//
    val[min_idx] = val[min_idx] * std::pow(10, len[min_idx]) + val[min_idx];
    val[max_idx] = val[max_idx] * std::pow(10, len[max_idx]) + val[max_idx];

    len[0] *= 2u;
    len[1] *= 2u;

    //-normalize-//
      val[min_idx] *= std::pow(10u , (len[max_idx] - len[min_idx]));

    //-compare-//
      if (val[0] == val[1])
        return min_idx == 1u;
      else
        return val[0] < val[1];
  }
};

//-3-FINAL-A-//
int main()
{
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);

  INIT_INPUT;

  unsigned n;

  INPUT_STREAM >> n;

  if (n == 0u) {
    return 0;
  }
  bool only_zeros = true;
  std::multiset<unsigned, Comp> data;
  for (unsigned i = 0u; i < n; ++i) {
    unsigned t;
    INPUT_STREAM >> t;
    if (t != 0u) only_zeros = false;
    data.insert(t);
  }
  if (only_zeros) {
    std::cout << 0;
    return 0;
  }
  for (auto i=data.crbegin(); i!=data.crend(); ++i)
    std::cout << *i;
 
  return 0;
}