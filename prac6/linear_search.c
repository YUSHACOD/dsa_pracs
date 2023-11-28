#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

void print_array(int *arr, int len) {
  printf("\n");
  for (int i = 0; i < len; i++) {
    printf("%d\t", arr[i]);
  }
  printf("\n");
}

bool linear_search_aux(int *arr, int len, int key, int count) {
  if (count >= len) {
    return false;
  } else {
    if (arr[count] == key) {
      return true;
    } else {
      return linear_search_aux(arr, len, key, count + 1);
    }
  }
}

bool linear_search(int *arr, int len, int key) {
  return linear_search_aux(arr, len, key, 0);
}

int main(int argc, char *argv[]) {

  int arr[] = {1, 2, 4243, 62, 246, 64};

  print_array(arr, 6);

  (linear_search(arr, 6, 89)) ? (printf("89 Found\n"))
                              : (printf("89 Not Found\n"));

  (linear_search(arr, 6, 1)) ? (printf("1 Found\n"))
                             : (printf("1 Not Found\n"));

  (linear_search(arr, 6, 2)) ? (printf("2 Found\n"))
                             : (printf("3 Not Found\n"));

  (linear_search(arr, 6, 4242)) ? (printf("4242 Found\n"))
                                : (printf("4242 Not Found\n"));

  (linear_search(arr, 6, 87)) ? (printf("87 Found\n"))
                              : (printf("87 Not Found\n"));

  return 0;
}
