/* use a linked list to store each element 
in the snowflakes array will point to the first snowflakes
in the linked list */
/* each snowflake_node contains both a snowflake and pointer 
to the next snowflake element */
#include <stdio.h>
#include <stdlib.h>

#define SIZE 100000

typedef struct snowflake_node
{
    int snowflake[6];
    struct snowflake_node *next;
} snowflake_node;

int main(void)
{
    static snowflake_node *snowflakes[SIZE] = {NULL};
    snowflake_node *snow;
    int n, i, j, snowflake_code;
    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        snow = malloc(sizeof(snowflake_node));
        if (snow == NULL) {
            fprintf(stderr, "malloc error\n");
            exit(1);
        }
    }
    for (j = 0; j < 6; j++) {
        scanf("%d", &snow->snowflake[j]);
        snowflake_code = code(snow->snowflake);
        snow->next = snowflakes[snowflake_code];
        snowflakes[snowflake_code] = snow;
    }
    identify_identical(snowflakes);
    // deallocate all malloc'd memory, if you want to be good
    free(snow);
    return 0;
}

/* identify identical to make all pairwise comparison
 of snowflakes within each linked list */
 void identify_identical(snowflake_node *snowflakes[])
 {
    snowflake_node *node1, *node2;
    int i;
    for (i = 0; i < SIZE; i++) {
        node1 = snowflakes[i];
        while (node1 != NULL) {
            node2 = node1->next;
            while (node2 != NULL) {
            if (are_identical(node1->snowflake, node2->snowflake)) {
               printf("Twin snowflakes found.\n");
               return;
            }
            node2 = node2->next;
        }
        node1 = node1->next;
        }
    }
    printf("No two snowflakes are alike.\n");
 }