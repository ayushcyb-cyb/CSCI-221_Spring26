#include <stdio.h>
#include <stddef.h>

void clamp(int *x, int lo, int hi) {
    if (*x < lo) {
        *x = lo;
    } else if (*x > hi) {
        *x = hi;
    }
}

int square(int x) {
    return x * x;
}

int negate(int x) {
    return -x;
}

int apply(int *a, size_t n, int (*op)(int)) {
    size_t i;
    for (i = 0; i < n; i++) {
        a[i] = op(a[i]);
    }
    return 0;
}

int main() {
    int val;
    int arr[5] = {1, 2, 3, 4, 5};
    size_t i;
    

    val = 15;
    printf("Before clamp: %d\n", val);
    clamp(&val, 0, 10);
    printf("After clamp(0, 10): %d\n\n", val);
    
    val = -5;
    printf("Before clamp: %d\n", val);
    clamp(&val, 0, 10);
    printf("After clamp(0, 10): %d\n\n", val);
    
    val = 5;
    printf("Before clamp: %d\n", val);
    clamp(&val, 0, 10);
    printf("After clamp(0, 10): %d\n\n", val);
    
    printf("Original array: ");
    for (i = 0; i < 5; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    
    apply(arr, 5, square);
    printf("After square:   ");
    for (i = 0; i < 5; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    
    apply(arr, 5, negate);
    printf("After negate:   ");
    for (i = 0; i < 5; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    
    return 0;
}