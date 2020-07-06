
//------  solution id 33361692  ------//

#include <string>
#include <sstream>
#include <vector>
#include <iostream>

//---------------------------------------------//

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

//---------------------------------------------//

struct calc {
  public:
    calc(unsigned max):
      _data{max}
    {}
    int calculate(std::string& s) {
      std::stringstream ss(s);
      std::string tmp;

      while (ss >> s) {
        if (s.empty()) continue;
        if (is_val(s)) {
          int val = std::stoi(s);
          _data.push(val);
        }
        else {
          process_op(s[0]);
        }
      }// !while

      int ret;
      _data.pop(ret);
      return ret;

  }// !calculate

  private:

    bool is_val(const std::string& s) {
      for (auto c : s) {
        if (c >= '0' && c <= '9') return true;
      }
      return false;
    }

    void process_op(char op) {
      int larg, rarg, res = 0;

      _data.pop(rarg);
      _data.pop(larg);

      switch (op) {
      case '+':
        res = larg + rarg;
        break;
      case '-':
        res = larg - rarg;
        break;
      case '/':
        res = larg / rarg;
        break;
      case '*':
        res = larg * rarg;
        break;
      }
      _data.push(res);
    }

    stack<int> _data;
  };

} // namespace

//---------------------------------------------//

int main() { //--------MAIN---------//

  std::cin.tie(nullptr);
  std::ios_base::sync_with_stdio(false);

  std::string s;
  std::getline(std::cin, s);

  DomchenkovMA::calc calc{ s.length() };

  std::cout << calc.calculate(s);

  return 0;
} //-!------MAIN---------//

//---------------------------------------------//