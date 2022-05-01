#include <iostream>

using namespace std;

template <typename T>
class Vector {
 private:
  T* elem;
  int sz = 10;

 public:
  Vector() : elem{nullptr}, sz{0} {}
  Vector(int s)
      : elem{new T[s]},
        sz{s} {  // constructor: establish invariant, acquire resources
    cout << "constructor!" << endl;
    for (int i = 0; i != s; ++i) elem[i] = 0;  // initialize elements
  }
  Vector<T>(const Vector<T>& a);             // copy constructor
  Vector<T>& operator=(const Vector<T>& a);  // copy assignment
  Vector<T>(Vector<T>&& a);                  // move constructor
  Vector& operator=(Vector<T>&& a);          // move assignment
  ~Vector() { delete[] elem; }               // destructor: release resources
  T& operator[](int i) const;
  int size() const { return sz; }
  void push_back(T);  // add element at end increasing the size by one
  Vector(std::initializer_list<T>);  // initialize with a list
};

template <typename T>
Vector<T>::Vector(Vector<T>&& a) : elem{a.elem}, sz{a.sz} {
  cout << "move constructor!" << endl;
  a.elem = nullptr;  // "grab the elements" from a
  a.sz = 0;          // now a has no elements
}

template <typename T>
Vector<T>& Vector<T>::operator=(Vector<T>&& a) {
  cout << "move assignment!" << endl;
  elem = a.elem;
  sz = a.sz;
  a.elem = nullptr;
  a.sz = 0;
  return *this;
}

template <typename T>
Vector<T>::Vector(const Vector& a)      // copy constructor
    : elem{new T[sz]}, sz{a.sz} {  // allocate space for elements
  cout << "copy constructor!" << endl;
  for (int i = 0; i != sz; ++i) elem[i] = a.elem[i];  // copy elements
}

template <typename T>
Vector<T>& Vector<T>::operator=(const Vector& a) {  // copy assignment
  cout << "copy assignment!" << endl;
  T* p = new T[a.sz];
  for (int i = 0; i != a.sz; ++i) p[i] = a.elem[i];
  delete[] elem;  // delete old elements
  elem = p;
  sz = a.sz;
  return *this;
}

template <typename T>
T& Vector<T>::operator[](int i) const {
  return elem[i];
}

class Vector_size_mismatch {};

template <typename T>
Vector<T> operator+(const Vector<T>& a, const Vector<T>& b) {
  if (a.size() != b.size()) throw Vector_size_mismatch{};
  Vector<T> res(a.size());
  for (int i = 0; i != a.size(); ++i) res[i] = a[i] + b[i];
  return res;
}

template <typename T>
Vector<T> read(istream& is) {
  Vector<T> v;
  for (T d; is >> d;) v.push_back(d);
  return v;
}

template <typename T>
void Vector<T>::push_back(T d) {
  if (elem == nullptr) {
    elem = new T[10];
  }
  elem[sz++] = d;
}

template <typename T>
Vector<T>::Vector(std::initializer_list<T> lst)
    : elem{new T[lst.size()]},
      sz{(int)lst.size()} {            // initialize with a list
  copy(lst.begin(), lst.end(), elem);  // copy from lst into elem
}

template <typename T>
T* begin(Vector<T>& x) {
  return &x[0];  // pointer to ﬁrst element
}

template <typename T>
T* end(Vector<T>& x) {
  return x.begin() + x.size();  // pointer to one-past-last element
}
