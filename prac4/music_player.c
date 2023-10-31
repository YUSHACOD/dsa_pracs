#include <stdio.h>
#include <stdlib.h>

typedef struct song_struct {
  int duration;
  int index;
  int id;
} song_struct;

typedef struct node {
    song_struct song;
    struct node *next;
    struct node *prev;
} node;

typedef struct dll {
    node *start;
} dll;

node *get_node(song_struct song) {
    node *n = (node *) malloc(sizeof(node));
    n->next = NULL;
    n->prev = NULL;
    n->song = song;
    return n;
}

void insert_at_start(dll *list,song_struct song) {
    if (list->start == NULL) {
        list->start = get_node(song);
    } else {
        node *temp = list->start;
        list->start = get_node(song);
        list->start->next = temp;
        temp->prev = list->start;
    }
}

void insert_at_end(dll *list,song_struct song) {
    if (list->start == NULL) {
        list->start = get_node(song);
    } else {
        node *temp = list->start;
        while (temp->next != NULL) {
            temp = temp->next;
        }

        temp->next = get_node(song);
        temp->next->prev = temp;
    }
}

void insert_before_num(dll *l, song_struct song, int id) {

  if (l->start == NULL) {
    l->start = get_node(song);
  } else {
    node *temp = l->start;
    while (temp->song.id != id) {
      temp = temp->next;
    }
    
    node *p1 = temp->prev;
    p1->next = get_node(song);
    p1->next->prev = p1;
    p1->next->next = temp;
    temp->prev = p1->next;

  }

}

void insert_after_num(dll *l, song_struct song, int id) {

  if (l->start == NULL) {
    l->start = get_node(song);
  } else {
    node *temp = l->start;
    while (temp->song.id != id) {
      temp = temp->next;
    }

    node *p1 = temp->next;
    temp->next = get_node(song);
    temp->next->prev = temp;
    temp->next->next = p1;
    p1->prev = temp->next;
    
  }

}

song_struct delete_at_start(dll *list) {
    if (list->start == NULL) {
        printf("No element in doubly linked list to delete.\n");
        exit(1);
    } else {
        song_struct song = list->start->song;
        list->start = list->start->next;
        free(list->start->prev);
        list->start->prev = NULL;
        return song;
    }
}

song_struct delete_at_end(dll *list) {
    if (list->start == NULL) {
        printf("No element in doubly linked list to delete.\n");
        exit(1);
    } else {
        node *temp = list->start;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        
        song_struct song = temp->song;
        temp = temp->prev;
        free(temp->next);
        temp->next = NULL;
    }
}

song_struct delete_before_num(dll *l, int id) {

  if (l->start == NULL) {
    printf("List is empty. Cannot delete. Underflow.\n");
  } else {
    node *temp = l->start;
    while (temp->next->next->song.id != id) {
      temp = temp->next;
    }

    song_struct song = temp->next->song;
    temp->next->next->prev = temp;
    node *p = temp->next->next;
    free(temp->next);
    temp->next = p;

    return song;
  }

}

song_struct delete_after_num(dll *l, int id) {

  if (l->start == NULL) {
    printf("List is empty. Cannot delete. Underflow.\n");
  } else {
    node *temp = l->start;
    while (temp->song.id != id) {
      temp = temp->next;
    }

    song_struct song = temp->next->song;
    temp->next->next->prev = temp;
    node *p = temp->next->next;
    free(temp->next);
    temp->next = p;

    return song;
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
            printf("song at %d : %d.\n", c, temp->song.id);
            temp = temp->next;
        }
        c++;
        printf("song at %d : %d.\n", c, temp->song.id);
    }
}

int main() {

  dll list = {
    .start = NULL
  };


    return 0;
}