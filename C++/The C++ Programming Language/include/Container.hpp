#include <iostream>
#include <list>

#include "Vector.hpp"

using namespace std;

class Container {
 public:
  virtual double& operator[](int) = 0;  // pure virtual function
  virtual int size() const = 0;         // const member function
  virtual ~Container() {}               // destructor
};

template<typename T>
class Vector_container
    : public Container {  // Vector_container implements Container
  Vector<T> v;

 public:
  Vector_container(int s) : v(s) {}  // Vector of s elements
  Vector_container(std::initializer_list<T> lst) : v(lst) {}
  ~Vector_container() {}
  T& operator[](int i) { return v[i]; }
  int size() const { return v.size(); }
};

class List_container
    : public Container {  // List_container implements Container
  std::list<double> ld;   // (standard-librar y) list of doubles (§4.4.2)
 public:
  List_container() {}  // empty List
  List_container(initializer_list<double> il) : ld{il} {}
  ~List_container() {}
  double& operator[](int i);
  int size() const { return ld.size(); }
};

double& List_container::operator[](int i) {
  for (auto& x : ld) {
    if (i == 0) return x;
    --i;
  }
  throw out_of_range("List container");
}

void use(Container& c) {
  const int sz = c.size();
  for (int i = 0; i != sz; ++i) cout << c[i] << '\n';
}

void g() {
  Vector_container<int> vc{10, 9, 8, 7, 6, 5, 4, 3, 2, 1, 0};
  use(vc);
}

void h() {
  List_container lc = {1, 2, 3, 4, 5, 6, 7, 8, 9};
  use(lc);
}