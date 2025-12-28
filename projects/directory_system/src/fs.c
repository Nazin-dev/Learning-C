#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/fs.h"

Node* create_node(const char *name, NodeType type) {
    Node *node = (Node*) malloc(sizeof(Node));
    if (!node) {
        printf("Erro de alocação de memória\n");
        exit(1);
    }

    strncpy(node->name, name, NAME_SIZE);
    node->type = type;
    node->parent = NULL;
    node->child = NULL;
    node->sibling = NULL;

    return node;
}

void add_child(Node *parent, Node *child) {
    child->parent = parent;

    if (!parent->child) {
        parent->child = child;
    } else {
        Node *temp = parent->child;
        while (temp->sibling) {
            temp = temp->sibling;
        }
        temp->sibling = child;
    }
}

Node* find_child(Node *parent, const char *name) {
    Node *temp = parent->child;
    while (temp) {
        if (strcmp(temp->name, name) == 0) {
            return temp;
        }
        temp = temp->sibling;
    }
    return NULL;
}

void list_dir(Node *dir) {
    Node *temp = dir->child;

    while (temp) {
        if (temp->type == DIR_NODE) {
            printf("[DIR] %s\n", temp->name);
        } else {
            printf("[FILE] %s\n", temp->name);
        }

        temp = temp->sibling;
    }
}

void print_path(Node *current) {
    if (current->parent) {
        print_path(current->parent);
        if (strcmp(current->name, "/") != 0) {
            printf("/%s", current->name);
        } else {
            printf("/");
        }
    } 
}