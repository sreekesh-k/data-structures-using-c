#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};
typedef struct node node;
node *f = NULL;
node *r = NULL;
void enqueue(int e)
{
    node *t = NULL;
    if (f == NULL && r == NULL)
    {
        t = (node *)malloc(sizeof(node));
        t->data = e;
        t->next = NULL;
        f = t;
        r = t;
    }
    else
    {
        t = (node *)malloc(sizeof(node));
        t->data = e;
        t->next = NULL;
        r->next = t;
        r = t;
    }
}
void dequeue()
{
    if (f == NULL && r == NULL)
    {
        printf("EMPTY\n");
    }
    else
    {
        printf("%d is dequeued\n", f->data);
        f = f->next;
        if (f == NULL)
        {
            r = NULL;
        }
    }
}
int main()
{
    enqueue(10);
    enqueue(20);
    enqueue(30);
    enqueue(40);
    enqueue(50);
    dequeue();
    dequeue();
    dequeue();
    return 0;
}
