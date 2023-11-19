#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
};
typedef struct node node;
node *head = NULL;
void insert(int e)
{
    if (head == NULL)
    {
        head = (node *)malloc(sizeof(node));
        head->data = e;
        head->next = head;
    }
    else
    {
        node *t = head;
        while (t->next != head)
        {
            t = t->next;
        }
        t->next = (node *)malloc(sizeof(node));
        t->next->data = e;
        t->next->next = head;
    }
}
void delete(int e)
{
    if (head == NULL)
    {
        printf("List is empty :(\n");
    }
    else if (head->data == e && head->next == head)
    {
        printf("%d is removed from the list\n", e);
        head = NULL;
    }
    else if (head->data == e && head->next != head)
    {
        printf("%d is removed from the list\n", e);
        head = head->next;
    }
    else
    {
        node *t = head;
        while (t->next->data != e && t->next->next != head)
        {
            t = t->next;
        }
        if (t->next->data == e)
        {
            printf("%d is removed from the list\n", e);
            t->next = t->next->next;
        }
        else
        {
            printf("Element not found\n");
        }
    }
}
void disp()
{
    if (head == NULL)
    {
        printf("List is empty :(\n");
    }
    else
    {
        node *t = head;
        printf("[Head]");
        while (t->next != head)
        {
            printf("%d ->", t->data);
            t = t->next;
        }
        printf("%d[Tail]\n", t->data);
    }
}
int main()
{
    insert(1);
    insert(20);
    insert(30);
    insert(50);
    insert(60);
    insert(63);
    insert(20);
    disp();
    delete (20);
    disp();
    delete (50);
    disp();
    delete (1);
    disp();
    delete (200);
    disp();
    return 0;
}
