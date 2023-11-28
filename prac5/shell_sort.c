#include <stdio.h>

void swap(int *a, int *b) {
  int t = *a;
  *a = *b;
  *b = t;
}

int get_index_of_smallest(int *arr, int start, int end, int increment) {
  int smallest = start;
  for (int j = smallest; j < end; j += increment) {
    if (arr[smallest] > arr[j])
      smallest = j;
  }
  return smallest;
}

void insertion_sort(int *arr, int len, int increment) {
  for (int i = 0; i < len; i += increment) {
    swap(&arr[i], &arr[get_index_of_smallest(arr, i, len, increment)]);
  }
}

void print_array(int *arr, int len) {
  printf("\n");
  for (int i = 0; i < len; i++) {
    printf("%d\t", arr[i]);
  }
  printf("\n");
}

void shell_sort_aux(int *arr, int len, int gap) {
  if (gap <= 0) {
    return;
  } else {
    insertion_sort(arr, len, gap);
    shell_sort_aux(arr, len, gap - 1);
  }
}

void shell_sort(int *arr, int len) { shell_sort_aux(arr, len, len / 2); }

int main(int argc, char *argv[]) {

  int arr[] = {1, 2, 4243, 62, 246, 64};

  print_array(arr, 6);

  shell_sort(arr, 6);
  print_array(arr, 6);

  return 0;
}
