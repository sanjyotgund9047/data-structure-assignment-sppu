/*Write a C program to concatenate two linkedlist.*/

#include <stdio.h>
#include <stdlib.h>

// Structure for a node in a linked list
struct Node {
    int data;
    struct Node* next;
};

typedef struct Node LinkedList;

// Function to insert a node at the end of a linked list
void insertEnd(LinkedList** head, int data) {
    LinkedList* newNode = (LinkedList*)malloc(sizeof(LinkedList));
    newNode->data = data;
    newNode->next = NULL;

    if (*head == NULL) {
        *head = newNode;
    } else {
        LinkedList* current = *head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newNode;
    }
}

// Function to concatenate two linked lists
LinkedList* concatenateLists(LinkedList* list1, LinkedList* list2) {
    if (list1 == NULL) {
        return list2;
    }

    LinkedList* current = list1;
    while (current->next != NULL) {
        current = current->next;
    }

    current->next = list2;

    return list1;
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
    LinkedList* list1 = NULL;
    LinkedList* list2 = NULL;

    // Insert elements into the first linked list
    insertEnd(&list1, 10);
    insertEnd(&list1, 20);
    insertEnd(&list1, 30);

    // Insert elements into the second linked list
    insertEnd(&list2, 40);
    insertEnd(&list2, 50);

    printf("First Linked List: ");
    displayList(list1);

    printf("Second Linked List: ");
    displayList(list2);

    // Concatenate the two linked lists
    list1 = concatenateLists(list1, list2);

    printf("Concatenated Linked List: ");
    displayList(list1);

    return 0;
}

/*Output
First Linked List: 10 -> 20 -> 30 -> NULL
Second Linked List: 40 -> 50 -> NULL
Concatenated Linked List: 10 -> 20 -> 30 -> 40 -> 50 -> NULL
*/