#include <stdio.h>

void swap(int *a, int *b) {
  int t = *a;
  *a = *b;
  *b = t;
}

void print_array(int *arr, int len) {
  printf("\n");
  for (int i = 0; i < len; i++) {
    printf("%d\t", arr[i]);
  }
  printf("\n");
}

void quick_sort_aux(int *arr, int left, int right, int pivot) {
  if (left >= right) {
    return;
  } else {
  }
}

int main(int argc, char *argv[]) {
  printf("");
  return 0;
}
