/*
 * Determines the number of people in each line
 * that each of new people join.
 * For example: we have 3 lines and each new people join the shortest line.
 * line1: contains 3 peoples.
 * line2: contains 2 peoples.
 * line3: contains 5 peoples.
 * n is the number of line of peoples in each lines.
 * m is the number of new peoples joining.
 */

#include <iostream>
using namespace std;

// Determines the shortest line by index
int shortest_line_index(int lines[], int n) {
 int j;
 int shortest = 0;
 for (j = 1; j < n; j++) {
    if (lines[j] < lines[shortest])
	    shortest = j;
 }
 return shortest;
}

// Add to the shortest line by one new joined people
void solve (int lines[], int n, int m) {
 int i, shortest;
 for (i = 0; i < m; i++) {
  shortest = shortest_line_index(lines, n);
  //printf("%d\n", lines[shortest]);
  cout << lines[shortest];
  lines[shortest]++;
 }
}

#define MAX_LINES 100

int main(void) {
 int lines[MAX_LINES];
 int n, m, i;
 //scanf("%d%d", &n, &m);
 cin >> n >> m;
 for (i = 0; i < n; i++) {
 //scanf("%d", &lines[i]);
 cin >> lines[i];
   solve(lines, n, m);
 }

 return 0;
}


