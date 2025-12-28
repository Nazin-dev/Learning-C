#ifndef FS_H
#define FS_H

#define NAME_SIZE 50

typedef enum {
    FILE_NODE,
    DIR_NODE,
} NodeType;

typedef struct Node {
    char name[50];
    NodeType type;

    struct Node *parent;
    struct Node *child;
    struct Node *sibling;
} Node;

Node* create_node(const char *name, NodeType type);
void add_child(Node *parent, Node *child);
Node* find_child(Node *parent, const char *name);
void list_dir(Node *dir);
void print_path(Node *current);

#endif

