//Write a function reverse_inplace(char *s) that reverses a mutable C string in place;
// show it working on char s[] = "systems";.

#include<stdio.h>

char reverse_inplace(char *s);

char reverse_inplace(char *s) {

    char *start = s;      
    char *end = s;        

    while (*end != '\0') {
        end++;
    }
    end--;                

    
    while (start < end) {
        char temp = *start;
        *start = *end;
        *end = temp;

        start++;          
        end--;           
    }
}


int main(){

    char s[] = "systems";

    printf("Original string: %s\n\n", s);

    reverse_inplace(s);

    printf("Reversed string: %s\n", s);

    return 0;
}