#include <stdio.h>
#include <stdlib.h>

typedef struct array {
    int *data;
    size_t length;
    size_t capacity;
} array_t;


array_t* create_array(size_t capacity);
size_t array_length(array_t *self); 
size_t array_capacity(array_t *self);
void array_push(array_t *self, int data);

void array_print(array_t *self);

array_t* create_array(size_t capacity) {
    int *data = (int*) calloc(capacity, sizeof(int));
    if (data == NULL) {
        perror("calloc falhou");
        exit(EXIT_FAILURE);
    }

    array_t *array = (array_t*) malloc(sizeof(array_t));

    if (array == NULL) {
        perror("malloc falhou");
        exit(EXIT_FAILURE);
    }

    array->data = data;
    array->length = 0;
    array->capacity = capacity;

    return array;
}

size_t array_length(array_t *self) {
    return self->length;
}

size_t array_capacity(array_t *self) {
    return self->capacity;
}

void array_push(array_t *self, int item) {
    if (self->length == self->capacity) {
        
    }

    self->data[self->length] = item;
    self->length++;
}