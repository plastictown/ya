#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <set>
#include <map>

#ifdef TESTING
  #define INIT_INPUT
  #define INPUT_STREAM std::cin
#else
  #define INIT_INPUT std::ifstream ifs("input.txt");
  #define INPUT_STREAM ifs
#endif // TESTING

//-31E-//
int main()
{
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);

  INIT_INPUT;

  unsigned m, n;

  INPUT_STREAM >> m >> n;

  if (n < 1u || m <1u) {
    return 0;
  }

  std::vector<int> data1;
  data1.reserve(m);
  std::vector<int> data2;

  for (unsigned i = 0u; i < m; ++i) {
    int t;
    INPUT_STREAM >> t;
    data1.push_back(t);
  }

  for (unsigned i = 0u; i < n; ++i) {
    int t;
    INPUT_STREAM >> t;
    data2.push_back(t);
  }

  std::vector<int> out;
  //std::set<int> outs;
  std::map<int, unsigned> outm;

  for (auto i : data1) {
    auto it = std::find(data2.cbegin(), data2.cend(), i);
    if (it != data2.cend()) {
      //auto res = outs.insert(i);
      auto res = outm.insert(std::make_pair(i, 1u));
      if (!res.second)
        outm[i]++;

      out.push_back(i);        
    }
  }

  for (int i = 0; i < out.size(); ++i) {
    auto c1 = std::count(data1.begin(), data1.end(), out[i]);
    auto c2 = std::count(data2.begin(), data2.end(), out[i]);
    unsigned cn = std::min(c1, c2);
    outm[out[i]] = cn;
  }

  for (auto& i : out) {
    if (outm[i] > 0) {
      std::cout << i << " ";
      --outm[i];
    }
  }

  return 0;
}