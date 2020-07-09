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

//-31A-//
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

  for (unsigned i = 0; i < n; ++i) {
    for (unsigned j = i + 1; j < n; ++j) {
      if (data[i] > data[j])
        std::swap(data[i], data[j]);
    }
  }

  for (auto i : data)
    std::cout << i << " ";

  return 0;
}