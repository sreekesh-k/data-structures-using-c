#include <stdio.h>

void disp(int coef[], int expo[], int n)
{
    int i;
    for (i = 0; i < n; i++)
    {
        if (i + 1 == n)
            printf("%dx^%d\n", coef[i], expo[i]);
        else
            printf("%dx^%d + ", coef[i], expo[i]);
    }
}

void sort(int coef[], int expo[], int n)
{
    int i, j;
    for (i = 0; i < n - 1; i++)
    {
        for (j = 0; j < n - i - 1; j++)
        {
            if (expo[j] > expo[j + 1])
            {
                int a;
                a = expo[j];
                expo[j] = expo[j + 1];
                expo[j + 1] = a;
                a = coef[j];
                coef[j] = coef[j + 1];
                coef[j + 1] = a;
            }
        }
    }
}

void add(int coef1[], int expo1[], int coef2[], int expo2[], int n1, int n2)
{
    int i = 0, j = 0, k = 0;
    int sumcoef[100], sumexpo[100];

    while (i < n1 && j < n2)
    {
        if (expo1[i] == expo2[j])
        {
            sumcoef[k] = coef1[i] + coef2[j];
            sumexpo[k] = expo1[i];
            i++;
            j++;
        }
        else if (expo1[i] > expo2[j])
        {
            sumcoef[k] = coef1[i];
            sumexpo[k] = expo1[i];
            i++;
        }
        else
        {
            sumcoef[k] = coef2[j];
            sumexpo[k] = expo2[j];
            j++;
        }
        k++;
    }

    while (i < n1)
    {
        sumcoef[k] = coef1[i];
        sumexpo[k] = expo1[i];
        i++;
        k++;
    }

    while (j < n2)
    {
        sumcoef[k] = coef2[j];
        sumexpo[k] = expo2[j];
        j++;
        k++;
    }
    sort(sumcoef, sumexpo, k);
    disp(sumcoef, sumexpo, k);
}

void read(int coef[], int expo[], int n)
{
    int i;
    static int j = 0;
    printf("\nFor polynomial %d\n", ++j);
    printf("Enter the coefficient and exponent\n");
    for (i = 0; i < n; i++)
    {
        printf("For term %d: ", i + 1);
        scanf("%d %d", &coef[i], &expo[i]);
    }
    sort(coef, expo, n);
}

int main()
{
    int n1, n2;
    printf("Enter the number of terms for polynomial 1: ");
    scanf("%d", &n1);
    printf("Enter the number of terms for polynomial 2: ");
    scanf("%d", &n2);

    int coef1[n1], expo1[n1];
    int coef2[n2], expo2[n2];

    read(coef1, expo1, n1);
    read(coef2, expo2, n2);

    printf("\n");
    disp(coef1, expo1, n1);
    printf("\t+\n");
    disp(coef2, expo2, n2);
    printf("___________________________________\n");

    add(coef1, expo1, coef2, expo2, n1, n2);

    return 0;
}
