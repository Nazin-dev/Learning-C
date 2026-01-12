#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


// representação do TAD lista duplamente encadeada
typedef struct node {
    int *value;
    struct node *next;
    struct node *prev;
} node_t;

typedef struct list {
    node_t *head;
    node_t *tail;
    size_t length;
} list_t;


node_t* node_create(int* value); // ok
void node_print(node_t* self); // ok
void node_delete(node_t *self); //

list_t* list_create(); // ok
void list_print(list_t *self); // ok
size_t list_length(list_t *self); 
void list_delete(list_t *self); 
void list_push(list_t *self, int* value); //
int* list_pop(list_t *self); //



node_t* node_create(int* value) {
    node_t *new_node = (node_t*) malloc(sizeof(node_t));

    if (new_node == NULL) {
        perror("Memory Error:");
        exit(EXIT_FAILURE);
    }

    new_node->next = NULL;
    new_node->prev = NULL;
    new_node->value = value;
    return new_node;
}

void node_print(node_t *self) {
    printf("Node{\n\tNext: %p\n\tPrev: %p\n\tValue: ", self->next, self->prev);
    printf("%d", *(self->value));
    printf("\n}\n");
}


list_t* list_create() {
    list_t *new_list =  (list_t*) malloc(sizeof(list_t));

    if (new_list == NULL) {
        perror("Memory Error:");
        exit(EXIT_FAILURE);
    }

    new_list->head = NULL;
    new_list->tail = NULL;
    new_list->length = 0;
    return new_list;
}

void list_print(list_t *self) {
    printf("List{\n\tLength: %zu\n\tData: [", self->length);
    node_t *current = self->head;
    while (current != NULL) {
        printf("%d", *(current->value));
        if (current->next != NULL) {
            printf(" -> ");
        }
        current = current->next;
    }
    printf("]");
    printf("\n}\n");
}


void list_push(list_t *self, int *value) {
    node_t *new_node = node_create(value); 

    if (self->length == 0) {
        self->head = new_node;
        self->tail = new_node;
    } 
    
    else if (self->length > 0) {
        self->tail->next = new_node;
        new_node->prev = self->tail;
        self->tail = new_node;
    }

    self->length += 1;
}


int main() {
    int value, value2;
    value = 16;
    value2 = 5;

    list_t *linked_list = list_create();
    list_push(linked_list, &value);
    list_push(linked_list, &value2);
    list_print(linked_list);
    


    return 0;
}