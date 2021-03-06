/**
 * @file io.cpp
 * @author your name (you@domain.com)
 * @brief 自定义 IO
 * @version 0.1
 * @date 2022-05-01
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include <bits/stdc++.h>

using namespace std;

struct Entry {
  string name;
  int number;
};

ostream& operator<<(ostream& os, const Entry& e) {
  return os << "{\"" << e.name << "\", " << e.number << "}";
}

// read { "name" , number } pair. Note: formatted with { " " , and }
istream& operator>>(istream& is, Entry& e) {
  char c, c2;
  if (is >> c && c == '{' && is >> c2 && c2 == '"') {  // star t with a { "
    string name;  // the default value of a string is the empty string: ""
    while (is.get(c) && c != '"')
      name += c;  // anything before a " is part of the name
    if (is >> c && c == ',') {
      int number = 0;
      if (is >> number >> c && c == '}') {  // read the number and a }
        e = {name, number};                 // assign to the entry
        return is;
      }
    }
  }
  is.setf(ios_base::failbit);  // register the failure in the stream
  return is;
}

int main() {
  for (Entry ee; cin >> ee;)  // read from cin into ee
    cout << ee << '\n';       // write ee to cout
}

// { "John Marwood Cleese" , 123456    }
// {"Michael Edward Palin",987654}
// { "Terry Gilliam", 987654 }
// { "Eric Idle", 987654 }
// ctrl+d