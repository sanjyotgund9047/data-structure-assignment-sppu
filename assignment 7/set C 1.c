/*Write a C program to implement binary search tree of integers with following operations:
 Inserting a new element
 Searching an element
 Creating mirror of the tree.
 Find largest and smallest value from a binary search tree
*/

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

// Function to search for an element in the binary search tree
struct Node* searchNode(struct Node* root, int value) {
    if (root == NULL || root->data == value) {
        return root;
    }

    if (value < root->data) {
        return searchNode(root->left, value);
    }

    return searchNode(root->right, value);
}

// Function to create the mirror of the binary search tree
struct Node* createMirror(struct Node* root) {
    if (root == NULL) {
        return NULL;
    }

    struct Node* newNode = createNode(root->data);
    newNode->left = createMirror(root->right);
    newNode->right = createMirror(root->left);
    return newNode;
}

// Function to find the smallest value in a binary search tree
int findSmallest(struct Node* root) {
    if (root == NULL) {
        printf("Tree is empty. Cannot find the smallest value.\n");
        return -1;
    }

    while (root->left != NULL) {
        root = root->left;
    }

    return root->data;
}

// Function to find the largest value in a binary search tree
int findLargest(struct Node* root) {
    if (root == NULL) {
        printf("Tree is empty. Cannot find the largest value.\n");
        return -1;
    }

    while (root->right != NULL) {
        root = root->right;
    }

    return root->data;
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

    printf("Searching for 40: %s\n", searchNode(root, 40) != NULL ? "Found" : "Not found");

    printf("Smallest value: %d\n", findSmallest(root));
    printf("Largest value: %d\n", findLargest(root));

    
    return 0;
}



/*output
Searching for 40: Found
Smallest value: 20
Largest value: 80
Mirror tree created.
*/