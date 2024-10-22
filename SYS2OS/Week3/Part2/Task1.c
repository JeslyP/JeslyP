#include <stdio.h>

int main(){
  int answer_1 = 3 * 4 << 2;
  int answer_2 = ~ (4 - 2); 
  int answer_3 = 4 && 2; 
  int answer_4 = 4 & 2; 
  int answer_5 = 9 || 12 << 32; 

  printf("answer_1 %d \n",answer_1);
  printf("answer_2 %d\n",answer_2);
  printf("answer_3 %d\n",answer_3);
  printf("answer_4 %d\n",answer_4);
  printf("answer_5 %d\n",answer_5);

}
