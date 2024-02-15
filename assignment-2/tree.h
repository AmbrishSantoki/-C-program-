#ifndef TREE_H
#define TREE_H

#define MAX_PROJ_NAME 32

typedef struct myNode {
    int id;
    char project[MAX_PROJ_NAME];
    struct myNode *left;
    struct myNode *right;
} Node;

Node* createNode();
void insertNode(Node **root);
void freeTree(Node *root);
int treeHeight(Node *root);

#endif // TREE_H
