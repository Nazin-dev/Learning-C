#include <stdio.h>
#include <stdlib.h>

// Como inserir no inicio da lista?

typedef struct no {
    int  value; 
    struct no *next;
} No;

//  procedimento para inserir no inicio

void insert_start(No **list, int num) {
    No *new = malloc(sizeof(No));

    if (new) {
        new->value = num;
        new->next = *list;
        *list = new; 

    } else {
        printf("Erro ao alocar memoria!\n");
    }
}

// procedimento para inserir no fim

void insert_end(No **list, int num) {
    No *aux, *new = malloc(sizeof(No));

    if (new) {
        new->value = num;
        new->next = NULL;

        if (*list == NULL) {
            *list = new;
        } else {
            aux = *list;
            while (aux->next)
            {
                aux = aux->next;

            }
            aux->next = new;
            
        }
    } else {
        printf("Erro ao alocar memoria!\n");
    }
}

// procedimento para inserir no meio

void insert_middle(No **list, int num, int prev) {
    No *aux, *new = malloc(sizeof(No));

    if (new) {
        new->value = num;
        if (*list == NULL) {
            new->next = NULL;
            *list = new;
        } else {
            aux = *list;
            while (aux->value != prev && aux->next)
            {
                aux = aux->next;
            } 
            new->next = aux->next;
            aux->next = new;
            
        }
    } else {
        printf("Erro ao alocar memmoria!\n");
    }
}

void print(No *no) {
    printf("\n\tLista: ");
    while (no)
    {
        printf("%d ", no->value);
        no = no->next;
    }
    printf("\n\n");
    
}

int main() {

    int option, value, prev;
    No *list = NULL;

    do {
        printf("\n\t0 - Exit\n\t1 - Insert Start\n\t2 - Insert End\n\t3 - Insert Middle\n\t4 - Print List\n");
        scanf("%d", &option);

        switch (option)
        {
        case 1:
            printf("Digite um valor: ");
            scanf("%d", &value);
            insert_start(&list, value);
            break;
        case 2:
            printf("Digite um valor: ");
            scanf("%d", &value);
            insert_end(&list, value);
            break;
        case 3:
            printf("Digite um valor e valor de referencia: ");
            scanf("%d %d", &value, &prev);
            insert_middle(&list, value, prev);
            break;
        case 4:
            print(list);
            break;
        
        default:
            if(option != 0) {
                printf("Option Invalid!\n");
            }
            break;
        }

    } while (option != 0);


    return 0;
}