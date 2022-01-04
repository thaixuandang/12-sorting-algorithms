#include <algorithm>

void shaker_sort(int a[], int n) {
  int left = 0, right = n - 1;
  int k = 0;
  while (left < right) {
    for (int i = left; i < right; ++i) {
      if (a[i] > a[i + 1]) {
        std::swap(a[i], a[i + 1]);
        k = i;
      }
    }
    right = k;
    for (int i = right; i > left; --i) {
      if (a[i] < a[i - 1]) {
        std::swap(a[i], a[i - 1]);
        k = i;
      }
    }
    left = k;
  }
}
