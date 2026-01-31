#include <stdio.h>
#include <stdlib.h>

void show_addresses(); //function prototype

int global_var = 100; //global variable

void show_addresses() { //funtion for displaying addresses
    
    static int static_var = 200; //static local variable
    int local_var = 300;  //local variable
    int *heap_var = malloc(sizeof(int));  //dynamically allocated variable

    if (heap_var == NULL) { // incase malloc fails 
        fprintf(stderr, "Memory allocation failed\n");
        return;
    }
    *heap_var = 400; //assign value to malloc'd block
    
    printf("Global variable address:       %p\n", (void*)&global_var);
    printf("Static local variable address: %p\n", (void*)&static_var);
    printf("Local variable address:        %p\n", (void*)&local_var);
    printf("Malloc'd block address:        %p\n", (void*)heap_var);
    
    free(heap_var); //free allocated memory
}

int main() {
    show_addresses();
    return 0;
}