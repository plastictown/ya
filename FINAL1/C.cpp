
//------  solution id 33361815  ------//

#include <vector>
#include <string>
#include <iostream>

//-----------------------stack--------------------------//

namespace DomchenkovMA {

  template<typename T>
  struct stack {
  public:
    stack(unsigned sz)
    {
      data.reserve(sz);
    }

    void push(const T& val) {
      data.push_back(val);
    }
    bool pop(T& out) {
      if (data.empty())
        return false;
      out = data.back();
      data.pop_back();
      return true;
    }
    bool empty() const { return data.empty(); }
    unsigned get_size() const {
      return data.size();
    }
  private:
    std::vector<T> data;
  };

//-----------------------queue--------------------------//

  template<typename T>
  struct DoubleStackQueue {
  public:

    DoubleStackQueue(unsigned sz):
      left{sz},
      right{ sz }
    {}

    void push(const T& val) {
      left.push(val);
    }
    bool pop(T& val) {
      if (left.empty() && right.empty())
        return false;
      if (right.empty()) {
        T temp;
        while (left.pop(temp))
          right.push(temp);
      }
      right.pop(val);
      return true;
    }

    unsigned get_size() const{
      return left.get_size() + right.get_size();
    }
  private:
    stack<T> left, right;
  };

} // ! DomchenkovMA

//-------------------------------------------------//

int main() { //--------MAIN---------//

  std::cin.tie(nullptr);
  std::ios_base::sync_with_stdio(false);

  unsigned ncmd;
  std::string s;
  std::cin >> ncmd;
  std::getline(std::cin, s);

  DomchenkovMA::DoubleStackQueue<int> q{ ncmd };

  for (unsigned i = 0u; i < ncmd; ++i) {
    std::string cmd;
    int val;
    std::cin >> cmd;
    if (cmd == "put") {
      std::cin >> val;
      q.push(val);
      continue;
    }
    if (cmd == "get") {
      if (q.pop(val)) std::cout << val << "\n";
      else std::cout << "error\n";
      continue;
    }
    // get_size
    std::cout << q.get_size() << "\n";
  }

  return 0;
} //-!------MAIN---------//

//-------------------------------------------------//