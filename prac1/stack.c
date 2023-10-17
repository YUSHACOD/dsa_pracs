#include <stdio.h>
#include <stdlib.h>

typedef struct stack {
  int top;
  int max_size;
  int *arr;
} stack;

int stack_is_empty(stack *s) {
  if (s->top == -1) {
    return 1;
  } else {
    return 0;
  }
}

int peek(stack *s) {
  if (s->top == -1) {
    printf("The stack is empty.Exitting the program.\n");
    exit(1);
  }
  return s->arr[s->top];
}

int pop(stack *s) {
  if (s->top == -1) {
    printf("The stack is empty.Exitting the program.\n");
    exit(1);
  }
  int temp = s->arr[s->top];
  s->top -= 1;
  return temp;
}

void push(stack *s, int value) {
  if (s->top == -1) {
    s->arr = (int *)calloc(10, sizeof(int));
    s->max_size = 10;
  } else if ((s->top + 1) == s->max_size) {
    s->arr = (int *)realloc(s->arr, 2 * s->top * sizeof(int));
    s->max_size = 2 * (s->top + 1);
  }
  s->top += 1;
  s->arr[s->top] = value;
}

void clear_stack(stack *s) {
  s->top = -1;
  s->arr = NULL;
  s->max_size = 0;
}

// int main() {
//   stack s;
//   clear_stack(&s);

//   printf("Creating the stack...\n");
//   for (int i = 0; i < 15; i++) {
//     push(&s, 3);
//     printf("Peeking value at %d : %d\n", s.top, peek(&s));
//   }

//   printf("Maxsize is %d.\n", s.max_size);
//   for (int i = 15; i > -1; i--) {
//     int t = s.top;
//     printf("Poping value at %d : %d\n", t, pop(&s));
//   }

//   return 0;
// }
