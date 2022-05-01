// UVa1339 Ancient Cipher
// Rujia Liu
#include <stdio.h>
#include <stdlib.h>  // qsort
#include <string.h>  // strlen

int cmp(const void *a, const void *b) { return *(int *)a - *(int *)b; }

int main() {
  char s1[200], s2[200];
  while (scanf("%s%s", s1, s2) == 2) {
    int n = strlen(s1);
    int cnt1[26] = {0}, cnt2[26] = {0};
    for (int i = 0; i < n; i++)
      cnt1[s1[i] -
           'A']++;  // 字母是可以做一一映射的，那只要看每种字母的个数是否都一样多。
    for (int i = 0; i < n; i++) cnt2[s2[i] - 'A']++;
    qsort(cnt1, 26, sizeof(int), cmp);
    qsort(cnt2, 26, sizeof(int), cmp);
    int ok = 1;
    for (int i = 0; i < 26; i++)
      if (cnt1[i] != cnt2[i]) ok = 0;
    if (ok)
      printf("YES\n");
    else
      printf("NO\n");
  }
  return 0;
}
