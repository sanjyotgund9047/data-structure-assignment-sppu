/*Write a C program to find intersection of two linkedlist.*/

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

// Function to find and return the intersection of two linked lists
LinkedList* findIntersection(LinkedList* list1, LinkedList* list2) {
    LinkedList* intersection = NULL;
    LinkedList* current1 = list1;
    LinkedList* current2;

    while (current1 != NULL) {
        current2 = list2;

        while (current2 != NULL) {
            if (current1->data == current2->data) {
                insertEnd(&intersection, current1->data);
                break;
            }

            current2 = current2->next;
        }

        current1 = current1->next;
    }

    return intersection;
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
    insertEnd(&list1, 40);
    insertEnd(&list1, 50);

    // Insert elements into the second linked list
    insertEnd(&list2, 20);
    insertEnd(&list2, 40);
    insertEnd(&list2, 60);

    printf("First Linked List: ");
    displayList(list1);

    printf("Second Linked List: ");
    displayList(list2);

    LinkedList* intersection = findIntersection(list1, list2);

    printf("Intersection Linked List: ");
    displayList(intersection);

    return 0;
}

/*output
First Linked List: 10 -> 20 -> 30 -> 40 -> 50 -> NULL
Second Linked List: 20 -> 40 -> 60 -> NULL
Intersection Linked List: 20 -> 40 -> NULL

*/