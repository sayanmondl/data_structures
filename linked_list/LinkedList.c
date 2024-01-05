#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
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
    insertFirst(&head, 9);
    insertFirst(&head, 56);
    insertFirst(&head, 5);
    insertFirst(&head, 31);
    insertMid(&head, 3, 24);
    display(head);

    deleteMid(&head, 1);
    display(head);
    return 0;
}

Node *createNode(int data) {
    Node *newNode = (Node *)calloc(1, sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
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
}

// deletion
void deleteFirst(Node **head) {
    if (*head == NULL) {
        printf("Empty list!");
        return;
    }
    Node *temp = *head;
    *head = (*head)->next;
    free(temp);
}

void deleteMid(Node **head, int pos) {
    if (*head == NULL) {
        printf("Empty list!");
        return;
    }

    // For pos = 1
    if (pos == 1) {
        Node *temp = *head;
        *head = (*head)->next;
        free(temp);
    }

    // Creating a node pointer to traverse
    Node *current = *head;
    for (int i = 1; i < pos - 1; i++) {
        current = current->next;
    }

    // Creating a node pointer to point the node to be deleted
    Node *temp = current->next;
    current->next = current->next->next;
    free(temp);
}

void deleteLast(Node **head) {
    // Empty condition
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
        printf("%d -> ", current->data);
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