#include <algorithm>

void selection_sort(int a[], int n) {
  for (int i = 0; i < n; ++i) {
    int jmin = i;
    for (int j = i + 1; j < n; ++j) {
      if (a[j] < a[jmin]) {
        jmin = j;
      }
    }
    std::swap(a[i], a[jmin]);
  }
}
