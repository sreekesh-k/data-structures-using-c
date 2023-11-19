#include <stdio.h>

void linearSearch(int array[], int n, int x)
{
    printf("Linear Search\n");
    for (int i = 0; i < n; i++)
    {
        if (array[i] == x)
        {
            printf("%d found at index %d\n", x, i);
            return;
        }
    }
    printf("%d not found int the array\n", x);
}
void binarySearch(int array[], int x, int low, int high)
{
    printf("Binary Search\n");
    while (low <= high)
    {
        int mid = low + (high - low) / 2;

        if (array[mid] == x)
        {
            printf("%d found at index %d\n", x, mid);
            return;
        }

        if (array[mid] < x)
            low = mid + 1;

        else
            high = mid - 1;
    }

    printf("%d not found int the array\n", x);
}

int main()
{
    int array[] = {12, 114, 0, 4, 9};
    int search = 4;
    int size = sizeof(array) / sizeof(array[0]);
    linearSearch(array, size, search);
    binarySearch(array, search, 0, size);

    return 0;
}