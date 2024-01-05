
#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
} node;

void display(node *head)
{
    node *T = head;
    while(T != NULL)
    {
        printf("%d\t", T->data);
        T = T->next;
    }
}

int main() {

    node *n1 = (node *)calloc(1,sizeof(node));

    printf("enter the first el: ");
    scanf("%d", &n1->data);
    n1->next = NULL;

    printf("%d\n", n1->data);
    printf("%p\t%p\n", n1, n1->next);

    n1->next = (node*)calloc(1,sizeof(node));
    printf("enter second element: ");
    scanf("%d", &n1->next->data);

    display(n1);


    // int a[3][5];
    // printf("%p\n", a);
    // printf("%p\n", a[3][5]);
    // printf("%p\n", a[0]);
    // printf("%p\n", a[0][0]);
    // printf("%p\n", &a);
}