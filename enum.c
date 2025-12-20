#include <stdio.h>

enum Level {
    LOW = 25,
    MEDIUM = 50,
    HEIG = 75
};

typedef enum {
    MON, TUE, WED, THU, FRI, SAT, SUN
} Day;

int main() {
    enum Level var = LOW;
    Day today = SAT;

    printf("%d ", var);

    return 0;
}