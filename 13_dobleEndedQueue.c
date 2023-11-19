#include <stdio.h>

#define Max 5

void enqueueFront(int q[], int *f, int *r)
{
    if ((*r + 1) % Max == *f)
    {
        printf("\nQueue is full!");
    }
    else
    {
        if (*f == -1)
        {
            *f = *r = 0;
        }
        else
        {
            *f = (*f - 1 + Max) % Max; 
        }

        printf("Enter the element: ");
        scanf("%d", &q[*f]);
    }
}

void enqueueRear(int q[], int *f, int *r)
{
    if ((*r + 1) % Max == *f)
    {
        printf("\nQueue is full!");
    }
    else
    {
        if (*f == -1)
        {
            *f = *r = 0;
        }
        else
        {
            *r = (*r + 1) % Max; 
        }

        printf("Enter the element: ");
        scanf("%d", &q[*r]);
    }
}

void dequeueFront(int q[], int *f, int *r)
{
    if (*f == -1)
    {
        printf("Queue is empty!");
    }
    else
    {
        printf("Dequeued item %d from the front.", q[*f]);
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

void dequeueRear(int q[], int *f, int *r)
{
    if (*f == -1)
    {
        printf("Queue is empty!");
    }
    else
    {
        printf("Dequeued item %d from the rear.", q[*r]);
        if (*f == *r)
        {
            *f = *r = -1;
        }
        else
        {
            *r = (*r - 1 + Max) % Max;
        }
    }
}

int main()
{
    int q[Max], f = -1, r = -1;
    int ch;

    do
    {
        printf("\n******************************************");
        printf("\n1.Enqueue Front\t\t2.Enqueue Rear\n3.Dequeue Front\t\t4.Dequeue Rear\n5.Exit\nEnter your choice: ");
        scanf("%d", &ch);

        switch (ch)
        {
        case 1:
            enqueueFront(q, &f, &r);
            break;
        case 2:
            enqueueRear(q, &f, &r);
            break;
        case 3:
            dequeueFront(q, &f, &r);
            break;
        case 4:
            dequeueRear(q, &f, &r);
            break;
        case 5:
            break;
        default:
            printf("Enter a valid choice!");
            break;
        }
    } while (ch != 5);

    return 0;
}
