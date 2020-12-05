#include <stdio.h>
#include <stdlib.h>
#include "string.h"

#include "pair.h"

/*
 * This program when given a list of names, should output pairs of names.
 * When given groups, should output pairs of groups.
 *
 * People and groups could be treated the same, just pairing two together.
*/

/* macro for unused arguments */
#define unused(x) (void)(x)

/* default values for input and output paths */
const char *kDefault_input = "people.txt";
const char *kDefault_output = "result.txt";


/* gets passed a file pointer, returns number of lines in file. */
static int get_file_length(FILE *fp) {
  int acc = 0;
  if (!fp) return -1;

  /* loop through file, until end counting newlines */
  for (char c = getc(fp); c != EOF; c = getc(fp)) 
    if (c == '\n')
        ++acc; 

  /* return file pointer to beginning */
  fseek(fp, 0, SEEK_SET);
  return acc;  
}


/* read a files contents */
static char **get_file_lines(FILE *fp, int *len) {
  int lines = *len = get_file_length(fp);
  char **contents = malloc(lines * sizeof(char *));
  if (!contents) return NULL;

  for (int i = 0; i < lines; ++i) {
    char *line = NULL; /* TODO: Fails when we try to add line, getline doesnt allocate. */
    getline(&line, NULL, fp);

    /* fails here, trying to dereference null pointer in strlen. */
    contents[i] = (char *)malloc(strlen(line) + 1);
  }

  return contents;
}


/* entry point */
int main (int argc, char **argv) {
  unused(argc);
  unused(argv);

  FILE *fp = fopen(kDefault_input, "r");
  if (!fp) return -1;

  int len = 0;
  char **contents = get_file_lines(fp, &len);

  for (int i = 0; i < len; ++i) {
    printf("%s\n", contents[i]);
  }

  return 0;
}
