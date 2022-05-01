#include <iostream>

#include "Vector.hpp"

using namespace std;

void f1(const Vector<int>& x, const Vector<int>& y, const Vector<int>& z) {
  cout << "f1" << endl;
  Vector<int> r;
  r = operator+(x, operator+(y, z));  // 右值，编译器会自动 move
  r = x + y + z;
}

Vector<int> f2() {
  cout << "f2" << endl;
  Vector<int> x(1000);
  Vector<int> y(1000);
  Vector<int> z(1000);

  f1(x, y, z);

  z = x;             // we get a copy
  y = std::move(x);  // we get a move
  return z;          // we get a move
};

int main() { auto h = f2(); }