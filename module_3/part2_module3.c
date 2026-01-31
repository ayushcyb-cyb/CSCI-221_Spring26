// Implement a function sum_ints(const int *a, size_t n) that returns the sum using pointer iteration (no indexing).

#include<stdio.h>

int sum_ints(const int *a, size_t n); //prototyping function

int sum_ints(const int *a, size_t n){

    int sum = 0;
    const int *end = a + n;

    while (a < end){ //iteration using while loop
        sum += *a;
        a++;
    }
    return sum;

    
}

int main(){

    int a[10]={1,2,3,4,5,6,7,8,9,10};
    size_t n=10;

    int sum = sum_ints(a, n); //calling func.
    printf("Sum of the ints in array: %d\n", sum);

    return 0;
}