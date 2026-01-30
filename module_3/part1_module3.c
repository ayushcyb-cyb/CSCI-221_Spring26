
// module_3/part1_module3.c
// Write a program that:
// Declares int x = 10; and int *p = &x;
// Prints x, p (as an address), and *p.
// Uses *p = 20; and shows that x changed.

#include <stdio.h>

int main(void) {

    int x = 10;
    int *p = &x;

    printf("Value of x: %d\n", x);
    printf("Address of x (p): %p\n", p);
    printf("Value pointed to by p (*p): %d\n", *p);

    *p = 20;  // Changing the value of x through the pointer p

    printf("After changing *p to 20:\n");
    printf("New value of x: %d\n", x);

}