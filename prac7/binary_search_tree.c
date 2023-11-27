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
  if (root == NULL) {
    printf("Tree is empty\n");
    exit(2);
  } else if (root->data >= data) {

    if (root->left == NULL) {

      root->left = get_node(data);
      return 0;

    } else {
      insert_node(root->left, data);
    }
  } else {

    if (root->right == NULL) {
      root->right = get_node(data);
      return 0;
    } else {
      insert_node(root->right, data);
    }
  }
  return 1;
}

void traverse_LNR(node *root) {
  if (root != NULL) {
    traverse_LNR(root->left);
    printf("%d\t", root->data);
    traverse_LNR(root->right);
  } else {
    return;
  }
}

void traverse_NLR(node *root) {
  if (root != NULL) {
    printf("%d\t", root->data);
    traverse_LNR(root->left);
    traverse_LNR(root->right);
  } else {
    return;
  }
}

void traverse_LRN(node *root) {
  if (root != NULL) {
    traverse_LNR(root->left);
    traverse_LNR(root->right);
    printf("%d\t", root->data);
  } else {
    return;
  }
}

int main(int argc, char *argv[]) {
  b_tree t1 = {.root = NULL};
  create_tree(&t1, 4);

  insert_node(t1.root, 5);
  insert_node(t1.root, 8);
  insert_node(t1.root, 2);
  insert_node(t1.root, 9);
  insert_node(t1.root, 1);
  insert_node(t1.root, 3);

  printf("NLR Traversal : ");
  traverse_NLR(t1.root);
  printf("\n");

  printf("LNR Traversal : ");
  traverse_LNR(t1.root);
  printf("\n");

  printf("LRN Traversal : ");
  traverse_LRN(t1.root);
  printf("\n");

  return 0;
}
