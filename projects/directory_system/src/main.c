#include <stdio.h>
#include <string.h>
#include "../include/fs.h"

int main() {
    Node *root = create_node("/", DIR_NODE);
    Node *current = root;

    char command[100];
    char arg[50];

    while (1) {
        print_path(current);
        printf("> ");

        fgets(command, sizeof(command), stdin);
        command[strcspn(command, "\n")] = 0;

        if (strcmp(command, "ls") == 0) {
            list_dir(current);
        } 
        else if (sscanf(command, "mkdir %s", arg) == 1) {
            if (find_child(current, arg)) {
                printf("Diretório já existente\n");
            } else {
                add_child(current, create_node(arg, DIR_NODE));
            }
        }
        else if (sscanf(command, "touch %s", arg) == 1) {
            if (find_child(current, arg)) {
                printf("Arquivo já existente\n");
            } else {
                add_child(current, create_node(arg, FILE_NODE));
            }
        }
        else if (sscanf(command, "cd %s", arg) == 1) {
            if (strcmp(arg, "..") == 0) {
                if (current->parent) 
                    current = current->parent;
            } else {
                Node *dir = find_child(current, arg);
                if (dir && dir->type == DIR_NODE)
                    current = dir;
                else    
                    printf("Diretório não encontrado\n");
            }
        }
        else if (strcmp(command, "pwd") == 0) {
            print_path(current);
            printf("\n");
        }
        else if (strcmp(command, "exit") == 0) {
            break;
        }
        else {
            printf("Comando desconhecido\n");
        }
    }
    return 0;
}