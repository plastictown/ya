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

//-31I-//
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

  std::vector<unsigned> data;
  data.reserve(n);

  for (unsigned i = 0u; i < n; ++i) {
    unsigned t;
    INPUT_STREAM >> t;
    data.push_back(t);
  }

  unsigned l = 0, m = 0, h = data.size() - 1;

  while (m <= h) {
    switch (data[m]) {
    case 0:
      std::swap(data[l++], data[m++]);
      break;
    case 1:
      m++;
      break;
    default:
      std::swap(data[m], data[h--]);
    }
  }

  for (auto i : data)
    std::cout << i << " ";
 
  return 0;
}