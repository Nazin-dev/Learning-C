#include <stdio.h>

void add() { printf("Add\n"); }
void sub() { printf("Sub\n"); }
void mult() { printf("mult\n"); }

int main() {
    void (*functions[3])(void) = {add, sub, mult};
    for (int i = 0; i < 3; i++) {
        functions[i]();
    }
    return 0;
}