#include <stdio.h>
#include <stdlib.h>

void reallocate();

int main() {
    int *ptr;
    ptr = calloc(4, sizeof(*ptr));

    *ptr = 2;
    ptr[1]  = 4;
    ptr[2]  = 6;
    
    printf("%p\n", ptr);
    printf("%d %d %d\n", ptr[1], ptr[2], ptr[3]);

    reallocate();
    return 0;
}

void reallocate() {
    int *ptr1, *ptr2, size;

    size = 4 * sizeof(*ptr1);
    ptr1 = malloc(size);

    printf("%d bytes allocated at address %p \n", size, ptr1);

    size = 6 * sizeof(*ptr1);
    ptr2 = realloc(ptr1, size);

    printf("%d bytes reallocated at address %p \n", size, ptr2);
}