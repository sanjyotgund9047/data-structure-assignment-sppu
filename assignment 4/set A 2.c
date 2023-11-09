/*Write a C program to implement a Singly linked list with following operations 
create() , display(), insert(),delete()*/

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

// Function to insert a new node at the end of the list
void insertAtEnd(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
    } else {
        struct Node* current = *head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newNode;
    }
}

// Function to delete a node with a specific value from the list
void deleteNode(struct Node** head, int key) {
    struct Node* current = *head;
    struct Node* prev = NULL;

    if (current != NULL && current->data == key) {
        *head = current->next;
        free(current);
        return;
    }

    while (current != NULL && current->data != key) {
        prev = current;
        current = current->next;
    }

    if (current == NULL) {
        printf("%d not found in the list.\n", key);
        return;
    }

    prev->next = current->next;
    free(current);
}

int main() {
    struct Node* head = NULL;  // Initialize an empty linked list

    // Insert nodes at the end of the list
    insertAtEnd(&head, 10);
    insertAtEnd(&head, 20);
    insertAtEnd(&head, 30);

    // Display the linked list
    displayList(head);

    // Delete a node with a specific value
    deleteNode(&head, 20);

    // Display the modified linked list
    displayList(head);

    return 0;
}

/*output
Linked List: 10 -> 20 -> 30 -> NULL
Linked List: 10 -> 30 -> NULL
*/