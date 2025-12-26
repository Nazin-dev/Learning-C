#include <stdio.h>

void board();
void drawBoard();

typedef struct
{
    int position;
    char Type;
} chessPiece;


int main() {

    drawBoard();

    return 0;
}

void board() {
        printf("  -----------------\n");
        printf("8 |♖|♘|♗|♔|♕|♗|♘|♖|\n");
        printf("  -----------------\n");
        printf("7 |♙|♙|♙|♙|♙|♙|♙|♙|\n");
        printf("  -----------------\n");
        printf("6 | | | | | | | | |\n");
        printf("  -----------------\n");
        printf("5 | | | | | | | | |\n");
        printf("  -----------------\n");
        printf("4 | | | | | | | | |\n");
        printf("  -----------------\n");
        printf("3 | | | | | | | | |\n");
        printf("  -----------------\n");
        printf("2 |♟|♟|♟|♟|♟|♟|♟|♟|\n");
        printf("  -----------------\n");
        printf("1 |♜|♞|♝|♚|♛|♝|♞|♜|\n");
        printf("  -----------------\n");
        printf("   a b c d e f g h\n");
}

void drawBoard() {
    for (int l = 8; l >= 0; l--)
    {
        printf("  -----------------\n");
        printf("%d", l);
        for (int c = 0; c <= 8; c++) {
            printf(" |");
        }
        printf("\n");
    }
    printf("  -----------------\n");
    printf("   a b c d e f g h\n");
}