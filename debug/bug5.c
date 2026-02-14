//debugged bug5.c


#include <stdlib.h>
int main() {
int *p = malloc(sizeof(int) * 5);
for (int i = 0; i < 5; i++) {
p[i] = i * 2;
}
free(p);
return 0;
}
