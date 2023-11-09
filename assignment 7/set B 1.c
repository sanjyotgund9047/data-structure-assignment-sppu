/*. Write a C program to implement binary search tree of integers with following operations:
 Add a function to insert a new element in the tree
 Add a function to count non-leaf nodes.
 Add a function to count leaf nodes.
 Add a function to count total number of nodes*/

#include <stdio.h>
#include <stdlib.h>

// Define the structure for a binary tree node
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Function to create a new binary tree node
struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed.\n");
        exit(1);
    }
    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Function to insert a new element into the binary search tree
struct Node* insertNode(struct Node* root, int value) {
    if (root == NULL) {
        return createNode(value);
    }

    if (value < root->data) {
        root->left = insertNode(root->left, value);
    } else if (value > root->data) {
        root->right = insertNode(root->right, value);
    }

    return root;
}

// Function to count non-leaf nodes
int countNonLeafNodes(struct Node* root) {
    if (root == NULL || (root->left == NULL && root->right == NULL)) {
        return 0;
    }
    return 1 + countNonLeafNodes(root->left) + countNonLeafNodes(root->right);
}

// Function to count leaf nodes
int countLeafNodes(struct Node* root) {
    if (root == NULL) {
        return 0;
    }
    if (root->left == NULL && root->right == NULL) {
        return 1;
    }
    return countLeafNodes(root->left) + countLeafNodes(root->right);
}

// Function to count the total number of nodes
int countTotalNodes(struct Node* root) {
    if (root == NULL) {
        return 0;
    }
    return 1 + countTotalNodes(root->left) + countTotalNodes(root->right);
}

int main() {
    struct Node* root = NULL;

    // Insert nodes into the binary search tree
    root = insertNode(root, 50);
    root = insertNode(root, 30);
    root = insertNode(root, 70);
    root = insertNode(root, 20);
    root = insertNode(root, 40);
    root = insertNode(root, 60);
    root = insertNode(root, 80);

    printf("Non-leaf nodes: %d\n", countNonLeafNodes(root));
    printf("Leaf nodes: %d\n", countLeafNodes(root));
    printf("Total nodes: %d\n", countTotalNodes(root));

    return 0;
}

/*Output
Non-leaf nodes: 3
Leaf nodes: 4
Total nodes: 7
*/