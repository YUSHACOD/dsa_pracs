#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct node {
  struct node *left;
  struct node *right;
  int data;
} node;

typedef struct {
  struct node *root;
  int inorder_traversal[1000];
  int len;
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

void create_tree(b_tree *tree, int data) {
  tree->root = get_node(data);
  tree->inorder_traversal[0] = data;
  tree->len = 1;
}

void destroy_tree(node *root) {
	if (root != NULL) {
		destroy_tree(root->left);
		destroy_tree(root->right);
		free(root);
	} else {
		return;
	}
}

bool insert_node_aux(node *root, int *traversal, int start, int end,
                     bool right) {
  int mid = (end + start) / 2;
  if (start > end) {
    return false;
  } else if (start == end) {
    if (right) {
      root->right = get_node(traversal[mid]);
      return true;
    } else {
      root->left = get_node(traversal[mid]);
      return true;
    }
  } else {
    if (right) {
      root->right = get_node(traversal[mid]);
      return (insert_node_aux(root->right, traversal, mid + 1, end, true)) &&
             (insert_node_aux(root->right, traversal, start, mid - 1, false));
    } else {
      root->left = get_node(traversal[mid]);
      return (insert_node_aux(root->left, traversal, mid + 1, end, true)) &&
             (insert_node_aux(root->left, traversal, start, mid - 1, false));
    }
  }
}

void swap(int *p, int *q) {
  int t = *p;
  *p = *q;
  *q = t;
}

void insertion_sort(int *arr, int len) {
  for (int i = 0; i < len; i++) {
    int smallest = i;
    for (int j = i; j < len; j++) {
      if (arr[smallest] > arr[j]) {
        smallest = j;
      }
    }
    swap(&arr[i], &arr[smallest]);
  }
}

void print_array(int *arr, int len) {
  printf("\n");
  for (int i = 0; i < len; i++) {
    printf("%d\t", arr[i]);
  }
  printf("\n");
}

bool insert_node(b_tree *tree, int data) {
  if (tree->root == NULL) {
    create_tree(tree, data);
    return true;
  } else {
    tree->inorder_traversal[tree->len] = data;
    tree->len += 1;

    insertion_sort(tree->inorder_traversal, tree->len);

    int mid = (tree->len - 1) / 2;
	destroy_tree(tree->root);
    tree->root = get_node(tree->inorder_traversal[mid]);

    return (insert_node_aux(tree->root, tree->inorder_traversal, mid + 1,
                            tree->len - 1, true)) &&
           (insert_node_aux(tree->root, tree->inorder_traversal, 0, mid - 1,
                            false));
  }
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

  insert_node(&t1, 5);
  insert_node(&t1, 8);
  insert_node(&t1, 2);
  insert_node(&t1, 9);
  insert_node(&t1, 1);
  insert_node(&t1, 3);

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
