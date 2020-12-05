/*
 * Jack Thake
 *
 * This file holds declarations for the pair struct.
*/

#ifndef __PAIR_H__
#define __PAIR_H__

/* one pair of values */
struct pair_t {
  char *x;
  char *y;
};

/* create a pair of strings */
struct pair_t *create_pair(const char *, const char *);

/* desttroy the pair of strings */
void destroy_pair(struct pair_t *);

#endif
