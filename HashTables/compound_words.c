/* This is UVa problem 10391
Problem: we are given a wordlist in which word is a lowercase
string.
Task: determine the strings in the wordlist that are.
compound words(union of two or more words, either with or without hyphen). 
Ex: the concatenation of exactly two other strings, "create" is a compound word
because it is the concatenation of "crea" and "te";
*/

#include <stdio.h>
#include <stdlib.h>
#include "oaat.c"

/* helper function that read a line */
char *read_line(int size) {
    char *str;
    int ch;
    int len = 0;
    str = malloc(size);
    if (str == NULL) {
       fprintf(stderr, "malloc error\n");
       exit(1);
    }
    while ((ch = getchar()) != EOF && (ch != '\n')) {
        str[len++] = ch;
        if (len == size) {
            size = size * 2;
            str = realloc(str, size);
            if (str == NULL) {
                fprintf(stderr, "realloc error\n");
                exit(1);
            }
        }
    }
    str[len] = '\0';
    return str;
}

/* search a hash table for a given word */
#define NUM_BITS 17

typedef struct word_node {
    char **word;
    struct word_node *next;
} word_node;

int in_hash_table(word_node *hash_table[], char *find,
                  unsigned find_len) {
  unsigned word_code;
  word_node *wordptr;
  word_code = ooat(find, find_len, NUM_BITS);
  wordptr = hash_table[word_code];
  while (wordptr) {
    if ((strlen(*(wordptr->word)) == find_len) &&
         (strncmp(*(wordptr->word), find, find_len) == 0))
      return 1;
    wordptr = wordptr->next;
  }
  return 0;
}

/* check all possible splits of a word */
void identify_compound_words(char *words[], word_node *hash_table[],
                             int total_words) {
int i, j;
unsigned len;
for (i = 0; i < total_words; i++) {
    len = strlen(words[i]);
    for (j = 1; j < len; j++) {
        if (in_hash_table(hash_table, words[i], j) &&
            in_hash_table(hash_table, &words[i][j], len - j)) {
         printf("%s\n", words[i]);
         break;
        }
    }
}
}