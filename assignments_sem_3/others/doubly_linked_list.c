#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *next;
    struct node *prev;
} node;

node *create_node(int data);
void insert_first(node **head, int data);
void insert_mid(node **head, int pos, int data);
void insert_last(node **head, int data);
void delete_first(node **head);
void delete_last(node **head);
void delete_mid(node **head, int pos);
void display(node *head);
int get_size(node *head);
void sort(node *head);
float avarage(node *head);

int main() {
    node *head = NULL;
    insert_last(&head, 3);
    insert_last(&head, 4);
    insert_first(&head, 2);
    insert_mid(&head, 3, 24);
    insert_last(&head, 7);
    insert_last(&head, 8);
    insert_last(&head, 32);
    display(head);
    delete_mid(&head, 2);
    display(head);
    delete_first(&head);
    display(head);
    sort(head);
    display(head);
    return 0;
}

node *create_node(int data) {
    node *n = (node *)calloc(1, sizeof(node));
    n->data = data;
    n->next = NULL;
    n->prev = NULL;
    return n;
}

//insertion
void insert_first(node **head, int data) {
    node *new_node = create_node(data);
    if (*head == NULL) {
        *head = new_node;
        return;
    }
    new_node->next = *head;
    (*head)->prev = new_node;
    *head = new_node;
}

void insert_mid(node **head, int pos, int data) {
    node *new_node = create_node(data);
    if (*head == NULL) {
        *head = new_node;
        return;
    }
    node *current = *head;
    for (int i = 1; i < pos - 1; i++) {
        current = current->next;
    }
    new_node->next = current->next;
    current->next = new_node;
    new_node->next->prev = new_node;
    new_node->prev = current;
}

void insert_last(node **head, int data) {
    node *new_node = create_node(data);
    if (*head == NULL) {
        *head = new_node;
        return;
    }
    node *current = *head;
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = new_node;
    new_node->prev = current;
}

//deletion
void delete_first(node **head) {
    if (*head == NULL) {
        printf("Empty list!");
        return;
    }
    node *temp = *head;
    *head = (*head)->next;
    if (head != NULL) {
        (*head)->prev = NULL;
    }
    free(temp);
}

void delete_mid(node **head, int pos) {
    if (*head == NULL) {
        printf("Empty list!");
        return;
    }
    if ((*head)->next == NULL) {
        head = NULL;
    }
    if ((*head)->next->next == NULL) {
        node *temp = (*head)->next;
        (*head)->next = NULL;
        free(temp);
    }
    node *current = *head;
    for (int i = 1; i < pos - 1; i++) {
        current = current->next;
    }
    node *temp = current->next;
    current->next = current->next->next;
    current->next->prev = current;
    free(temp);
}

void delete_last(node **head) {
    if (*head == NULL) {
        printf("Empty list!");
        return;
    }
    node *current = *head;
    while (current->next->next != NULL) {
        current = current->next;
    }
    node *temp = current->next;
    current->next = NULL;
    free(temp);
}

//traverse
void display(node *head) {
    node *current = head;
    while (current != NULL) {
        printf("%d\t", current->data);
        current = current->next;
    }
    printf("\n");
}

int get_size(node *head) {
    node *current = head;
    int count = 0;
    while (current != NULL) {
        current = current->next;
        count++;
    }
    return count;
}

//sorting (bubble sort)
void sort(node *head) {
    node *curr = head;
    int nodes = get_size(head);

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

//avarage
float avarage(node *head) {
    node *curr = head;
    int sum = 0;
    while (curr != NULL) {
        sum += curr->data;
        curr = curr->next;
    }

    int nodes = get_size(head);

    return ((float)sum / nodes);
}