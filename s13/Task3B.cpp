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

//-31B-//
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

  if (n == 1u) {
    std::cout << n;
    return 0;
  }

  std::vector<int> data;
  data.reserve(n);

  for (unsigned i = 0u; i < n; ++i) {
    int t;
    INPUT_STREAM >> t;
    data.push_back(t);
  }

  for (unsigned i = 1u; i < n; ++i) {
    for (int j = i - 1; j >= 0; --j) {
      if (data[j] <= data[j + 1]) break;
      std::swap(data[j], data[j + 1]);
    }
  }
  
  for (auto i : data)
    std::cout << i << " ";

  return 0;
}