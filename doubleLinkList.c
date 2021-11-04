#include<stdio.h>
#include<stdlib.h>

typedef struct node {
    int data;
    struct node* next;
    struct node* prev;
} NODE;

NODE* createNode(int data) {
    NODE* ptr = (NODE*)malloc(sizeof(NODE));
    ptr->data = data;
    ptr->next = NULL;
    ptr->prev = NULL;
    return ptr;
}


void addAtBeginning(NODE** head, NODE** tail, int data) {
    NODE* ptr = createNode(data);
    if(*head == NULL) {
        *head = ptr;
        *tail = ptr;
    } else {
        ptr->next = *head;
        (*head)->prev = ptr;
        *head = ptr;
    }
}

void addAtEnd(NODE** head, NODE** tail, int data) {
    NODE* ptr = createNode(data);
    if(*head == NULL) {
        *head = ptr;
        *tail =ptr;
    } else {
        ptr->prev = *tail;
        (*tail)->next = ptr;
        *tail = ptr;
    }
}

void deleteFirst(NODE** head, NODE** tail) {
    if(head != NULL) {
        NODE* ptr = *head;
        if(*head == *tail) {
            free(ptr);
            *head = NULL;
            *tail = NULL;
        } else {
            *head = ptr->next;
            (ptr->next)->prev = NULL;
            free(ptr);
        }
    }
}

void deleteLast(NODE** head, NODE** tail) {
    if(head != NULL) {
        NODE* ptr = *tail;
        if(*head == *tail) {
            free(ptr);
            *head = NULL;
            *tail = NULL;
        } else {
            (ptr->prev)->next = NULL;
            *tail = ptr->prev;
            free(ptr);
        }
    }
}

void printList(NODE* head) {
    if(head == NULL) {
        printf("\nLinked list is empty");
    } else {
        NODE* ptrTravel = head;
        while(ptrTravel != NULL) {
            printf("%d ", ptrTravel->data);
            ptrTravel = ptrTravel->next;
        }
    }
}

int main() {
    NODE* head = NULL;
    NODE* tail = NULL;
    for(int i = 5; i>=1; i--) {
        addAtBeginning(&head, &tail, i);
    }
    for(int i = 6; i<= 10; i++) {
        addAtEnd(&head, &tail, i);
    }
    printList(head);
    printf("\nAfter deleting first : ");
    deleteFirst(&head, &tail);
    deleteFirst(&head, &tail);
    printList(head);
    printf("\nAfter deleting last : ");
    deleteLast(&head, &tail);
    printList(head);
}