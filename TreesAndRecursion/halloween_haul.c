/* 
 * Input: it consists of exactly five lines, where each line is a string
 * at most 255 characters that describes a neighborhood.
 * Output: it will be five lines of text, with each line corresponding to one
 * of the input lines. Each line of output contains two integers separated by a
 * space.
 * 1- the minimum number of streets walked to obtain all of the candy.
 * 2- the total amount of candy obtained.
 * Building a node.
 *         C        node *four = malloc(sizeof(node));
 *        / \       four->candy = 4; four->left = NULL; four->right = NULL;
 *       B   15     node *nine = malloc(sizeof(node));
 *      / \         nine->candy = 9; nine->left = NULL; nine->right = NULL;
 *     4   9        node *B = malloc(sizeof(node));
 *                  B->left = four; B->right = nine;
 *
 * helper function for four, nine, B code while adding C and 15.
 * node *four = new_house(4);
 * node *nine = new_house(9);
 * node *B = new_nonhouse(four, nine);
 * node *fifteen = new_house(15);
 * node *C = new_nonhouse(B, fifteen);
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct node {
  int candy;
  struct node *left, *right;
} node;

// helper function for creating nodes.
node *new_house(int candy) {
  node *house = malloc(sizeof(node));
  if (house == NULL) {
    fprintf(stderr, "malloc error\n");
    exit(1);
  }
  // initializing attributes values.
  house->candy = candy;
  house->right = NULL;
  house->left = NULL;
  return house;
}

node *new_nonhouse(node *left, node *right) {
  node *nonhouse = malloc(sizeof(node));
  if (nonhouse == NULL) {
    fprintf(stderr, "malloc error\n");
    exit(1);
  }
  nonhouse->left = left;
  nonhouse->right = right;
  return nonhouse;
}

// Implemeting a stack.
#define SIZE 255

typedef struct stack {
  node *values[SIZE];
  int highest_used;
} stack;

stack *new_stack(void) {
  stack *s = malloc(sizeof(stack));
  if (s == NULL) {
   fprintf(stderr, "malloc error\n");
   exit(1);
 }
 s->highest_used = -1;   // -1 mean an empty stack
 return s;
}
// push stack or add
void push_stack(stack *s, node *value) {
  s->highest_used++;
  s->values[s->highest_used] = value;
}
// pop stack or remove
node *pop_stack(stack *s) {
  node *ret = s->values[s->highest_used];
  s->highest_used--;
  return ret;
}
// determines whether the stack is empty before popping
int is_empty_stack(stack *s) {
  return s->highest_used = -1;
}

// the total amount of candy
int tree_candy(node *tree) {
  int total = 0;
  stack *s = new_stack();
  while (tree != NULL) {
      if (tree->left && tree->right) {   // check nonhouse node
        push_stack(s, tree->left);
	tree = tree->right;
      } else {                           // check housenode
        total = total + tree->candy;
	 if (is_empty_stack(s))
           tree = NULL;
	 else
	   tree = pop_stack(s);
      }
  }
  return total;
}

int main(void) {
  stack *s;
  s = new_stack();
  node *n, *n1, *n2, *n3;
  n1 = new_house(20);
  n2 = new_house(30);
  n3 = new_house(10);
  push_stack(s, n1);
  push_stack(s, n2);
  push_stack(s, n3);
  while (!is_empty_stack(s)) {
     n = pop_stack(s);
     printf("The total candy is:%d\n", n->candy);
  }
  return 0;
}




