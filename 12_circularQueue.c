#include <stdio.h>

#define Max 5

void enqueue(int q[], int *f, int *r)
{
    if ((*r + 1) % Max == *f)
    {
        printf("\nQueue is full!");
    }
    else
    {
        if (*f == -1)
        {
            *f = 0;
        }
        printf("Enter the element: ");
        scanf("%d", &q[*r]);
        *r = (*r + 1) % Max;
    }
}

void dequeue(int q[], int *f, int *r)
{
    if (*f == -1)
    {
        printf("Queue is empty!");
    }
    else
    {
        printf("Dequeued item %d.", q[*f]);
        if (*f == *r)
        {
            *f = *r = -1;
        }
        else
        {
            *f = (*f + 1) % Max;
        }
    }
}

int main()
{
    int q[Max], f = -1, r = -1;
    int ch;

    do
    {
        printf("\n*********************");
        printf("\n1.Enqueue\t2.Dequeue\n3.Exit\nEnter your choice: ");
        scanf("%d", &ch);

        switch (ch)
        {
        case 1:
            enqueue(q, &f, &r);
            break;
        case 2:
            dequeue(q, &f, &r);
            break;
        case 3:
            break;
        default:
            printf("Enter a valid choice!");
            break;
        }
    } while (ch != 3);

    return 0;
}
