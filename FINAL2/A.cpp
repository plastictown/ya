//------  solution id 33538647  ------//

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

int main()
{
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);

  std::ifstream ifs("input.txt");

  unsigned n;

  ifs >> n;

  if (n < 2u) {
    std::cout << 0;
    return 0;
  }

  std::vector<unsigned> data;
  data.reserve(n);

  for (unsigned i = 0u; i < n; ++i) {
    unsigned t;
    ifs >> t;
    data.push_back(t);
  }

  unsigned ctr = 0u;

  while (!data.empty()) {
    unsigned l = std::min_element(
        data.cbegin(),
        data.cend()
      ) - data.cbegin();

    unsigned r =
      data.size() - (
          std::max_element(
            data.crbegin(),
            data.crend()
          ) - data.crbegin()
        ) - 1;
    if (l == r) break;
    if (data[l] == 0 || data[r] == 0) break;

    -- data[l];
    -- data[r];
    ++ ctr;

    unsigned min_index = std::min(l, r);
    unsigned max_index = std::max(l, r);

    if (data[max_index] == 0)
      data.erase(data.begin() + max_index);
    if (data[min_index] == 0)
      data.erase(data.begin() + min_index);
  }

  std::cout << ctr;

  return 0;
}