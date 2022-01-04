#include <algorithm>

void quicksort(int a[], int n) {
  if (n <= 1) {
    return;
  }
  int pivot = a[n / 2];
  int i = 0, j = n - 1;
  do {
    while (a[i] < pivot) {
      i++;
    }
    while (a[j] > pivot) {
      j--;
    }
    if (i <= j) {
      std::swap(a[i++], a[j--]);
    }
  } while (i <= j);
  quicksort(a, j + 1);
  quicksort(a + i, n - i);
}

