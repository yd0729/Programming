/**
 * @file variadic_template.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-05-01
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include <bits/stdc++.h>

using namespace std;

template <typename T>
void g(T x) {
  cout << x << " ";
}

void f() {}  // 最后 tail 为空

template <typename T, typename... Tail>
void f(T head, Tail... tail) {
  g(head);     // do something to head
  f(tail...);  // try again with tail
}

int main() {
  cout << "ﬁrst: ";
  f(1, 2.2, "hello");
  cout << "\nsecond: ";
  f(0.2, 'c', "yuck!", 0, 1, 2);
  cout << "\n";
}