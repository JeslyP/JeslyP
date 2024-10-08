#include <stdio.h>
/* insert addmult prototype */
 
int addmult(int x, int y, int z){
   return (x + y) * z;
}
 
int main(){
  int x = 0;
  int y = 0;
  
  y = addmult(3, 4, 5);
  printf("Addmult(3,4,5) = %d\n", y);
  
  printf("These are numbers less than 10\n");
  for (/* insert for loop */){
      printf("%d\n", x); // will print x, you can change this variable if you want
  }
  
  x = 1;
  y = 0;
  printf("These are square numbers less than 100\n");
  while (/* insert loop condition */){
    /* insert code before or after this printf */
      printf("%d\n", y);
  }
  
  printf("This loop runs until it gets to 49, then it prints and stops\n");
  
  x = 30;
  do {
     if (/* condition /*) {
        printf("%d\n", x);
        /* something to stop the loop */
     }
     x = x + 1;
  } while (1); // try not to change this
  
  x = 1;
  
  printf("This should print Yes if x == 2, otherwise it should print No\n");
  
  switch (/* condition */){
     /* case statements */
  };
}
