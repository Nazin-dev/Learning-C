#include <stdio.h>
#include <stdlib.h>

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

node_t* create_node(int *value);
void node_print(node_t *self);

list_t* list_create();
void list_print(list_t *self);
void list_push(list_t *self, int *value);
int* list_pop(list_t *self);


node_t* create_node(int *value) {
    node_t *new_node = (node_t*) malloc(sizeof(node_t*));

    if (new_node == NULL) {
        perror("Memory Error:");
        exit(EXIT_FAILURE);
    }

    new_node->next = NULL;
    new_node->prev = NULL;
    new_node->value = value;

    return new_node;
}

list_t* list_create() {
    list_t *new_list = (list_t*)  malloc(sizeof(list_t));

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
    while (current != NULL)
    {
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
    node_t *new_node = create_node(value);

    if (self->length == 0) {
        self->head = new_node;
        self->tail = new_node;
        self->length += 1;
    } else if (self->length > 0) {
        self->tail->next = new_node;
        new_node->prev = self->tail;
        self->tail = new_node;
        self->length += 1;
    }


}

void node_print(node_t *self) {
    printf("Node{\n\tNext: %p\n\tPrev: %p\n\tValue: %d", self->next, self->prev, *(self->value));
    printf("\n}\n");
}

int* list_pop(list_t *self) {
    if (self->length == 0) {
        return NULL;
    }
    if (self->length == 1) {
        self->head = NULL;
        self->tail = NULL;
    }

    node_t *node = self->tail;
    self->tail = node->prev;
    self->tail->next = NULL;
    int *value = node->value;
    self->length -= 1;

    free(node);

    return value;
}


int main() {
    int v1, v2, v3, v4;
    v1 = 16;
    v2 = 14;
    v3 = 18;
    v4 = 21;
    list_t *linked_list = list_create();
    node_t *no1 = create_node(&v1);
    node_print(no1);

    list_push(linked_list, &v1);
    list_push(linked_list, &v2);
    list_push(linked_list, &v3);
    list_push(linked_list, &v4);
    list_print(linked_list);

    printf("\n-->POP[%d]\n\n", *(list_pop(linked_list)));

    list_print(linked_list);

    return 0;
}