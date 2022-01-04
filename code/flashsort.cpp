#include <algorithm>

void flashsort(int a[], int n) {
  if (n <= 2) {
    if (n == 2 && a[0] > a[1]) {
      std::swap(a[0], a[1]);
    }
    return;
  }
  int max = a[0], min = a[0];
  for (int i = 1; i < n; ++i) {
    if (a[i] > max) {
      max = a[i];
    }
    if (a[i] < min) {
      min = a[i];
    }
  }
  int m = 0.42 * n;
  int* cnt = new int[m]();
  for (int i = 0; i < n; ++i) {
    cnt[(m - 1LL) * (a[i] - min) / (max - min)]++;
  }
  for (int i = 1; i < m; ++i) {
    cnt[i] += cnt[i - 1];
  }
  int move = 0, i = 0, k = 0;
  while (move < n) {
    while (i >= cnt[k]) {
      k = (m - 1LL) * (a[++i] - min) / (max - min);
    }
    int x = a[i];
    while (i < cnt[k]) {
      k = (m - 1LL) * (x - min) / (max - min);
      std::swap(a[--cnt[k]], x);
      move++;
    }
  }
  for (int k = 1; k < m; ++k) {
    for (int i = cnt[k] - 2; i >= cnt[k - 1]; --i) {
      int x = a[i];
      int j = i + 1;
      while (x > a[j]) {
        a[j - 1] = a[j];
        j++;
      }
      a[j - 1] = x;
    }
  }
  delete[] cnt;
}
