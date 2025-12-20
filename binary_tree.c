#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int value;
    struct node *left, *right; 
} Node;

typedef struct {
    Node *source;
} TreeB;

void insertLeft(Node *node, int value);
void insertRight(Node *node, int value);

void insertLeft(Node *node, int value) {
    if (node->left == NULL) {
        Node *new = (Node*) malloc(sizeof(Node));
        new->value = value;
        new->left = NULL;
        new->right = NULL;
        node->left = new;
    } else {
        if (value < node->left->value) {
            insertLeft(node->left, value);
        } else {
            insertRight(node->left, value);
        }
    }
}

void insertRight(Node *node, int value) {
    if (node->right == NULL) {
        Node *new = (Node*) malloc(sizeof(Node));
        new->value = value;
        new->left = NULL;
        new->right = NULL;
        node->right = new;
    } else {
        if (value > node->right->value) {
            insertRight(node->right, value);
        } else {
            insertLeft(node->right, value);
        }
    }
}

void insert(TreeB *tree, int value) {
    if (tree->source == NULL) {
        Node *new = (Node*) malloc(sizeof(Node));
        new->value = value;
        new->left = NULL;
        new->right = NULL;
        tree->source = new;
    } else {
        if (value < tree->source->value) {
            insertLeft(tree->source, value);
        } else {
            insertRight(tree->source, value);
        }
    }
}

void print(Node *source) {
    if(source != NULL) {
        print(source->left);
        printf("%d ", source->value);
        print(source->right);
    }
}

int main() {
    int op, value;
    TreeB tree;
    tree.source = NULL;


    do {
        printf("\n0 - exit\n1 - insert\n2 - print\n");
        scanf("%d", &op);

        switch (op) {

        case 0:
            printf("\nLeaving...");
            break;
        case 1:
            printf("Enter a value: ");
            scanf("%d", &value);
            insert(&tree, value);
            break;
        case 2:
            printf("\nPrint of binary tree:\n");
            print(tree.source);
            break;
        default:
            printf("\nOption invalid!");
        }
    } while (op != 0);

    return 0;
} 