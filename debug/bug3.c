//debugged bug3.c

#include <stdio.h>
int main() {

int x=20;

int *p = &x;
*p = 10;
//printf("%d",x);
return 0;
}
