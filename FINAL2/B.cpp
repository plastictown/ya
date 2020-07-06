//------  solution id 33537426  ------//

#include <iostream>
#include <fstream>
#include <vector>

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);

  unsigned n;
  int e;

  std::ifstream ifs("input.txt");
  ifs >> n >> e;

  if (n < 1) {
    std::cout << -1;
    return 0;
  }

  std::vector<int> data;
  data.reserve(n);

  unsigned first = 0u;

  for (unsigned i = 0u; i < n; ++i) {
    int t;
    ifs >> t;
    data.push_back(t);

    if (i > 0) 
      if (data[i] < data[i - 1])
        first = i;   
  }

  int result = -1;

  unsigned l = 0;
  unsigned r = data.size() - 1u;
  
  //- binary search -//
  while (l <= r) {
    // index without offset
    unsigned m = l + (r - l) / 2u;
    // index with offset
    unsigned cvi = (first + m) % data.size();
    int cv = data[cvi];
    if (cv == e) {
      result = cvi;
      break;
    }
    else if (cv > e)
    {
      r = m - 1;
      continue;
    }
    else if (cv < e)
    {
      l = m + 1;
      continue;
    }
  }

  std::cout << result;

  return 0;
}