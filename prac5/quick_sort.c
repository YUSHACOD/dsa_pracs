#include <stdio.h>
#include <stdlib.h>

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

int quick_sort_aux(int *arr, int left, int right, int pivot) {
  if (left >= right) {
    return pivot;
  } else {
    if (right == pivot) {
      if (arr[left] > arr[pivot]) {
        swap(&arr[left], &arr[pivot]);
        return quick_sort_aux(arr, left, right - 1, left);
      } else {
        return quick_sort_aux(arr, left + 1, right, pivot);
      }
    } else if (left == pivot) {
      if (arr[right] < arr[pivot]) {
        swap(&arr[right], &arr[pivot]);
        return quick_sort_aux(arr, left + 1, right, right);
      } else {
        return quick_sort_aux(arr, left, right - 1, pivot);
      }
    } else {
      printf("Major error, pivot value diverted");
      exit(1);
    }
  }
}

void partition_and_sort(int *arr, int left, int right) {
  if (left < right) {
    int pivot = quick_sort_aux(arr, left, right, right);
    partition_and_sort(arr, left, pivot - 1);
    partition_and_sort(arr, pivot + 1, right);
  } else {
    return;
  }
}

void quick_sort(int *arr, int len) { partition_and_sort(arr, 0, len - 1); }

int main(int argc, char *argv[]) {
  int arr[] = {85, 87, 6, 51, 4, 3, 2, 1};
  print_array(arr, 8);

  quick_sort(arr, 8);

  print_array(arr, 8);
  return 0;
}
