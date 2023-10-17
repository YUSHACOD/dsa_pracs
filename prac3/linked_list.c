#include <stdio.h>
#include <stdlib.h>

typedef struct node {
  int value;
  struct node *next;
} node;

typedef struct linked_list {
  node *start;
  int size;
} linked_list;

void initialize_ll(linked_list *l) {
  l->start = NULL;
  l->size = 0;
}

node *get_node() {
  node *n;
  if ((n = (node *)malloc(sizeof(node))) == NULL) {
    printf("Not able to allocate memmory.Exitting program....\n");
    exit(1);
  }
  n->next = NULL;
  return n;
}

void add_node_to_ll(linked_list *l, int value) {

  node *temp;
  temp = l->start;

  if (temp != NULL) {

    while (temp->next != NULL)
      temp = temp->next;
    temp->next = get_node();
    temp = temp->next;
    temp->value = value;
  } else {

    l->start = get_node();
    temp = l->start;
    temp->value = value;
  }
  l->size += 1;
}

void traverse_ll(linked_list *l) {
  if (l->size == 0) {

    printf("First initialize the linked list.\n");
    return;
  } else {

    node *temp;
    temp = l->start;
    int i;
    for (i = 0; temp->next != NULL; i++) {
      printf("%d : %d\n", i + 1, temp->value);
      temp = temp->next;
    }
    printf("%d : %d\n", i + 1, temp->value);
  }
}

int main(int argc, char *argv[]) {

  printf("hola\n");

  linked_list l;
  initialize_ll(&l);

  add_node_to_ll(&l, 4);
  add_node_to_ll(&l, 5);
  add_node_to_ll(&l, 6);
  add_node_to_ll(&l, 8);

  traverse_ll(&l);

  return 0;
}
