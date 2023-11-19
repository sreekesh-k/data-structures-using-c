#include <stdio.h>

int push(int arr[], int pos)
{
    if (pos == 9)
    {
        printf("Stack is full\n");
        return pos;
    }
    printf("Enter element: ");
    scanf("%d", &arr[++pos]);
    return pos;
}

int pop(int arr[], int pos)
{
    if (pos == -1)
    {
        printf("Stack is Empty\n");
        return pos;
    }
    printf("%d is poped from the stack \n", arr[pos--]);
    return pos;
}
int peak(int arr[], int pos)
{
    if (pos == -1)
    {
        printf("Stack is Empty\n");
        return pos;
    }
    printf("%d is on the top from the stack \n", arr[pos]);
}
int menu()
{
    int ch;
    printf("***********************\n");
    printf("1.Push\t\t2.Pop\n3.peak\t\t4.Exit\nEnter your choice: ");
    scanf("%d", &ch);
    return ch;
}
void process()
{
    int arr[10], top = -1, ch, e;
    for (ch = menu(); ch != 4; ch = menu())
    {
        switch (ch)
        {
        case 1:

            top = push(arr, top);
            break;
        case 2:
            top = pop(arr, top);
            break;
        case 3:
            peak(arr, top);
            break;
        default:
            printf("invalid choice\n");
            break;
        }
    }
}

int main()
{

    process();

    return 0;
}
