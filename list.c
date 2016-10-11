#include <stdlib.h>
#include <stdio.h>

struct node {
  int i;
  struct node *nxt;
};

void print_list(struct node *n) {
  if (n->nxt != NULL) {
    printf("%d, ", n->i);
    print_list(n->nxt);
  } else {
    printf("%d\n", n->i);
  }
}

struct node * insert_front(struct node *list, int newvalue) {
  struct node *n = malloc(sizeof(list));
  n->nxt = list;
  n->i = newvalue;
  return n;
}

struct node * free_list(struct node *list, struct node *curr) {
  if (curr == NULL) {
    curr = list;
  }
  if (curr->nxt == NULL) {
    return list;
  } else {
    free(curr);
    return free_list(list, curr->nxt);
  }
}

int main() {
  struct node *list = insert_front(insert_front(insert_front(insert_front(NULL, 2), 4), 9), 7);
  print_list(list);
  free_list(list, NULL);
  
}
