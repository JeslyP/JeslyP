#include <stdio.h>
#include <string.h>
int main() {
   char sentence1[25] = "It's a nice day today. ";
   char sentence2[25] = "It really is.";
   char firstbit[30];
   
   // TODO: use two string manipulation functions to make firstbit 
   // sentence1 followed by as much of sentence2 as will fit.
   
   printf("%s\n", firstbit); // should print "It's a nice day today. It rea" - might print more, might not.
}
