/*Write a C program to implement a Doubly linked list with Create and Display operation*/

#include <stdio.h>
#include <stdlib.h>

// Structure for a node in the doubly linked list
struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
};

struct Node* head = NULL; // Global variable to store the head of the linked list

// Function to create a new node and add it to the doubly linked list
void create(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;

    if (head == NULL) {
        newNode->prev = NULL;
        head = newNode;
    } else {
        struct Node* current = head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newNode;
        newNode->prev = current;
    }
}

// Function to display the doubly linked list in both forward and backward directions
void display() {
    struct Node* current = head;

    if (current == NULL) {
        printf("The list is empty.\n");
        return;
    }

    printf("Doubly Linked List (Forward): ");
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");

    printf("Doubly Linked List (Backward): NULL");
    while (current->prev != NULL) {
        printf(" <- %d", current->data);
        current = current->prev;
    }
    printf("\n");
}

int main() {
    int choice, value;

    while (1) {
        printf("Doubly Linked List Operations:\n");
        printf("1. Create\n2. Display\n3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the value to insert: ");
                scanf("%d", &value);
                create(value);
                break;
            case 2:
                display();
                break;
            case 3:
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}


/*Output
Doubly Linked List Operations:
1. Create
2. Display
3. Exit
Enter your choice: 1
Enter the value to insert: 10

Doubly Linked List Operations:
1. Create
2. Display
3. Exit
Enter your choice: 1
Enter the value to insert: 20

Doubly Linked List Operations:
1. Create
2. Display
3. Exit
Enter your choice: 1
Enter the value to insert: 30

Doubly Linked List Operations:
1. Create
2. Display
3. Exit
Enter your choice: 2
Doubly Linked List (Forward): 10 -> 20 -> 30 -> NULL
Doubly Linked List (Backward): NULL <- 30 <- 20 <- 10

Doubly Linked List Operations:
1. Create
2. Display
3. Exit
Enter your choice: 3

*/