/* two snowflakes are identical if they match when we move 
   leftward through the numbers.
   A snowflakes is represented by 6 integers.
   
   #include <stdio.h>

void identify_identical(int values[], int n);

int main(void)
{
    int a[5] = {1, 2, 3, 1, 4};
    identify_identical(a, 5);
    return 0;
}

void identify_identical(int values[], int n) {
    int i, j;
    for (i = 0; i < n; i++) {
        for (j = i+1; j < n; j++) {
            if (values[i] == values[j]) {
             printf("Two integers found.\n");
             return;
            }
        }
    }
    printf("No integers are alike.\n");
}
*/

#include <stdio.h>

#define SIZE 10

int identical_right(int snow1[], int snow2[], int start);
int identical_left(int snow1[], int snow2[], int start);
int are_identical(int snow1[], int snow2[]);
void identify_identical(int snowflakes[][6], int n);

/* read a line containing integer n that tells us 
   how many snowflakes there are and read each of the 
   following n lines as an individual snowflake. 
   EX: 123456 and 456123 are identical snowflakes.
*/
int main(void)
{
  static int snowflakes[SIZE][6];
  int n, i , j;
  printf("Input the number of snowflakes a.k.a row : \n");
  scanf("%d", &n);
  printf("Input each element of n row of snowflakes : ");
  for (i = 0; i < n; i++)
     for (j = 0; j < 6; j++)
       scanf("%d", &snowflakes[i][j]);
 identify_identical(snowflakes, n);
 return 0;
}

// determines the snowflakes are same by moving right
int identical_right(int snow1[], int snow2[], int start)
{
    int offset;
    for (offset = 0; offset < 6; offset++) {
        if (snow1[offset] != snow2[(start + offset) % 6])
        return 0;   // false  
    }
    return 1;   // true
}

// identify indentical snowflakes moving left
int identical_left(int snow1[], int snow2[], int start)
{
    int offset, snow2_index;
    for (offset = 0; offset < 6; offset++) {
        snow2_index = start - offset;
        if (snow2_index < 0)
        snow2_index = snow2_index + 6;
        if (snow1[offset] != snow2[snow2_index])
          return 0;
    }
    return 1;
}

// check identical
int are_identical(int snow1[], int snow2[])
{
  int start;
  for (start = 0; start < 6; start++) {
    if (identical_right(snow1, snow2, start))
        return 1;
    if (identical_left(snow1, snow2, start))
        return 1;
  }
  return 0;
}

// identify snowflakes
void identify_identical(int snowflakes[][6], int n)
{
    int i, j;
    for (i = 0; i < n; i++) {
        for (j = i+1; j < n; j++) {
            if (are_identical(snowflakes[i], snowflakes[j])) {
             printf("Twin snowflakes found.\n");
             return;
            }
        }
    }
    printf("No integers are alike.\n");
}

