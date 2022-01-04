void shellsort(int a[], int n) {
  for (int gap = n / 2; gap > 0; gap /= 2) {
    for (int i = gap; i < n; ++i) {
      int x = a[i];
      int j = i - gap;
      while (j >= 0 && a[j] > x) {
        a[j + gap] = a[j];
        j -= gap;
      }
      a[j + gap] = x;
    }
  }
}
