#include <iostream>
#include <fstream>
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


//-31J-//
int main()
{
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);

  INIT_INPUT;

  unsigned n;

  INPUT_STREAM >> n;

  std::vector<int> data;
  data.reserve(n);

  for (unsigned i = 0u; i < n; ++i) {
    int t;
    INPUT_STREAM >> t;
    data.push_back(t);
  }

  unsigned m;

  INPUT_STREAM >> m;

  std::vector<int> pattern;
  pattern.reserve(m);

  for (unsigned i = 0u; i < m; ++i) {
    int t;
    INPUT_STREAM >> t;
    pattern.push_back(t);
  }

  auto pred = [pattern](const int& l, const int& r)->bool {
    auto il = std::find(pattern.cbegin(), pattern.cend(), l);
    auto ir = std::find(pattern.cbegin(), pattern.cend(), r);
    if (il != pattern.cend() && ir != pattern.cend())
      return il < ir;
    if (il == pattern.cend() && ir == pattern.cend())
      return l < r;
    if (il == pattern.cend() && ir != pattern.cend())
      return false;
    return true;
  };

  std::sort(data.begin(), data.end(), pred);

  for (unsigned i = 0u; i < data.size(); ++i) {
    std::cout << data[i] << " ";
  }

  return 0;
}