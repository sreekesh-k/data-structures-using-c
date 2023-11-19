#include <stdio.h>
#include <stdlib.h>

int main()
{
    int *numbers = NULL;
    int n = 0;

    while (1)
    {
        int e;

        printf("Enter a new element (enter 0 to exit): ");
        scanf("%d", &e);

        if (e == 0)
            break;

        int *temp = (int *)realloc(numbers, (n + 1) * sizeof(int));

        numbers = temp;
        numbers[n] = e;
        n++;
    }

    double sum = 0.0;
    for (int i = 0; i < n; i++)
    {
        sum += numbers[i];
    }
    double average = (n > 0) ? sum / n : 0.0;

    printf("Average: %.2f\n", average);

    return 0;
}