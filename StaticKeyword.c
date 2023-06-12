/*
 * Using a static variable to access
 * the program scope
 * Compile C program: gcc -0 file_name file_name.c
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int function(void) {
 static int x = 5;
 printf("%d\n", x);
  x++;
}

int main(void) {
 function();
 function();
 function();
 return 0;
}
