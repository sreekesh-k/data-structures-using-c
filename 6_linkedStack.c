#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
};
typedef struct node node;
node *top = NULL;
void push(int e)
{
    node *t = (node *)malloc(sizeof(node));
    t->data = e;
    t->next = top;
    top = t;
}
void pop()
{
    if (top == NULL)
    {
        printf("No Elements\n");
    }
    else
    {
        printf("%d is removed from stack\n", top->data);
        top = top->next;
    }
}
int peak()
{
    printf("%d is on top of the stack\n", top->data);
}
int main()
{
    push(10);
    push(20);
    push(30);
    push(40);
    push(50);
    while (top != NULL)
    {
        peak();
        pop();
    }

    return 0;
}
