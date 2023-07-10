#include <stdio.h>
#include <stdlib.h>

// Implemeting a stack.
#define SIZE 255

typedef struct node {
  int candy;
  struct node *left, *right;
} node;

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