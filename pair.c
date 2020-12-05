#include "pair.h"

#include <stdlib.h>
#include <string.h>

/* create a pair of strings */
struct pair_t *create_pair(const char *a, const char *b) {
  /* allocate struct */
  struct pair_t *ptr = (struct pair_t *)malloc(sizeof(struct pair_t));
  memset(ptr, 0x0, sizeof(struct pair_t));

  if (!ptr) return NULL;

  /* assign data members */
  if (a) {
    ptr->x = (char *)malloc(strlen(a) + 1);
    strcpy(ptr->x, a);
  } else
    ptr->x = NULL;

  if (b) {
    ptr->y = (char *)malloc(strlen(b) + 1);
    strcpy(ptr->y, b);
  } else
    ptr->y = NULL;

  /* return resulting pointer */
  return ptr;
}


/* destroy the pair of strings */
void destroy_pair(struct pair_t *pair) {
  if (pair) { /* only ddestroy if it exists */
    if (pair->x)
      free(pair->x);
    if (pair->y)
      free(pair->y);

    free(pair);
  } 
}

