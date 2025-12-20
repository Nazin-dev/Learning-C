#include <stdio.h>

typedef struct 
{
    int dia;
    int mes;
    int ano;
} Age;

typedef struct
{
    char nome[30];
    int identidade;
    Age idade;
} Dono;


typedef struct
{
    char placa[30];
    char modelo[40];
    int peso;
    Dono dono;
} Cars;



int main() {
    Age age = {16, 8, 2006};
    Dono dono = {"Nailton", 8973627, age};
    Cars sedan = {"RSH2025", "Preto", 1000, dono};
    Cars* prt = &sedan;

    printf("%s - %s - %d - %d", prt->placa, prt->modelo, prt->peso, prt->dono.idade.ano);
    return 0;
}