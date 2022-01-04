/* Compile this file by calling
 * "g++ main.cpp DataGenerator.cpp selection_sort.cpp insertion_sort.cpp binary_insertion_sort.cpp bubble_sort.cpp shaker_sort.cpp shellsort.cpp heapsort.cpp merge_sort.cpp quicksort.cpp counting_sort.cpp radix_sort.cpp flashsort.cpp -O2".
 *
 * Then, run a.exe (for Windows) or a.out (for Linux) to generate the results.
 */

#include <cstdio>
#include <cstring>
#include <ctime>
#include <cstdlib>

// Declarations
void GenerateData(int*, int, int);
void selection_sort(int*, int);
void insertion_sort(int*, int);
void binary_insertion_sort(int*, int);
void bubble_sort(int*, int);
void shaker_sort(int*, int);
void shellsort(int*, int);
void heapsort(int*, int);
void merge_sort(int*, int);
void quicksort(int*, int);
void counting_sort(int*, int);
void radix_sort(int*, int);
void flashsort(int*, int);

const int num_data_orders = 4;
const int num_data_sizes = 5;
const int num_algorithms = 12;

const char* data_orders[] = {
  "Random Order Data",
  "Sorted Data",
  "Reverse Data",
  "Nearly Sorted Data"
};

const int data_sizes[] = {3000, 10'000, 30'000, 100'000, 300'000};

const char* algorithms[] = {
  "Selection sort",
  "Insertion sort",
  "Binary insertion sort",
  "Bubble sort",
  "Shaker sort",
  "Shellsort",
  "Heapsort",
  "Merge sort",
  "Quicksort",
  "Counting sort",
  "Radix sort",
  "Flashsort"
};

void (*sorts[]) (int*, int) = {
  selection_sort,
  insertion_sort,
  binary_insertion_sort,
  bubble_sort,
  shaker_sort,
  shellsort,
  heapsort,
  merge_sort,
  quicksort,
  counting_sort,
  radix_sort,
  flashsort
};

const int max_size = data_sizes[num_data_sizes - 1];
int a[max_size];
int b[max_size];

void create_file(const char* data_order) {
  char result_filename[FILENAME_MAX];
  sprintf(result_filename, "%s Results.csv", data_order);
  freopen(result_filename, "w", stdout);
  for (int i = 0; i < num_algorithms; ++i) {
    printf(",%s", algorithms[i]);
  }

  putchar('\n');
}

int main() {
  for (int i = 0; i < num_data_orders; ++i) {
    create_file(data_orders[i]);
    for (int j = 0; j < num_data_sizes; ++j) {
      int n = data_sizes[j];
      printf("%d", n);
      GenerateData(a, n, i);
      for (int k = 0; k < num_algorithms; ++k) {
        memcpy(b, a, n * sizeof(int));
        time_t start = clock();
        sorts[k](b, n);
        time_t end = clock();
        auto runtime = (end - start) / (CLOCKS_PER_SEC / 1000);
        printf(",%li", runtime);
        fprintf(stderr, "%18s, size %6d: Completed %21s in %7li milliseconds.\n",
                data_orders[i], n, algorithms[k], runtime);
      }
      putchar('\n');
    }
  }
  return 0;
}
