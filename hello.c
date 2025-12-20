#include <stdio.h>
#include <stdbool.h>

int main() {

    int matriz[9][3] = {{2, 3, 5}, {6, 8, 1}, {6, 8, 1}, {2, 3, 5}, {6, 8, 1}, {6, 8, 1}, {2, 3, 5}, {6, 8, 1}, {6, 8, 1}};
    int linhas, colunas;

    linhas = sizeof(matriz) / sizeof(matriz[0]);
    colunas = sizeof(matriz[0]) / sizeof(matriz[0][0]);
    for (int i = 0; i < linhas; i++) {
        printf("|");
        for (int e = 0; e < colunas; e++) {
            printf("___");
            printf("%d ", matriz[i][e]);
        }
        printf("|\n");
    }
    return 0;
}