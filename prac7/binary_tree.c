#include <stdio.h>
#include <stdlib.h>

typedef struct node {
  struct node *left;
  struct node *right;
  int data;
} node;

typedef struct {
  struct node *root;
} b_tree;

node *get_node(int data) {
  node *temp;
  if ((temp = (node *)calloc(1, sizeof(node))) == NULL) {
    printf("Not able to assign a node. Heap is Full. Exitting...");
    exit(1);
  };

  // Setting the data ///
  temp->data = data;
  temp->left = NULL;
  temp->right = NULL;
  ///////////////////////

  return temp;
}

void create_tree(b_tree *p, int data) { p->root = get_node(data); }

int insert_node(node *root, int data) {
  if (root->left == NULL) {
    return 0;
  } else if (root->right == NULL) {
    return 0;
  } else {
    insert_node(root->left, data);
    insert_node(root->right, data);
  }
}

int main(int argc, char *argv[]) {
  printf("");
  return 0;
}
