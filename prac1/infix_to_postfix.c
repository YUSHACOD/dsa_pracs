#include "stack.c"
#include <stdio.h>
#include <stdlib.h>

int check_expresssion(char *expression, int length) {

  stack temp;
  clear_stack(&temp);

  for (int i = 0; i < length; i++) {

    char c = expression[i];

    switch (c) {

    case '{': {
      push(&temp, c);
    } break;

    case '}': {
      if (peek(&temp) == ('{')) {
        pop(&temp);
      } else {
        printf("%c from expression point %d, char %c", peek(&temp), i, c);
        return 0;
      }
    } break;

    case '(': {
      push(&temp, c);
    } break;

    case ')': {
      if (peek(&temp) == ('(')) {
        pop(&temp);
      } else {
        printf("%c from expression point %d, char %c", peek(&temp), i, c);
        return 0;
      }
    } break;

    case '[': {
      push(&temp, c);
    } break;

    case ']': {
      if (peek(&temp) == ('[')) {
        pop(&temp);
      } else {
        printf("%c from expression point %d, char %c", peek(&temp), i, c);
        return 0;
      }
    } break;

    default:
      break;
    }
  }

  if (temp.top == -1) {
    return 1;
  } else {
    return 0;
  }
}

int precedence(char c) {

  switch (c) {
  case '%':
    return 2;
    break;

  case '*':
    return 2;
    break;

  case '/':
    return 2;
    break;

  case '+':
    return 1;
    break;

  case '-':
    return 1;
    break;

  default:
    return 0;
    break;
  }
}

char *convert_to_postfix(char *original_expression,
                         int original_expression_length) {

  stack stash;
  clear_stack(&stash);
  stack resulting_expression;
  clear_stack(&resulting_expression);

  for (int i = 0; i < original_expression_length; i++) {

    char c = original_expression[i];
    printf("On %c from the expression.\n", c);

    switch (c) {

    case ('('): {
      push(&stash, c);
    } break;

    case (')'): {
      while (peek(&stash) != ('(')) {
        push(&resulting_expression, pop(&stash));
      }
      pop(&stash);
    } break;

    case ('%'): {
      if ((precedence(c) > precedence((char)peek(&stash))) ||
          stack_is_empty(&stash) || ((char)peek(&stash) == '(')) {

        push(&stash, c);
      } else {

        while (peek(&stash) != ('(')) {
          if (precedence(c) >= precedence((char)peek(&stash)))
            push(&resulting_expression, pop(&stash));
        }
        pop(&stash);
        push(&stash, c);
      }
    } break;

    case ('*'): {
      if ((precedence(c) > precedence((char)peek(&stash))) ||
          stack_is_empty(&stash) || ((char)peek(&stash) == '(')) {

        push(&stash, c);
      } else {

        while (peek(&stash) != ('(')) {
          if (precedence(c) >= precedence((char)peek(&stash)))
            push(&resulting_expression, pop(&stash));
        }
        pop(&stash);
        push(&stash, c);
      }
    } break;

    case ('/'): {
      if ((precedence(c) > precedence((char)peek(&stash))) ||
          stack_is_empty(&stash) || ((char)peek(&stash) == '(')) {

        push(&stash, c);
      } else {

        while (peek(&stash) != ('(')) {
          if (precedence(c) >= precedence((char)peek(&stash)))
            push(&resulting_expression, pop(&stash));
        }
        pop(&stash);
        push(&stash, c);
      }
    } break;

    case ('+'): {
      if ((precedence(c) > precedence((char)peek(&stash))) ||
          stack_is_empty(&stash) || ((char)peek(&stash) == '(')) {

        push(&stash, c);
      } else {

        while (peek(&stash) != ('(')) {
          if (precedence(c) >= precedence((char)peek(&stash)))
            push(&resulting_expression, pop(&stash));
        }
        pop(&stash);
        push(&stash, c);
      }
    } break;

    case ('-'): {

      if ((precedence(c) > precedence((char)peek(&stash))) ||
          stack_is_empty(&stash) || ((char)peek(&stash) == '(')) {

        push(&stash, c);
      } else {

        while (peek(&stash) != ('(')) {
          if (precedence(c) >= precedence((char)peek(&stash)))
            push(&resulting_expression, pop(&stash));
        }
        pop(&stash);
        push(&stash, c);
      }
    } break;

    default:
      push(&resulting_expression, c);
      break;
    }

    if (!stack_is_empty(&stash))
      printf("State of stash : %c.\n", peek(&stash));
    if (!stack_is_empty(&resulting_expression))
      printf("State of stack : %c.\n", peek(&resulting_expression));
  }

  printf("Length of the stack is %d.\n", resulting_expression.top + 1);
  char *c = (char *)calloc(resulting_expression.top, sizeof(char));
  for (int i = resulting_expression.top; i >= 0; i--) {
    printf("State of the stack %c.\n", peek(&resulting_expression));
    c[i] = pop(&resulting_expression);
  }

  return c;
}

int main(int argc, char **argv) {

  char *original_expression;
  int original_expression_length;

  printf("Enter the length of the expression : ");
  scanf("%d", &original_expression_length);

  original_expression =
      (char *)calloc(original_expression_length, sizeof(char));
  printf("\n");
  printf("Enter the expression string : ");
  scanf("%s", original_expression);

  if (check_expresssion(original_expression, original_expression_length)) {
    printf("Success. Expression is good.\n");
  } else {
    printf("Bad expression. Exitting program...");
    exit(1);
  }

  printf("The postfixed expression is : %s\n",
         convert_to_postfix(original_expression, original_expression_length));

  return 0;
}
