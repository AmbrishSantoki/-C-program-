#include <stdio.h>
#include "tree.h"

int main() {
    Node *root = NULL;

    // Insert nodes into the tree
    int numNodes;
    printf("Enter the number of nodes to insert: ");
    scanf("%d", &numNodes);

    for (int i = 0; i < numNodes; ++i) {
        printf("Inserting Node %d:\n", i + 1);
        insertNode(&root);
    }

    // Calculate and print tree height
    printf("Tree Height: %d\n", treeHeight(root));

    // Free the tree
    freeTree(root);

    return 0;
}
