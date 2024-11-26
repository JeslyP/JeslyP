#include <stdio.h>
int main(){
  char word[50];
  printf("Read and print the character: \n");
  scanf("%s", word);
    
  printf("here is your word %s \n", word);

  int num1, num2, result1;
  printf("what is the 1st number: \n");
  scanf("%d", &num1);
  printf("what is the 2nd number: \n");
  scanf("%d", &num2);
  result1 = (num1 - num2);
  printf("the answer is %d \n", result1);

  int num3; 
  float num4, result2;
  printf("what is the 1st number: \n");
  scanf("%d", &num1);
  printf("what is the 2nd number: \n");
  scanf("%f", &num4);
  result2 = num3 * num4;
  printf("the answer is %f", result2);



}

