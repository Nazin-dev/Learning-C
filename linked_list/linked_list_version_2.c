#include <stdio.h>
#include <stdlib.h>

typedef struct node 
{
    int data;
    struct node *next;
} node_t;

typedef struct simply_linked_list {
    size_t length;
    node_t *head;
} simply_linked_list;
