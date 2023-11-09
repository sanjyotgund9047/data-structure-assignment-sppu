/*Write a C program to reverse a singly linkedlist.*/

#include <stdio.h>
#include <stdlib.h>

// Structure for a node in a singly linked list
struct Node {
    int data;
    struct Node* next;
};

typedef struct Node LinkedList;

// Function to insert a node at the beginning of a linked list
void insertFront(LinkedList** head, int data) {
    LinkedList* newNode = (LinkedList*)malloc(sizeof(LinkedList));
    newNode->data = data;
    newNode->next = *head;
    *head = newNode;
}

// Function to reverse a singly linked list
void reverseLinkedList(LinkedList** head) {
    LinkedList* prev = NULL;
    LinkedList* current = *head;
    LinkedList* next;

    while (current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }

    *head = prev;
}

// Function to display a linked list
void displayList(LinkedList* head) {
    LinkedList* current = head;
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

int main() {
    LinkedList* list = NULL;

    // Insert elements into the linked list
    insertFront(&list, 10);
    insertFront(&list, 20);
    insertFront(&list, 30);
    insertFront(&list, 40);
    insertFront(&list, 50);

    printf("Original Linked List: ");
    displayList(list);

    reverseLinkedList(&list);

    printf("Reversed Linked List: ");
    displayList(list);

    return 0;
}

/*Output
Original Linked List: 50 -> 40 -> 30 -> 20 -> 10 -> NULL
Reversed Linked List: 10 -> 20 -> 30 -> 40 -> 50 -> NULL

*/