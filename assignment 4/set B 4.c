/*Write a C program to implement a Doubly Circular linked list with following operations
create() and display(), append(),delete()
*/

#include <stdio.h>
#include <stdlib.h>

// Structure for a node in the doubly circular linked list
struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
};

struct Node* head = NULL; // Global variable to store the head of the linked list

// Function to create a new node and add it to the doubly circular linked list
void create(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;

    if (head == NULL) {
        newNode->next = newNode;
        newNode->prev = newNode;
        head = newNode;
    } else {
        struct Node* last = head->prev;
        last->next = newNode;
        newNode->prev = last;
        newNode->next = head;
        head->prev = newNode;
    }
}

// Function to display the doubly circular linked list
void display() {
    struct Node* current = head;

    if (current == NULL) {
        printf("The list is empty.\n");
        return;
    }

    printf("Doubly Circular Linked List: ");
    do {
        printf("%d <-> ", current->data);
        current = current->next;
    } while (current != head);

    printf("(Head)\n");
}

// Function to append a new node at the end of the doubly circular linked list
void append(int value) {
    create(value);
}

// Function to delete a node with a given value from the list
void delete(int value) {
    if (head == NULL) {
        printf("The list is empty. Nothing to delete.\n");
        return;
    }

    struct Node* current = head;

    do {
        if (current->data == value) {
            struct Node* prevNode = current->prev;
            struct Node* nextNode = current->next;
            prevNode->next = nextNode;
            nextNode->prev = prevNode;

            if (current == head) {
                if (current->next == head) {
                    head = NULL;
                } else {
                    head = nextNode;
                }
            }

            free(current);
            printf("%d deleted from the list.\n", value);
            return;
        }
        current = current->next;
    } while (current != head);

    printf("%d not found in the list.\n", value);
}

int main() {
    int choice, value;

    while (1) {
        printf("Doubly Circular Linked List Operations:\n");
        printf("1. Create\n2. Display\n3. Append\n4. Delete\n5. Exit\n");
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
                printf("Enter the value to append: ");
                scanf("%d", &value);
                append(value);
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


/*Output
Doubly Circular Linked List Operations:
1. Create
2. Display
3. Append
4. Delete
5. Exit
Enter your choice: 1
Enter the value to insert: 10

Doubly Circular Linked List Operations:
1. Create
2. Display
3. Append
4. Delete
5. Exit
Enter your choice: 1
Enter the value to insert: 20

Doubly Circular Linked List Operations:
1. Create
2. Display
3. Append
4. Delete
5. Exit
Enter your choice: 2
Doubly Circular Linked List: 10 <-> 20 <-> (Head)

Doubly Circular Linked List Operations:
1. Create
2. Display
3. Append
4. Delete
5. Exit
Enter your choice: 3
Enter the value to append: 30

Doubly Circular Linked List Operations:
1. Create
2. Display
3. Append
4. Delete
5. Exit
Enter your choice: 2
Doubly Circular Linked List: 10 <-> 20 <-> 30 <-> (Head)

Doubly Circular Linked List Operations:
1. Create
2. Display
3. Append
4. Delete
5. Exit
Enter your choice: 4
Enter the value to delete: 20
20 deleted from the list.

Doubly Circular Linked List Operations:
1. Create
2. Display
3. Append
4. Delete
5. Exit
Enter your choice: 2
Doubly Circular Linked List: 10 <-> 30 <-> (Head)

Doubly Circular Linked List Operations:
1. Create
2. Display
3. Append
4. Delete
5. Exit
Enter your choice: 5

*/