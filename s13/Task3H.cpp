#include <iostream>
#include <fstream>
#include <set>
#include <vector>
#include <algorithm>

#define TESTING

#ifdef TESTING
  #define INIT_INPUT
  #define INPUT_STREAM std::cin
#else
  #define INIT_INPUT std::ifstream ifs("input.txt");
  #define INPUT_STREAM ifs
#endif // TESTING

struct flowerbed {
  unsigned l = 0;
  unsigned r = 0;
  bool operator < (const flowerbed& rhs) const{
    if (l == rhs.l)
      return (r < rhs.r);
    return l < rhs.l;
  }
  bool in(unsigned pt) const{
    return (pt >= l && pt <= r);
  }
  bool intersect(const flowerbed& rhs) const{
    if (in(rhs.l) || in(rhs.r))
      return true;
    if (rhs.in(l) || rhs.in(r))
      return true;
    return false;
  }
  flowerbed merge(const flowerbed& rhs) {
    return flowerbed{
      std::min(l, rhs.l),
      std::max(r, rhs.r)
    };
  }

};

//-31H-//
int main()
{
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);

  INIT_INPUT;

  unsigned n;

  INPUT_STREAM >> n;

  if (n < 1u) {
    return 0;
  }

  std::vector<flowerbed> data;
  data.reserve(n);

  for (unsigned i = 0u; i < n; ++i) {
    flowerbed t;
    INPUT_STREAM >> t.l >> t.r;
    bool push = true;

    for (auto& f : data) {
      if (t.intersect(f)) {
        f = f.merge(t);
        push = false;
        break;
      }
    }
    if (push)
      data.push_back(t);
  }

  std::sort(data.begin(), data.end());

  for (unsigned i = 0u; i < data.size()-1; ++i) {
    if (data[i].intersect(data[i + 1])) {
      auto m = data[i].merge(data[i + 1]);
      data[i] = m;
      data[i + 1] = m;
    }
  }

  std::set< flowerbed> datas(data.begin(), data.end());

  for (const auto& f : datas) {
    std::cout << f.l << " " << f.r << "\n";
  }

  return 0;
}