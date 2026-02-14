//debugged bug6.c


#include <stdlib.h> 
#include <stdio.h> 
int main() { 
int *p = malloc(sizeof(int)); 
*p = 10; 
printf("%d\n", *p); 
free(p);
p = NULL; // Set pointer to NULL after freeing memory
return 0; 
} 
