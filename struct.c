#include <stdio.h>

struct myStruct
{
    int myNum;
    char myLetter;
};


int main() {
    struct myStruct s1;

    s1.myLetter = 'a';
    s1.myNum = 16;

    printf("%d - %c", s1.myNum, s1.myLetter);
    return 0;
}