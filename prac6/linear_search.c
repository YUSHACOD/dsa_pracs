#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

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

  (linear_search(arr, 6, 4243)) ? (printf("Found")) : (printf("Not Found"));

  return 0;
}
