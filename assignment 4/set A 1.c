/*Write a C program to implement a Singly linked list with Create and Display operation*/

#include <stdio.h>
#include <stdlib.h>

// Define the structure for a node in the linked list
struct Node {
    int data;
    struct Node* next;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed.\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to display the linked list
void displayList(struct Node* head) {
    struct Node* current = head;
    if (current == NULL) {
        printf("The list is empty.\n");
        return;
    }
    printf("Linked List: ");
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

int main() {
    struct Node* head = NULL;  // Initialize an empty linked list

    // Create nodes and add them to the linked list
    struct Node* node1 = createNode(10);
    struct Node* node2 = createNode(20);
    struct Node* node3 = createNode(30);

    // Link the nodes to form the list
    head = node1;
    node1->next = node2;
    node2->next = node3;

    // Display the linked list
    displayList(head);

    return 0;
}

/*output
Linked List: 10 -> 20 -> 30 -> NULL*/