#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

static int cmp_int(const void *p, const void *q) {
  if (*(const int *)p == *(const int *)q) {
    return 0;
  } else if (*(const int *)p > *(const int *)q) {
    return 1;
  } else {
    return -1;
  }
}

bool binary_search_aux(int *arr, int start, int end, int key) {
  if (start == end) {
    return (arr[start] == key) ? (true) : (false);
  } else if (start > end) {
    return false;
  } else {
    int mid = (end + start) / 2;
    if (arr[mid] == key) {
      return true;
    } else if (arr[mid] > key) {
      return binary_search_aux(arr, start, mid - 1, key);
    } else {
      return binary_search_aux(arr, mid + 1, end, key);
    }
  }
}

void swap(int *p, int *q) {
  int t = *p;
  *p = *q;
  *q = t;
}

void insertion_sort(int *arr, int len) {
  for (int i = 0; i < len; i++) {
    int smallest = i;
    for (int j = i; j < len; j++) {
      if (arr[smallest] > arr[j]) {
        smallest = j;
      }
    }
    swap(&arr[i], &arr[smallest]);
  }
}

void print_array(int *arr, int len) {
  printf("\n");
  for (int i = 0; i < len; i++) {
    printf("%d\t", arr[i]);
  }
  printf("\n");
}

bool binary_search(int *arr, int len, int key) {

  int *temp = (int *)calloc(len, sizeof(int)); // Making temperory array
  for (int i = 0; i < len; i++)                // to not mutate original array
    temp[i] = arr[i];

  insertion_sort(temp, len);

  return binary_search_aux(temp, 0, len - 1, key);
}

int main(int argc, char *argv[]) {

  int arr[] = {1, 2, 4243, 62, 246, 64};

  print_array(arr, 6);

  (binary_search(arr, 6, 89)) ? (printf("89 Found\n"))
                              : (printf("89 Not Found\n"));

  (binary_search(arr, 6, 1)) ? (printf("1 Found\n"))
                             : (printf("1 Not Found\n"));

  (binary_search(arr, 6, 2)) ? (printf("2 Found\n"))
                             : (printf("3 Not Found\n"));

  (binary_search(arr, 6, 4242)) ? (printf("4242 Found\n"))
                                : (printf("4242 Not Found\n"));

  (binary_search(arr, 6, 87)) ? (printf("87 Found\n"))
                              : (printf("87 Not Found\n"));

  return 0;
}
