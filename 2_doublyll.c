#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
    struct node *prev;
};

struct node *head = NULL;

void insert(int e)
{
    if (head == NULL)
    {
        head = (struct node *)malloc(sizeof(struct node));
        head->data = e;
        head->next = NULL;
        head->prev = NULL;
    }
    else
    {
        struct node *t = head;
        while (t->next != NULL)
        {
            t = t->next;
        }

        t->next = (struct node *)malloc(sizeof(struct node));
        t->next->data = e;
        t->next->next = NULL;
        t->next->prev = t;
    }
}

void display()
{
    struct node *t = head;
    if (head == NULL)
    {
        printf("Empty Doubly Linked List.\n");
        return;
    }
    while (t != NULL)
    {
        printf("%d ", t->data);
        t = t->next;
    }
    printf("\n");
}

int main()
{
    display();
    insert(10);
    insert(20);
    insert(30);
    display();
    insert(40);
    insert(50);
    display();

    return 0;
}
