void binary_insertion_sort(int a[], int n) {
  for (int i = 1; i < n; ++i) {
    int x = a[i];
    int low = -1, high = i;
    while (low + 1 < high) {
      int mid = (low + high) / 2;
      if (a[mid] > x) {
        high = mid;
      } else {
        low = mid;
      }
    }
    for (int j = i - 1; j >= high; --j) {
      a[j + 1] = a[j];
    }
    a[high] = x;
  }
}
