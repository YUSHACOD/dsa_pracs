#include <stdio.h>
#include <stdlib.h>

int front = -1, rear = -1;

struct queue {
  int *FRONT, *REAR, size;
} q;

int size = 100;

int *create() {
  q.FRONT = (int *)malloc(size * sizeof(int));
  front++;
  rear++;
  q.REAR = q.FRONT;
  return q.FRONT;
}

void enqueue(int data) {

  if ((front == 0 && rear == q.size - 1) || rear == front - 1) {
    printf("Overflow");
  } else {
    if (front != 0 && rear == q.size - 1) {
      rear = 0;
      q.REAR = q.REAR - (q.size - 1);
    }
    *(q.REAR) = data;
  }
}

void deque() {
  if (front == -1) {
    printf("Underflow");
  } else {

    front++;
    q.FRONT += 1;
  }
}

int main() {
  create();
  enqueue(1);
  enqueue(2);
  enqueue(3);
  enqueue(4);
  deque();
  deque();
}
