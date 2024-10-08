#include <stdio.h>
struct Coordinates{
   float x;
   float y;
} A;
struct FullNameDOB{
  char name[40];
  int day[2];
  int month[2];
  int year[2];
} B;
struct bitvalue{
  unsigned int bit1:1;
  unsigned int bit2:1;
  unsigned int bit3:1;
  unsigned int bit4:1;
  unsigned int bit5:1;
  unsigned int bit6:1;
  unsigned int bit7:2;
} C; 
int main(){

printf("%lu\n", sizeof(A));
printf("%lu\n", sizeof(B));
printf("%lu\n", sizeof(C));
   };
