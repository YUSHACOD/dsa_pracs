#include <stdio.h>
#include <stdlib.h>

typedef struct stack {
  int top;
  int *arr;
  int MAX_SIZE;
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
    printf("The stack is empty. Underflow. Exitting the program.\n");
    exit(1);
  } else {
    return s->arr[s->top];
  }
}

int pop(stack *s) {
  if (s->top == -1) {
    printf("The stack is empty. Underflow. Exitting the program.\n");
    exit(1);
  } else {
    int temp = s->arr[s->top];
    s->top -= 1;
    return temp;
  }
}

void push(stack *s, int value) {
  if (s->top == -1) {
    s->arr = (int *)calloc(s->MAX_SIZE, sizeof(int));
    s->top += 1;
    s->arr[s->top] = value;
  } else if (s->top == s->MAX_SIZE - 1) {
    printf("No Space in stack. Overflow. Exitting the program...\n");
    exit(1);
  } else {
    s->top += 1;
    s->arr[s->top] = value;
  }
}

/*
int main() {
  stack s = {
		.top = -1,
	  .arr = NULL,
	.MAX_SIZE = 15
  };
  
  // For testing peek
	 push(&s, 4);
	 printf("Now at the top of the stack we have : %d\n",peek(&s));
	 printf("Poping from the stack : %d\n",pop(&s));
	 printf("Now at the top of the stack we have : %d\n",peek(&s));

  // For testing pop
  push(&s, 4);
  printf("Now at the top of the stack we have : %d\n",peek(&s));
  printf("Poping from the stack : %d\n",pop(&s));
  printf("Now at the top of the stack we pop to get : %d\n",pop(&s));


  // For testing push function
  int c = 0;
  for (int i = 6 + 0; i < 6 + 16; i++) {
	  push(&s, i);
	  printf("Now at the top of the stack we have : %d\n",peek(&s));
	  printf("Count of pushes into stack : %d\n",1 + c++);
  }
  
  return 0;
}
*/
