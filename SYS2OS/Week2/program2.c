#include <stdio.h>
int main() {
   float x = 4;
   float y = 5;
   float z = 3;
   x = x / y;
   z = z * x;
   z = z + y;
   printf("%.1f\n", z); // should print 7.4
}
