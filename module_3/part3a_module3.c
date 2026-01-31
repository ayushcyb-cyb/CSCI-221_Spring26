#include <stdio.h>
#include <stdlib.h>

int *make_range(int start, int end);
int *grow_array(int *arr, size_t old_n, size_t new_n);

int *make_range(int start, int end){
    if (end < start){  // handling invalid range
        return NULL;
    }
    
    size_t size = end - start + 1;
    int *arr = malloc(size * sizeof(int));
    
    if (arr == NULL){
        return NULL;  // incase allocation fails
    }
    
    for (size_t i = 0; i < size; i++){ // Initializing array
        arr[i] = start + i;
    }
    
    return arr;
}

int *grow_array(int *arr, size_t old_n, size_t new_n){
   
    int *temp = realloc(arr, new_n * sizeof(int)); // resizing the array and handle failure    
    
    if (temp == NULL){
        free(arr);  // Free original array if realloc fails
        return NULL;
    }
    
    // Success! Initialize new elements if growing
    if (new_n > old_n){
        for (size_t i = old_n; i < new_n; i++){
            temp[i] = 0;
        }
    }
    
    return temp;  // Return new pointer
    
}

int main(){
    int start = 5;
    int end = 10;
    
    int *range = make_range(start, end);
    
    if (range == NULL){
        printf("Invalid range or memory allocation failed.\n");
        return 1;
    }
    
    size_t size = end - start + 1;
    printf("Array from %d to %d:\n", start, end);
    for (size_t i = 0; i < size; i++){
        printf("%d ", range[i]);
    }
    printf("\n");

    // Grow the array
    size_t new_size = 15;
    int *grown_array = grow_array(range, size, new_size);
    
    if (grown_array == NULL){
        printf("Memory reallocation failed.\n");
        free(range);  // Free original array before exiting
        return 1;
    }
    
    range = grown_array;  // Update pointer
    
    printf("Grown array to size %zu:\n", new_size);
    for (size_t i = 0; i < new_size; i++){
        printf("%d ", range[i]);
    }
    printf("\n");

    free(range);  // Free allocated memory
    return 0;
}