#include <stdio.h>
#include <stdlib.h>

typedef struct node {
	int value;
	struct node *next;
} node;

typedef struct linked_list {
	node *head;
} linked_list;

node *get_node(int data) {
	node *n;
	if ((n = (node *)malloc(sizeof(node))) == NULL) {
		printf("Not able to allocate memmory.Exitting program....\n");
		exit(1);
	}

	n->next = NULL;
	n->value = data;
	return n;
}

void insert_at_end(linked_list *l, int value) {

  if (l->head == NULL) {
    l->head = get_node(value);
  } else {
    node *temp = l->head;
    while (temp->next != NULL) {
      temp = temp->next;
    }

    temp->next = get_node(value);
  }

}

void insert_at_start(linked_list *l, int value) {

  if (l->head == NULL) {
    l->head = get_node(value);
  } else {
    node *temp = l->head;
    l->head = get_node(value);
    l->head->next = temp;
  }

}

void insert_before_num(linked_list *l, int value, int id) {

  if (l->head == NULL) {
    l->head = get_node(value);
  } else {
    node *temp = l->head;
    while (temp->next->value != id) {
      temp = temp->next;
    }

    node *ptr = temp->next;
    temp->next = get_node(value);
    temp->next->next = ptr;
  }

}

void insert_after_num(linked_list *l, int value, int id) {

  if (l->head == NULL) {
    l->head = get_node(value);
  } else {
    node *temp = l->head;
    while (temp->value != id) {
      temp = temp->next;
    }

    node *ptr = temp->next;
    temp->next = get_node(value);
    temp->next->next = ptr;
  }

}

int delete_at_start(linked_list *l) {

  if (l->head == NULL) {
    printf("List is empty. Cannot delete. Underflow.\n");
  } else {
    int value = l->head->value;
    node *temp = l->head->next;
    free(l->head);
    l->head = temp;
    return value;
  }

}

int delete_at_end(linked_list *l) {

  if (l->head == NULL) {
    printf("List is empty. Cannot delete. Underflow.\n");
  } else {
    node *temp = l->head;
    while (temp->next->next != NULL) {
      temp = temp->next;
    }
    int value = temp->next->value;
    free(temp->next);
    temp->next = NULL;
    return value;
  }

}

int delete_before_num(linked_list *l, int id) {

  if (l->head == NULL) {
    printf("List is empty. Cannot delete. Underflow.\n");
  } else {
    node *temp = l->head;
    while (temp->next->next->value != id) {
      temp = temp->next;
    }

    int n = temp->next->value;
    node *ptr = temp->next->next;
    free(temp->next);
    temp->next = ptr;
    return n;
  }

}

int delete_after_num(linked_list *l, int id) {

  if (l->head == NULL) {
    printf("List is empty. Cannot delete. Underflow.\n");
  } else {
    node *temp = l->head;
    while (temp->value != id) {
      temp = temp->next;
    }

    int n = temp->next->value;
    node *ptr = temp->next->next;
    free(temp->next);
    temp->next = ptr;
    return n;
  }

}

void traverse(linked_list *l) {

  if (l->head == NULL) {
    printf("First initialize the linked list.\n");
    return;
  } else {
    node *temp;
    temp = l->head;
    int i;
    for (i = 0; temp->next != NULL; i++) {
      printf("%d : %d\n", i + 1, temp->value);
      temp = temp->next;
    }
    printf("%d : %d\n", i + 1, temp->value);
  }

}

int find_nth_from_last(linked_list *l, int n) {

  node *temp = l->head;
  int length = 0;
  while (temp != NULL) {
    temp = temp->next;
    length += 1;
  }
  length += 1;
  temp = l->head;

  for (int i = 0; i < length - n - 1; i++) {
    temp = temp->next;
  }
  n = temp->value;
  return n;

}

void test_last_nth_node() {
  linked_list l = {
    .head = NULL
  };
  insert_at_start(&l, 5);
  insert_at_start(&l, 6);
  insert_after_num(&l, 54, 6);
  insert_at_end(&l, 7);
  insert_before_num(&l, 37, 5);
  printf("\n");
  printf("\n");
  traverse(&l);
  printf("\n");

  int n = 1;
  printf("The last %dth node from the end is : %d.\n", n, find_nth_from_last(&l, n));
}

int main(int argc, char *argv[]) {

  linked_list list = {
	  .head = NULL
  };

  printf("Testing insertion of the linked_list.\n");
  insert_at_start(&list, 5);
  traverse(&list);
  printf("\n");
  insert_at_start(&list, 6);
  traverse(&list);
  printf("\n");
  insert_after_num(&list, 54, 6);
  traverse(&list);
  printf("\n");
  insert_at_end(&list, 7);
  traverse(&list);
  printf("\n");
  insert_before_num(&list, 37, 5);
  traverse(&list);
  printf("\n");
  
  printf("Testing deletion of the linked_list.\n");
  insert_at_end(&list, 8);
  traverse(&list);
  printf("\n");
  delete_at_end(&list);
  traverse(&list);
  printf("\n");
  delete_at_start(&list);
  traverse(&list);
  printf("\n");
  delete_after_num(&list,37);
  traverse(&list);
  printf("\n");
  delete_before_num(&list,7);
  traverse(&list);
  printf("\n");
  
  printf("Testing traversal of the linked_list.\n");
  insert_at_end(&list, 8);
  traverse(&list);
  printf("\n");
  insert_at_end(&list, 9);
  traverse(&list);
  printf("\n");
  insert_at_end(&list, 10);
  traverse(&list);

  test_last_nth_node();
  return 0;
}
