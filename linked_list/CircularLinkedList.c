#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
} Node;

Node *createNode(int data);
void insert(Node **head, int data);
void insertMid(Node **head, int pos, int data);
void deleteFirst(Node **head);
void deleteLast(Node **head);
void deleteMid(Node **head, int pos);
void display(Node *head);
int getSize(Node *head);
void sort(Node *head);
float avarage(Node *head);

int main() {
    Node *head = NULL;
    insert(&head, 3);
    insert(&head, 4);
    insert(&head, 2);
    insertMid(&head, 3, 24);
    insert(&head, 7);
    insert(&head, 8);
    insert(&head, 32);
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
    return newNode;
}

// insertion
void insert(Node **head, int data) {
    Node *newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
        (*head)->next = *head;
        return;
    }
    Node *current = *head;
    while (current->next != *head) {
        current = current->next;
    }
    current->next = newNode;
    newNode->next = *head;
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
}

// deletion
void deleteFirst(Node **head) {
    if (*head == NULL) {
        printf("Empty list!");
        return;
    }
    Node *current = *head;
    while (current->next != *head) {
        current = current->next;
    }
    *head = (*head)->next;
    Node *temp = current->next;
    current->next = *head;
    free(temp);
}

void deleteMid(Node **head, int pos) {
    if (*head == NULL) {
        printf("Empty list!");
        return;
    }
    Node *current = *head;
    for (int i = 1; i < pos - 1; i++) {
        current = current->next;
    }
    Node *temp = current->next;
    current->next = current->next->next;
    free(temp);
}

void deleteLast(Node **head) {
    if (*head == NULL) {
        printf("Empty list!");
        return;
    }
    Node *current = *head;
    while (current->next->next != *head) {
        current = current->next;
    }
    Node *temp = current->next;
    current->next = *head;
    free(temp);
}

// traverse
void display(Node *head) {
    Node *current = head;
    while (current->next != head) {
        printf("%d\t", current->data);
        current = current->next;
    }
    printf("%d\t", current->data);
    printf("\n");
}

int getSize(Node *head) {
    Node *current = head;
    int count = 1;
    while (current->next != head) {
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