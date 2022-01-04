void counting_sort(int a[], int n) {
  int* cnt = new int[n]();
  for (int i = 0; i < n; ++i) {
    cnt[a[i]]++;
  }
  for (int i = 0, j = 0; i < n; ++i) {
    while (cnt[i]) {
      cnt[i]--;
      a[j++] = i;
    }
  }
  delete[] cnt;
}
