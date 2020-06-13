#pragma once
#ifndef __TASK21G_HPP__
#define __TASK21G_HPP__

#include <iostream>
#include <vector>

namespace DomchenkovMA {

  struct point {
    int x, y;
  };

  enum direction {
    left,
    right,
    up,
    down
  };

  struct borders {
    int l, r, t, b;
    bool pt_in(const point& p) const {
      bool bx = p.x > l && p.x < r;
      bool by = p.y > t && p.y < b;
      return bx && by;
    }
  };

  bool move(point& pt, direction d, borders& bs) {
    point p = pt;
    switch (d) {
    case left:
      --p.x;
      break;
    case right:
      ++p.x;
      break;
    case up:
      --p.y;
      break;
    case down:
      ++p.y;
      break;
    }

    if (bs.pt_in(p)) {
      pt.x = p.x;
      pt.y = p.y;
      return true;
    }

    switch (d) {
    case left:
      --bs.b;
      break;
    case right:
      ++bs.t;
      break;
    case up:
      ++bs.l;
      break;
    case down:
      --bs.r;
      break;
    }

    return false;
  }

  direction rotate(direction d) {
    switch (d) {
    case left:
      return up;
    case right:
      return down;
    case up:
      return right;
    case down:
      return left;
    }
    return d; //stub
  }

  int solution() {
    using rowtype = std::vector<int>;

    unsigned rows, cols;
    std::cin >> rows >> cols;

    if (cols == 0 || rows == 0)
      return 0;

    rowtype row;
    row.resize(cols);
    std::vector<rowtype> data;
    data.reserve(rows);
    for (unsigned i = 0u; i < rows; ++i)
      data.push_back(row);

    for (unsigned i = 0u; i < rows; ++i)
      for (unsigned j = 0u; j < cols; ++j)
        std::cin >> data[i][j];

    borders bs{ -1, cols, -1, rows };
    point pos{ 0,0 };
    direction dir = right;

    while (1) {
      std::cout << data[pos.y][pos.x] << "\n";
      bool m = move(pos, dir, bs);
      if (!m) {
        dir = rotate(dir);
        m = move(pos, dir, bs);
        if (!m)
          break;
      }
    }
  }
  
} // !namespace

#endif // !__TASK21G_HPP__