// ECUST luoyongjun
#include <bits/stdc++.h>

using namespace std;

int main() {
  int t, n;
  cin >> t;

  while (t--) {
    cin >> n;

    int k = 2;

    list<int> mylist;  //����
    list<int>::iterator it;

    for (int i = 1; i <= n; i++) mylist.push_back(i);  //��ֵ

    while (mylist.size() > 3) {
      int num = 1;
      
      for (it = mylist.begin(); it != mylist.end();) {
        if (num++ % k == 0)
          it = mylist.erase(it);
        else
          it++;
      }
      k == 2 ? k = 3 : k = 2;  // 1��2������1��3����
    }

    for (it = mylist.begin(); it != mylist.end(); it++) {
      if (it != mylist.begin()) cout << " ";
      cout << *it;
    }
    cout << endl;
  }
  return 0;
}
