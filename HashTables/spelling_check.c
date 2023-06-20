/* We are given strings s1 and s2. The first string has 
 * one more string than the second. Determines the number 
 * of ways in which one character can be deleted from the
 * first string.
 * EX: input s1: abcdxxxef, s2: abcdxxef.
 *     output n = 3: the number of ways in which a character can be deleted
 *     from s1 to get s2.
 *     5 6 7 : the indices(from 1) of characters of s1 that can be removed to get s2.
 *     Otherwise output 0.
 */
#include <stdio.h>
#include <string.h>

#define SIZE 1000000

int prefix_length(char s1[], char s2[]);
int suffix_length(char s1[], char s2[], int len);

int main(void) {
  static char s1[SIZE + 2], s2[SIZE + 2];
  int len , prefix, suffix, total;
 fgets(&s1[1], SIZE, stdin);
 fgets(&s2[1], SIZE, stdin);

  len = strlen(&s1[1]);
  prefix = prefix_length(s1, s2);
  suffix = suffix_length(s1, s2, len);
  total = (prefix + 1) - (len - suffix) + 1;
  if (total < 0)
  total = 0;

  printf("%d\n", total);
  for (int i = 0; i < total; i++) {
  printf("%d", i + len - suffix);
  if (i < total - 1)
     printf(" ");
  else
     printf("\n");
  }
  return 0;
}
/* build the common prefix array. long long is a very large integer type in C99.
unsigned long long prefix1[1000001];
prefix1[0] = 0;
for (int i = 1; i <= strlen(first_string); i++)
    prefix1[i] = prefix1[i - 1] * 39 + first_string[i];
*/
// calculate the length of the longest common prefix(i-1).
int prefix_length(char s1[], char s2[]) {
  int i = 1;
  while (s1[i] == s2[i])
     i++;
  return i - 1; 
}

// the longest common suffix.
int suffix_length(char s1[], char s2[], int len) {
   int i = len;
   while(i >= 2 && s1[i] == s2[i - 1])
     i--;
   return len - i;  
}






