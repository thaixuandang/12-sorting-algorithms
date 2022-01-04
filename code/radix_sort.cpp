#include <cstring>

const int radix = 1 << 16;
int cnt[radix];

void counting_sort(int a[], int b[], int n, int base) {
  memset(cnt, 0, sizeof(cnt));
  for (int i = 0; i < n; ++i) {
    cnt[a[i] / base % radix]++;
  }
  for (int i = 1; i < radix; ++i) {
    cnt[i] += cnt[i - 1];
  }
  for (int i = n - 1; i >= 0; --i) {
    b[--cnt[a[i] / base % radix]] = a[i];
  }
}

void radix_sort(int a[], int n) {
  const int max_value = n - 1;
  int* b = new int[n];
  bool flag = true;
  for (long long base = 1; base <= max_value; base *= radix, flag = !flag) {
    if (flag) {
      counting_sort(a, b, n, base);
    } else {
      counting_sort(b, a, n, base);
    }
  }
  if (!flag) {
    memcpy(a, b, n * sizeof(int));
  }
  delete[] b;
}
