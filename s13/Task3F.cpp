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

//-31F-//
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

  std::vector<int> data;
  data.reserve(n);

  for (unsigned i = 0u; i < n; ++i) {
    int t;
    INPUT_STREAM >> t;
    data.push_back(t);
  }

  unsigned half_size = data.size() / 2u;
  std::vector<int> even, odd; 
  even.reserve(half_size);
  odd.reserve(half_size);

  for (unsigned i = 0u; i < n; ++i) {
    if (data[i] % 2 == 0u)
      even.push_back(data[i]);
    else
      odd.push_back(data[i]);
  }

  std::reverse(even.begin(), even.end());
  std::reverse(odd.begin(), odd.end());

  for (unsigned i = 0u; i < n; ++i) {
    if (i % 2 == 0u) {
      data[i] = even.back();
      even.pop_back();
    }
    else {
      data[i] = odd.back();
      odd.pop_back();
    }
    std::cout << data[i] << " ";
  }

  return 0;
}