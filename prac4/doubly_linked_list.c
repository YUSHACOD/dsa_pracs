#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *next;
    struct node *prev;
} node;

typedef struct dll {
    node *start;
} dll;

node *get_node(int data) {
    node *n = (node *) malloc(sizeof(node));
    n->next = NULL;
    n->prev = NULL;
    n->data = data;
    return n;
}

void insert_at_start(dll *list,int data) {
    if (list->start == NULL) {
        list->start = get_node(data);
    } else {
        node *temp = list->start;
        list->start = get_node(data);
        list->start->next = temp;
        temp->prev = list->start;
    }
}

void insert_at_end(dll *list, int data) {
    if (list->start == NULL) {
        list->start = get_node(data);
    } else {
        node *temp = list->start;
        while (temp->next != NULL) {
            temp = temp->next;
        }

        temp->next = get_node(data);
        temp->next->prev = temp;
    }
}

void insert_before_num(dll *l, int value, int id) {

  if (l->start == NULL) {
    l->start = get_node(value);
  } else {
    node *temp = l->start;
    while (temp->data != id) {
      temp = temp->next;
    }
    
    node *p1 = temp->prev;
    p1->next = get_node(value);
    p1->next->prev = p1;
    p1->next->next = temp;
    temp->prev = p1->next;

  }

}

void insert_after_num(dll *l, int value, int id) {

  if (l->start == NULL) {
    l->start = get_node(value);
  } else {
    node *temp = l->start;
    while (temp->data != id) {
      temp = temp->next;
    }

    node *p1 = temp->next;
    temp->next = get_node(value);
    temp->next->prev = temp;
    temp->next->next = p1;
    p1->prev = temp->next;
    
  }

}

int delete_at_start(dll *list) {
    if (list->start == NULL) {
        printf("No element in doubly linked list to delete.\n");
        exit(1);
    } else {
        int data = list->start->data;
        list->start = list->start->next;
        free(list->start->prev);
        list->start->prev = NULL;
        return data;
    }
}

int delete_at_end(dll *list) {
    if (list->start == NULL) {
        printf("No element in doubly linked list to delete.\n");
        exit(1);
    } else {
        node *temp = list->start;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        
        int data = temp->data;
        temp = temp->prev;
        free(temp->next);
        temp->next = NULL;
    }
}

int delete_before_num(dll *l, int id) {

  if (l->start == NULL) {
    printf("List is empty. Cannot delete. Underflow.\n");
  } else {
    node *temp = l->start;
    while (temp->next->next->data != id) {
      temp = temp->next;
    }

    int n = temp->next->data;
    temp->next->next->prev = temp;
    node *p = temp->next->next;
    free(temp->next);
    temp->next = p;

    return n;
  }

}

int delete_after_num(dll *l, int id) {

  if (l->start == NULL) {
    printf("List is empty. Cannot delete. Underflow.\n");
  } else {
    node *temp = l->start;
    while (temp->data != id) {
      temp = temp->next;
    }

    int n = temp->next->data;
    temp->next->next->prev = temp;
    node *p = temp->next->next;
    free(temp->next);
    temp->next = p;

    return n;
  }

}

void traverse(dll *list) {
    if (list->start == NULL) {
        printf("No element in doubly linked list to print.\n");
        exit(1);
    } else {
        node *temp = list->start;
        int c = 0;
        while (temp->next != NULL) {
            c++;
            printf("Data at %d : %d.\n", c, temp->data);
            temp = temp->next;
        }
        c++;
        printf("Data at %d : %d.\n", c, temp->data);
    }
}

int main() {

    dll list = {
        .start = NULL
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

    return 0;
}