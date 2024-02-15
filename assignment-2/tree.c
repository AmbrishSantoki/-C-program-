#include <stdio.h>
#include <stdlib.h>
#include "tree.h"

Node* createNode() {
    Node *newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }

    printf("Enter ID: ");
    scanf("%d", &newNode->id);

    printf("Enter project name: ");
    scanf("%s", newNode->project);

    newNode->left = newNode->right = NULL;

    return newNode;
}

void insertNode(Node **root) {
    if (*root == NULL) {
        *root = createNode();
    } else {
        printf("Go left (l) or right (r) from %d: ", (*root)->id);
        char direction;
        scanf(" %c", &direction);

        if (direction == 'l') {
            insertNode(&((*root)->left));
        } else if (direction == 'r') {
            insertNode(&((*root)->right));
        } else {
            printf("Invalid direction\n");
        }
    }
}

void freeTree(Node *root) {
    if (root != NULL) {
        freeTree(root->left);
        freeTree(root->right);
        free(root);
    }
}

int treeHeight(Node *root) {
    if (root == NULL) {
        return 0;
    } else {
        int leftHeight = treeHeight(root->left);
        int rightHeight = treeHeight(root->right);

        return 1 + ((leftHeight > rightHeight) ? leftHeight : rightHeight);
    }
}
