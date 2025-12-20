#include <stdio.h>

int factorial(int n);

int main() {
    int (*fct)(int) = factorial;

    int result = fct(5);

    printf("%d ", result);

    return 0;
}

int factorial(int n) {
    if (n > 1) {
        return n * factorial(n - 1);
    } else {
        return 1;
    }
}