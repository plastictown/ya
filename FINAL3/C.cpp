//------  solution id 33592827  ------//

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

using value_type = unsigned;

void radix_sort(std::vector<value_type>& data, int to) {
  value_type mask = 1u;
  auto pred = [&mask](const value_type& l, const value_type& r)->bool {
    return (r & mask && !(l & mask));
  };
    do {
      std::stable_sort(data.begin(), data.end(), pred);
      --to;
      mask <<= 1u;
    } while (to >=0 );
}

//-3-FINAL-C-//
int main()
{
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);

  INIT_INPUT;
  
  const unsigned type_len = sizeof(value_type) * 8u;

  value_type n;

  INPUT_STREAM >> n;

  std::vector<std::vector<value_type>> data(type_len + 1u);

  for (unsigned i = 0u; i < n; ++i) {
    unsigned t;
    INPUT_STREAM >> t;
    if (t == 0u) { 
      data[0].push_back(t); 
      continue;
    }
    unsigned c = type_len - 1u;
    value_type mask = 1u << (type_len - 1u);
    for (; c != 0; --c) {
      if (t & mask) break;
      mask >>= 1u;
    }
    data[c + 1u].push_back(t);
  }

  for (auto i : data[0])
    std::cout << i << " ";

  for (unsigned i = 1u; i < data.size() - 1u; ++i) {
    radix_sort(data[i], i - 1u);
    for (auto j : data[i])
      std::cout << j << " ";
  }

  return 0;
}