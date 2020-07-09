#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <set>

#ifdef TESTING
  #define INIT_INPUT
  #define INPUT_STREAM std::cin
#else
  #define INIT_INPUT std::ifstream ifs("input.txt");
  #define INPUT_STREAM ifs
#endif // TESTING

//-31C-//
int main()
{
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);

  INIT_INPUT;

  unsigned m, n;

  INPUT_STREAM >> m >> n;

  if (n < 1u || m <1u) {
    return 0;
  }

  std::vector<int> data1;
  data1.reserve(m);
  std::set<int> data2;

  for (unsigned i = 0u; i < m; ++i) {
    int t;
    INPUT_STREAM >> t;
    data1.push_back(t);
  }

  for (unsigned i = 0u; i < n; ++i) {
    int t;
    INPUT_STREAM >> t;
    data2.insert(t);
  }

  std::vector<int> out;
  std::set<int> outs;

  for (auto i : data1) {
    auto it = data2.find(i);
    if (it != data2.cend()) {
      auto res = outs.insert(i);
      if (res.second)
        out.push_back(i);
    }
  }

  for (auto i : out)
    std::cout << i << " ";

  return 0;
}