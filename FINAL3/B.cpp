//------  solution id 33592756  ------//

#include <iostream>
#include <fstream>
#include <vector>

#ifdef TESTING
  #define INIT_INPUT
  #define INPUT_STREAM std::cin
#else
  #define INIT_INPUT std::ifstream ifs("input.txt");
  #define INPUT_STREAM ifs
#endif // TESTING

//-3-FINAL-B-//
int main()
{
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);

  INIT_INPUT;

  unsigned m, n;

  INPUT_STREAM >> m >> n;

  if (m == 0u && n == 0u) {
    std::cout << 0;
    return 0;
  }

  unsigned half = (m + n) / 2u + 1u;
  unsigned full = m + n - 1u;
  
  std::vector<unsigned> data1;
  data1.reserve(m);
  std::vector<unsigned> data2;
  data2.reserve(n);
  
  //-read first array-//
  for (unsigned i = 0u; i < m; ++i) {
    unsigned t;
    INPUT_STREAM >> t;
    data1.push_back(t);
  }
  
  //-merge simulation-//
  int it1 = 0;
  int it2 = 0;
  int it = m + n - 1u;
  bool even = (m + n) % 2u == 0u;
  unsigned ri = (m + n) / 2u;
  unsigned li = (even) ? ri - 1u : ri;
  unsigned lv = 0u; // target
  unsigned rv = 0u; // values
  unsigned ctr = 0u;
  
  // reading the second array and searching
  // for target elements simultaneously
  for (unsigned j = 0u; j < n; ++j) {
    unsigned t;
    INPUT_STREAM >> t;
    data2.push_back(t);

    bool repeat_flag = true;

    //-merging arrays without merging arrays-//
    do {
      if (it1 > data1.size() - 1) {
        if (ctr == ri) {
          rv = data2[it2];
          break;
        }
        if (even && ctr == li) {
          li = data2[it2];
        }
        ++ctr;
        --it;
        ++it2;
        repeat_flag = false;
      } else if (it2 > n - 1) {
        it = -1;
        break;
      } else if (data1[it1] < data2[it2]) {
        if (ctr == ri) {
          rv = data1[it1];
          break;
        }
        if (even && ctr == li) {
          lv = data1[it1];
        }
        ++ctr;
        --it;
        ++it1;      
      } else {
        if (ctr == ri) {
          rv = data2[it2];
          break;
        }
        if (even && ctr == li) {
          lv = data2[it2];
        }
        ++ctr;
        --it;
        ++it2;
        repeat_flag = false;
      }
    } while (repeat_flag && it >=0);
    // stop reading after 
    // finding the desired item
    if (ctr > ri)
      break;
  }//-for

  double ret = (even) ?(lv + rv) / 2.0: rv ;

  std::cout << ret;

  return 0;
}//-main()-//