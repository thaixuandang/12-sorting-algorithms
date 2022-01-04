#include <cstring>

void merge(int a[], int b[], int p, const int q, const int r) {
  int i = p, j = q;
  while (i < q && j < r) {
    if (a[i] <= a[j]) {
      b[p++] = a[i++];
    } else {
      b[p++] = a[j++];
    }
  }
  memcpy(b + p, a + (i < q ? i : j), (r - p) * sizeof(int));
}

void merge_sort(int a[], int b[], int n, int step) {
  int p = 0, q = step, r = 2 * step;
  while (r <= n) {
    merge(a, b, p, q, r);
    p += 2 * step;
    q += 2 * step;
    r += 2 * step;
  }
  if (q < n) {
    merge(a, b, p, q, n);
  } else {
    if (p < n) {
      memcpy(b + p, a + p, (n - p) * sizeof(int));
    }
  }
}

void merge_sort(int a[], int n) {
  int* b = new int[n];
  bool flag = true;
  for (int step = 1; step < n; step *= 2, flag = !flag) {
    if (flag) {
      merge_sort(a, b, n, step);
    } else {
      merge_sort(b, a, n, step);
    }
  }
  if (!flag) {
    memcpy(a, b, n * sizeof(int));
  }
  delete[] b;
}
