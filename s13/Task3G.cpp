#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

#ifdef TESTING
  #define INIT_INPUT
  #define INPUT_STREAM std::cin
#else
  #define INIT_INPUT std::ifstream ifs("input.txt");
  #define INPUT_STREAM ifs
#endif // TESTING

//-31G-//
int main()
{
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);

  INIT_INPUT;

  unsigned n;

  INPUT_STREAM >> n;

  if (n < 3u) {
    std::cout << 0;
    return 0;
  }

  std::vector<unsigned> data;
  data.reserve(n);

  for (unsigned i = 0u; i < n; ++i) {
    unsigned t;
    INPUT_STREAM >> t;
    data.push_back(t);
  }

  std::sort(data.rbegin(), data.rend());

  auto check = [](unsigned a, unsigned b, unsigned c)->bool {
    return (a < (b + c) && b < (a + c) && c < (a + b));
  };

  unsigned P = 0u;
  unsigned p = 0;

  for (unsigned a = 0u; a < data.size() - 2u; ++a) {
    for (unsigned b = a + 1u; b < data.size() - 1u; ++b) {
      for (unsigned c = b + 1; c < data.size(); ++c) {
        if (!check(data[a], data[b], data[c])) continue;
        unsigned p = data[a] + data[b] + data[c];
        if (p > P)P = p;
      }
      if (p < P) break;
    }
    if (p < P) break;
  }

  std::cout << P;
 
  return 0;
}