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


int part(std::vector<int>& data, unsigned l, unsigned r) {
  int v = data[(l + r) / 2];
  unsigned i = l, j = r;
  while (i <= j) {
    while (data[i] < v)
      ++i;
    while (data[j] > v)
      --j;
    if (i >= j) break;
    std::swap(data[i++], data[j--]);
  }
  return j;
}

void quicksort(std::vector<int>& data, unsigned l, unsigned r) {
  unsigned sz = r - l + 1u;
  if (sz < 2) return;
  if (l >= r) return;
  int q = part(data, l, r);
  quicksort(data, l, q);
  quicksort(data, q + 1, r);
}

//-31C-//
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

  quicksort(data, 0, data.size() - 1);

  for (auto i : data)
    std::cout << i << " ";

  return 0;
}
