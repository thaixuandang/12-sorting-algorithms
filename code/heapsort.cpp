void adjust_heap(int a[], int i, int n, int x) {
  int j = i * 2 + 1;
  while (j < n) {
    if (j + 1 < n && a[j + 1] > a[j]) {
      j++;
    }
    if (x >= a[j]) {
      break;
    }
    a[i] = a[j];
    i = j, j = i * 2 + 1;
  }
  a[i] = x;
}

void heapsort(int a[], int n) {
  if (n <= 1) {
    return;
  }
  for (int parent = (n - 2) / 2; parent >= 0; --parent) {
    adjust_heap(a, parent, n, a[parent]);
  }
  while (--n) {
    int x = a[n];
    a[n] = a[0];
    adjust_heap(a, 0, n, x);
  }
}
