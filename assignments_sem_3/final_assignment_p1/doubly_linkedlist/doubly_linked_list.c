#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
    struct Node *prev;
} Node;

Node *create_node(int data);
void insert(Node **head, int pos, int data);
void delete(Node **head, int pos);
void display(Node *head);
void sort(Node *head);
int get_response();
int get_size(Node *head);

/* Assuming 0 as 1st position (head) */

int main() {
    Node *head = NULL;
    int val, pos;
    while (1) {
        switch (get_response()) {
        case 0:
            return 0;
        case 1:
            printf("Initialize list with a value: ");
            scanf("%d", &val);
            head = create_node(val);
            break;
        case 2:
            printf("Enter value and position: ");
            scanf("%d%d", &val, &pos);
            insert(&head, pos, val);
            break;
        case 3:
            printf("Enter position: ");
            scanf("%d", &pos);
            delete(&head, pos);
            break;
        case 4:
            printf("List = {");
            display(head);
            printf("}\n");
            break;
        case 5:
            sort(head);
            printf("List sorted.");
            break;
        default: printf("Wrong response.");
        }
    }
    return 0;
}

int get_response() {
    printf("1. Create Doubly Linked List with an initial value.\n");
    printf("2. Insert node at a particular position\n");
    printf("3. Delete node at a particular position.\n");
    printf("4. Display list.\n");
    printf("5. Sort list.\n");
    printf("0. Quit.\n");
    int response;
    printf("Response: ");
    scanf("%d", &response);
    getchar();
    return response;
}

Node *create_node(int data) {
    Node *n = (Node *)calloc(1, sizeof(Node));
    n->data = data;
    n->next = NULL;
    n->prev = NULL;
    return n;
}

void insert(Node **head, int pos, int data) {
    if (pos < 0 || pos > get_size(*head)) {
        printf("Invalid position.\n");
        return;
    }

    Node *new_node = create_node(data);
    if (*head == NULL) {
        *head = new_node;
        return;
    }

    if (pos == 0) {
        new_node->next = *head;
        (*head)->prev = new_node;
        *head = new_node;
        return;
    }

    Node *current = *head;
    for (int i = 0; i < pos - 1; i++) {
        current = current->next;
    }

    if (current->next == NULL) {
        current->next = new_node;
        new_node->prev = current;
        return;
    }
    new_node->next = current->next;
    current->next = new_node;
    new_node->next->prev = new_node;
    new_node->prev = current;
}

void delete(Node **head, int pos) {
    if (pos < 0 || pos > get_size(*head) - 1) {
        printf("Invalid position.\n");
        return;
    }

    if (*head == NULL) {
        printf("Empty list!");
        return;
    }

    if ((*head)->next == NULL) {
        Node *temp = *head;
        free(temp);
        *head = NULL;
        return;
    }

    if (pos == 0) {
        Node *temp = *head;
        *head = (*head)->next;
        (*head)->prev = NULL;
        free(temp);
        return;
    }

    Node *current = *head;
    for (int i = 0; i < pos - 1; i++) {
        current = current->next;
    }

    Node *temp = current->next;
    if (current->next->next == NULL) {
        current->next = NULL;
        free(temp);
        return;
    }
    current->next = current->next->next;
    current->next->prev = current;
    free(temp);
}

void display(Node *head) {
    Node *current = head;
    if (head != NULL) {
        printf("null<->");
    }
    while (current != NULL) {
        printf("%d<->", current->data);
        current = current->next;
    }
    printf("null");
}

int get_size(Node *head) {
    Node *current = head;
    int count = 0;
    while (current != NULL) {
        current = current->next;
        count++;
    }
    return count;
}

void sort(Node *head) {
    Node *curr = head;
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
