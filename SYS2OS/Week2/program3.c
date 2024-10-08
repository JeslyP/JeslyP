#include <stdio.h>
int main() {
   long int x = 256;
   long int y = 6000;
   long int z = 100;
   x = x * y;
   z = z * x;
   z = z * y;
   printf("%ld\n", z); // should print 921600000000
}
