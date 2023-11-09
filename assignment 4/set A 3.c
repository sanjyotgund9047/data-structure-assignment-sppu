/*Write a C program to implement a Singly Circular linked list with following operations
create(), display(), search(),length()*/

#include <stdio.h>
#include <stdlib.h>

// Structure for a node in the linked list
struct Node {
    int data;
    struct Node* next;
};

struct Node* head = NULL; // Global variable to store the head of the linked list

// Function to create a new node and add it to the circular linked list
void create(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    if (head == NULL) {
        head = newNode;
        newNode->next = head;
    } else {
        struct Node* temp = head;
        while (temp->next != head) {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->next = head;
    }
}

// Function to display the circular linked list
void display() {
    if (head == NULL) {
        printf("The list is empty.\n");
        return;
    }

    struct Node* current = head;

    do {
        printf("%d -> ", current->data);
        current = current->next;
    } while (current != head);

    printf(" (Head)\n");
}

// Function to search for a given value in the circular linked list
int search(int value) {
    if (head == NULL) {
        return 0; // List is empty, value not found
    }

    struct Node* current = head;

    do {
        if (current->data == value) {
            return 1; // Value found
        }
        current = current->next;
    } while (current != head);

    return 0; // Value not found
}

// Function to find the length of the circular linked list
int length() {
    if (head == NULL) {
        return 0; // List is empty
    }

    struct Node* current = head;
    int count = 0;

    do {
        count++;
        current = current->next;
    } while (current != head);

    return count;
}

int main() {
    int choice, value;

    while (1) {
        printf("Circular Linked List Operations:\n");
        printf("1. Create\n2. Display\n3. Search\n4. Length\n5. Exit\n");
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
                printf("Enter the value to search: ");
                scanf("%d", &value);
                if (search(value)) {
                    printf("%d is found in the list.\n", value);
                } else {
                    printf("%d is not found in the list.\n", value);
                }
                break;
            case 4:
                printf("Length of the list: %d\n", length());
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
Circular Linked List Operations:
1. Create
2. Display
3. Search
4. Length
5. Exit
Enter your choice: 1
Enter the value to insert: 10

Circular Linked List Operations:
1. Create
2. Display
3. Search
4. Length
5. Exit
Enter your choice: 1
Enter the value to insert: 20

Circular Linked List Operations:
1. Create
2. Display
3. Search
4. Length
5. Exit
Enter your choice: 1
Enter the value to insert: 30

Circular Linked List Operations:
1. Create
2. Display
3. Search
4. Length
5. Exit
Enter your choice: 2
10 -> 20 -> 30 ->  (Head)

Circular Linked List Operations:
1. Create
2. Display
3. Search
4. Length
5. Exit
Enter your choice: 3
Enter the value to search: 20
20 is found in the list.

Circular Linked List Operations:
1. Create
2. Display
3. Search
4. Length
5. Exit
Enter your choice: 3
Enter the value to search: 40
40 is not found in the list.

Circular Linked List Operations:
1. Create
2. Display
3. Search
4. Length
5. Exit
Enter your choice: 4
Length of the list: 3

Circular Linked List Operations:
1. Create
2. Display
3. Search
4. Length
5. Exit
Enter your choice: 5

*/