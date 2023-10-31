#include <stdio.h>
#include <stdlib.h>

// a queue needs a left and right side in the queue and 
/*
**    ->        ->          ->        ->       ->  
**  --------------------------------------------------------------
**  |      |      |      |      |      |      |     |      |     |
**  |      |      |      |      |      |      |     |      |     |
**  |      |      |      |      |      |      |     |      |     |
**  -------------------------------------------------------------- 
**                                              Left & Right -^
**
**  will need to shift the entries again and again as the so we make left
*/
typedef struct {
  // the memory patch where the elements will actually be
  int * buffer;
  // capacity in size of the buffer
  size_t capacity;
  // the size of the queue actually
  size_t size;
  // used to queue
  size_t left;
  // used to dequeue
  size_t right;
} queue_t;


queue_t create(size_t capacity) {
  int *buffer = calloc(capacity, sizeof(int));  
  queue_t queue = {
    .buffer = buffer,
    .capacity = capacity,
    .size = 0,
    .left = capacity - 1,
    .right = capacity - 1,
  };
  return queue;
}

int checks(queue_t q) {
  return 
    q.left <= q.right &&
    q.left >= 0 && q.right >= 0 &&
    q.left < q.capacity && q.right < q.capacity;
}

// debug purpose only
void display(queue_t q) {   
  // see below for these magic constants
  size_t hdash = (1 + 7) * q.capacity + 1;

  // dash as decoration
  for(size_t i = 0; i < hdash; i++) {
    printf("-");
  }
  printf("\n\n");
  
  for(size_t i = 0; i < q.capacity; i++) {
    // one for this
    printf("|");
    // seven for this 
    if (i == q.left && i == q.right) {
      printf("< %2d  >", q.buffer[i]);
    } else 
    if (i == q.left) {
      // this is the block where the next enqueue will happen
      printf("< %2d   ", q.buffer[i]);
    } else 
    if (i == q.right) {
      // this is the block where the next dequeue will happen
      printf("  %2d  >", q.buffer[i]);
    } else {
      printf("  %2d   ", q.buffer[i]);
    }

  }
  // and the lone one for this
  printf("|\n\n");

  for(size_t i = 0; i < hdash; i++) {
    printf("-");
  }
  printf("\n");
  printf("size: %ld \tleft: %ld \tright: %ld \n\n", q.size, q.left, q.right);
}

void enqueue(queue_t *q, int element) {
  if (checks(*q) && q->left > 0) {
    // insert 
    q->buffer[q->left] = element;
    q->left -= 1;
    // then bookeeping later
    q->size += 1;
  } else {
    puts("Cannot enqueue");
  }
}

int dequeue(queue_t *q) {
  if (checks(*q) && q->right < q->capacity) {
    int d;
    d = q->buffer[q->right];
    q->right -= 1;
    q->size -= 1;
    return d;
  } else {
    puts("Cannot dequeue");
  }
}

int main() {
  size_t size = 6;
  queue_t mq = create(size);
  display(mq);
  for(size_t i = 1; i < (size / 2) + 1; i++) {
    enqueue(&mq,1);
  }
  for(size_t i = 1; i < (size / 2) - 1 ; i++){
    dequeue(&mq);
    display(mq);
  }
  puts("Deque complete");
  for(size_t i = 1; i < size / 2 - 1; i++){
    enqueue(&mq,i + 10);
    display(mq);
  }
  puts("Enqueque complete");
  for(size_t i = 1; i < (size / 2); i++){
    dequeue(&mq);
    display(mq);
  }
}
