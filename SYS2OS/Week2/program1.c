#include <stdio.h>
int main() {
   int x = 9;
   int y = 32;
   int z = 3;
   x = x - y;
   z = z * x;
   z = z - y;
   printf("%d\n", z); // should print -101
}



