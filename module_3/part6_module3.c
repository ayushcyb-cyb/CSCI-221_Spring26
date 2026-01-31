#include <stdio.h>
#include <stdlib.h>

int main() {


    int *p;   // contains garbage as its uninitialized
    printf("Uninitialized p = %p (garbage)\n", p);
    // Using p now would be undefined behavior

        
    // dangling pointer example
    int *q = NULL;

    q = malloc(sizeof(int));
    if (!q) return 1; //malloc check

    *q = 34;
    printf("q initially points to %p with value %d\n", q, *q);

    free(q);          // memory freed
    // q still holds the old address which may cause dangling pointer
    printf("After free, q = %p (dangling pointer)\n", q);

    // Using q now would be undefined behavior
    //like; *q = 50;


    printf("\nSAFE VERSION (avoiding both pitfalls)\n");

    //initialized pointers
    int *sp = NULL;
    printf("Initialized sp = %p\n", sp);

    //Correct malloc usage and avoid dangling pointer
    int *sq = malloc(sizeof(int));
    if (!sq) return 1;

    *sq = 34;   
    printf("sq points to %p with value %d\n", sq, *sq);

    free(sq);   // freed correctly
    sq = NULL;  // avoid dangling pointer by NULL
    printf("After free, sq = %p (NULL)\n", sq);

    return 0;
}



// int *p;             // uninitialized pointer containing garbage
// printf("%p\n", p);   // prints random address (unsafe)
// *p = 10;         // undefined behavior (dereferencing garbage)
// // safe usage requires initialization


// int *p = NULL;        // initialize pointer to a known safe value with no garbage

// p = malloc(sizeof(int));   // assign valid memory before use
// if (p != NULL) { //it will check if malloc was successful
//     *p = 10;               
// }

// free(p);                  // release memory
// p = NULL;                 // prevent dangling pointer

//--------------------------------------------------------------------

// int *q = malloc(sizeof(int));
// *q = 34;

// free(q);      // memory freed
// printf("%p\n", q);   // q still holds old address and gives dangling pointer

// *q = 50;      // undefinied behavior (dereferencing freed memory)



int *q = malloc(sizeof(int));
if (q != NULL) {
    *q = 34;      // safe use
}

free(q);          // free the memory
q = NULL;         // avoid dangling pointer
// now q is NULL and safe to use