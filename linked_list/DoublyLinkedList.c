#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
    struct Node *prev;
} Node;

Node *createNode(int data);
void insertFirst(Node **head, int data);
void insertMid(Node **head, int pos, int data);
void insertLast(Node **head, int data);
void deleteFirst(Node **head);
void deleteLast(Node **head);
void deleteMid(Node **head, int pos);
void display(Node *head);
int getSize(Node *head);
void sort(Node *head);
float avarage(Node *head);

int main() {
    Node *head = NULL;
    insertLast(&head, 3);
    insertLast(&head, 4);
    insertFirst(&head, 2);
    insertMid(&head, 3, 24);
    insertLast(&head, 7);
    insertLast(&head, 8);
    insertLast(&head, 32);
    display(head);
    deleteMid(&head, 2);
    display(head);
    deleteFirst(&head);
    display(head);
    sort(head);
    display(head);
    return 0;
}

Node *createNode(int data) {
    Node *newNode = (Node *)calloc(1, sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}

// insertion
void insertFirst(Node **head, int data) {
    Node *newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    newNode->next = *head;
    (*head)->prev = newNode;
    *head = newNode;
}

void insertMid(Node **head, int pos, int data) {
    Node *newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    Node *current = *head;
    for (int i = 1; i < pos - 1; i++) {
        current = current->next;
    }
    newNode->next = current->next;
    current->next = newNode;
    newNode->next->prev = newNode;
    newNode->prev = current;
}

void insertLast(Node **head, int data) {
    Node *newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    Node *current = *head;
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = newNode;
    newNode->prev = current;
}

// deletion
void deleteFirst(Node **head) {
    if (*head == NULL) {
        printf("Empty list!");
        return;
    }
    Node *temp = *head;
    *head = (*head)->next;
    if (head != NULL) {
        (*head)->prev = NULL;
    }
    free(temp);
}

void deleteMid(Node **head, int pos) {
    if (*head == NULL) {
        printf("Empty list!");
        return;
    }
    if ((*head)->next == NULL) {
        head = NULL;
    }
    if ((*head)->next->next == NULL) {
        Node *temp = (*head)->next;
        (*head)->next = NULL;
        free(temp);
    }
    Node *current = *head;
    for (int i = 1; i < pos - 1; i++) {
        current = current->next;
    }
    Node *temp = current->next;
    current->next = current->next->next;
    current->next->prev = current;
    free(temp);
}

void deleteLast(Node **head) {
    if (*head == NULL) {
        printf("Empty list!");
        return;
    }
    Node *current = *head;
    while (current->next->next != NULL) {
        current = current->next;
    }
    Node *temp = current->next;
    current->next = NULL;
    free(temp);
}

// traverse
void display(Node *head) {
    Node *current = head;
    while (current != NULL) {
        printf("%d\t", current->data);
        current = current->next;
    }
    printf("\n");
}

int getSize(Node *head) {
    Node *current = head;
    int count = 0;
    while (current != NULL) {
        current = current->next;
        count++;
    }
    return count;
}

// sorting (bubble sort)
void sort(Node *head) {
    Node *curr = head;
    int nodes = getSize(head);

    for (int i = 0; i < nodes - 1; i++) {
        for (int j = 0; j < nodes - i - 1; j++) {
            if (curr->data > curr->next->data) {
                int temp = curr->data;
                curr->data = curr->next->data;
                curr->next->data = temp;
            }
            curr = curr->next;
        }
        curr = head;
    }
}

// avarage
float avarage(Node *head) {
    Node *curr = head;
    int sum = 0;
    while (curr != NULL) {
        sum += curr->data;
        curr = curr->next;
    }

    int nodes = getSize(head);

    return ((float)sum / nodes);
}