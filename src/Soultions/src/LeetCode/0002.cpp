#include "leetcode.hpp"
#include <bits/stdc++.h>

using namespace std;

class Solution {
  public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        auto cur = new ListNode(0);
        auto &res = cur;
        for (int a = 0, b = 0, carry = 0, sum; l1 || l2 || carry;
             a = 0, b = 0) {
            if (l1) {
                a = l1->val;
                l1 = l1->next;
            }
            if (l2) {
                b = l2->val;
                l2 = l2->next;
            }
            sum = a + b + carry;
            cur->next = new ListNode(sum % 10);
            cur = cur->next;
            carry = sum / 10;
        }
        auto tmp = res;
        res = res->next;
        delete tmp;
        return res;
    }
};