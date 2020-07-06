
//------  solution id 33357800  ------//

#include <string>
#include <sstream>
#include <vector>
#include <iostream>

//---------------------------------------------//

namespace DomchenkovMA {

template<typename T>
  struct deque {

  public:

    deque(unsigned sz) :
      max_size{ sz },
      size{ 0u },
      head{ 0u },
      tail{ 1u }
    { data.resize(sz); }

    bool push_back(const T& val) {
      if (full()) return false;
      data[tail] = val;
      tail = next(tail);
      ++size;
      return true;
    }
    bool push_front(const T& val) {
      if (full()) return false;
      data[head] = val;
      head = prev(head);
      ++size;
      return true;
    }

    bool pop_back() {
      if (empty()) return false;
      tail = prev(tail);
      --size;
      return true;
    }
    bool pop_front() {
      if (empty()) return false;
      head = next(head);
      --size;
      return true;
    }

    const T* front() const {
      if (empty()) return nullptr;
      return (data.data() + next(head));
    }

    const T* back() const {
      if (empty()) return nullptr;
      return (data.data() + prev(tail));
    }
    bool empty() const {
      return size == 0u;
    }

    unsigned get_size() const { return size; }

  private:

    //- methods -//

    unsigned next(unsigned i) const {
      return (i + 1) % max_size;
    }
    unsigned prev(unsigned i) const {
      return (max_size + i - 1u) % max_size;
    }
    bool full() const {
      return size == max_size;
    }

    //- fields -//

    unsigned max_size;
    unsigned size;
    std::vector<T> data;
    unsigned head, tail;

  }; // ! deque;

  template<typename T>
  struct stack {
  public:
    stack(unsigned sz) 
      : data{sz}{}

    bool push(const T& val) {
      return data.push_back(val);
    }
    bool pop(T& out) {
      if (data.empty())
        return false;
      out = *data.back();
      data.pop_back();
      return true;
    }
    bool empty() const { return data.empty(); }
    unsigned get_size() const { 
      return data.get_size(); 
    }
  private:
    deque<T> data;
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