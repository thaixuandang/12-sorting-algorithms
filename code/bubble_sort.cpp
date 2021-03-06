#include <algorithm>

void bubble_sort(int a[], int n) {
  for (int i = 0; i < n; ++i) {
    for (int j = n - 1; j > i; --j) {
      if (a[j] < a[j - 1]) {
        std::swap(a[j], a[j - 1]);
      }
    }
  }
}
