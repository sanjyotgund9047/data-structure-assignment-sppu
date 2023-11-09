/*Write a C program to implement a Doubly linked list with following operations
create() , display(), insert(),delete()*/

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

// Function to display the doubly linked list
void display() {
    struct Node* current = head;

    if (current == NULL) {
        printf("The list is empty.\n");
        return;
    }

    printf("Doubly Linked List: ");
    while (current != NULL) {
        printf("%d <-> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

// Function to insert a new node with a given value at the end of the list
void insert(int value) {
    create(value);
}

// Function to delete a node with a given value from the list
void delete(int value) {
    struct Node* current = head;

    while (current != NULL) {
        if (current->data == value) {
            if (current->prev != NULL) {
                current->prev->next = current->next;
            } else {
                head = current->next;
                if (head != NULL) {
                    head->prev = NULL;
                }
            }
            if (current->next != NULL) {
                current->next->prev = current->prev;
            }
            free(current);
            return;
        }
        current = current->next;
    }
    printf("%d not found in the list.\n", value);
}

int main() {
    int choice, value;

    while (1) {
        printf("Doubly Linked List Operations:\n");
        printf("1. Create\n2. Display\n3. Insert\n4. Delete\n5. Exit\n");
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
                printf("Enter the value to insert: ");
                scanf("%d", &value);
                insert(value);
                break;
            case 4:
                printf("Enter the value to delete: ");
                scanf("%d", &value);
                delete(value);
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}

/*output
Doubly Linked List Operations:
1. Create
2. Display
3. Insert
4. Delete
5. Exit
Enter your choice: 1
Enter the value to insert: 10

Doubly Linked List Operations:
1. Create
2. Display
3. Insert
4. Delete
5. Exit
Enter your choice: 1
Enter the value to insert: 20

Doubly Linked List Operations:
1. Create
2. Display
3. Insert
4. Delete
5. Exit
Enter your choice: 1
Enter the value to insert: 30

Doubly Linked List Operations:
1. Create
2. Display
3. Insert
4. Delete
5. Exit
Enter your choice: 2
Doubly Linked List: 10 <-> 20 <-> 30 <-> NULL

Doubly Linked List Operations:
1. Create
2. Display
3. Insert
4. Delete
5. Exit
Enter your choice: 3
Enter the value to insert: 40

Doubly Linked List Operations:
1. Create
2. Display
3. Insert
4. Delete
5. Exit
Enter your choice: 2
Doubly Linked List: 10 <-> 20 <-> 30 <-> 40 <-> NULL

Doubly Linked List Operations:
1. Create
2. Display
3. Insert
4. Delete
5. Exit
Enter your choice: 4
Enter the value to delete: 20

Doubly Linked List Operations:
1. Create
2. Display
3. Insert
4. Delete
5. Exit
Enter your choice: 2
Doubly Linked List: 10 <-> 30 <-> 40 <-> NULL

Doubly Linked List Operations:
1. Create
2. Display
3. Insert
4. Delete
5. Exit
Enter your choice: 5

*/