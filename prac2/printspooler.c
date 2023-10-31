#include <stdlib.h>
#include <stdio.h>

typedef struct {
  char *title;
  int pages;
} document;

document *new(char *title, int pages){
  document *doc = malloc(sizeof(document));
  doc->title = title;
  doc->pages = pages;
  return doc;
}

void drop(document *doc) {
  free(doc);
}

typedef struct {
  document **buffer;
  size_t capacity;
  size_t size;
  size_t left;
  size_t right;
} spool;

spool create_spool(size_t capacity) {
  document **buffer = calloc(capacity, sizeof(document));  
  spool queue = {
    .buffer = buffer,
    .capacity = capacity,
    .size = 0,
    .left = capacity - 1,
    .right = capacity - 1,
  };
  return queue;
}

int checks(spool q) {
  return 
    q.left <= q.right &&
    q.left >= 0 && q.right >= 0 &&
    q.left < q.capacity && q.right < q.capacity;
}

void enqueue(spool *q, document *element) {
  if (checks(*q) && q->left > 0) {
    q->buffer[q->left] = element;
    q->left -= 1;
    q->size += 1;
  } else {
    puts("Cannot enqueue. Queue is full");
  }
}

document *dequeue(spool *q) {
  if (checks(*q) && q->right < q->capacity) {
    document *d;
    d = q->buffer[q->right];
    q->right -= 1;
    q->size -= 1;
    return d;
  } else {
    puts("Cannot dequeue. Queue is empty");
    return NULL;
  }
}

int main() {
  char *document_name[] = {"recipes", "DCIM 20231001_099", "DCIM 20231001_091", "Assignment - 5", "Assignment - 4"};
  int pages[] = {12, 1, 1, 24, 20};

  spool spool_queue = create_spool(9);
  for(size_t i = 0; i < sizeof(pages)/sizeof(int); i += 1){
    enqueue(&spool_queue, new(document_name[i], pages[i]));
  }

  for(size_t i = 0; i < 9; i += 1){
    document *de = dequeue(&spool_queue);
    if (de != NULL) {
      printf("Document No: %d\n\tTitle:\t%s \n\tPages:\t%d\n", i + 1, de->title, de->pages);
    } else {
      puts("Cannot dequeue. Queue is empty");
      break;
    }
  }
}
