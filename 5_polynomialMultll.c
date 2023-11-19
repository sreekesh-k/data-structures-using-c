#include <stdio.h>
#include <stdlib.h>

struct term
{
    int coeff;
    int exp;
    struct term *next;
};
typedef struct term term;

term *poly1 = NULL;
term *poly2 = NULL;
term *result = NULL;

void insert(term **poly, int coeff, int exp)
{
    term *n = (term *)malloc(sizeof(term));
    n->coeff = coeff;
    n->exp = exp;
    n->next = NULL;
    if (*poly == NULL)
        *poly = n;
    else
    {
        term *t = *poly;
        while (t->next != NULL)
            t = t->next;
        t->next = n;
    }
}

void sort(term *poly)
{
    if (poly->next != NULL)
    {
        term *i = poly;
        term *j = poly;
        for (i = poly; i->next != NULL; i = i->next)
        {
            for (j = poly; j->next != NULL; j = j->next)
            {
                if (j->exp > j->next->exp)
                {
                    int temp = j->exp;
                    j->exp = j->next->exp;
                    j->next->exp = temp;
                    temp = j->coeff;
                    j->coeff = j->next->coeff;
                    j->next->coeff = temp;
                }
            }
        }
    }
}

void disp(term *poly)
{
    term *t = poly;
    while (t != NULL)
    {
        if (t->next == NULL)
            printf("%dx^%d\n", t->coeff, t->exp);
        else
            printf("%dx^%d +", t->coeff, t->exp);
        t = t->next;
    }
}
void mult(term *poly1, term *poly2)
{
    term *t = poly1;
    term *s = poly2;
    while (t != NULL)
    {
        s = poly2;
        while (s != NULL)
        {
            insert(&result, t->coeff * s->coeff, t->exp + s->exp);
            s = s->next;
        }
        t = t->next;
    }
    sort(result);
    disp(result);
}

int main()
{
    printf("instructions\nEnter x then its coeff and its exponent\neg:x 1 2 is 1x^2\nEnter 'f' when finish\n");
    printf("**************************\n");

    int coeff, exp;
    char ch = 'x';

    printf("Polynomial 1\n");
    while (ch)
    {
        scanf(" %c", &ch);
        if (ch == 'f')
            break;
        scanf("%d%d", &coeff, &exp);
        insert(&poly1, coeff, exp);
    }
    sort(poly1);

    printf("Polynomial 2\n");
    while (ch)
    {
        scanf(" %c", &ch);
        if (ch == 'f')
            break;
        scanf("%d%d", &coeff, &exp);
        insert(&poly2, coeff, exp);
    }
    sort(poly2);
    printf("\nMULTIPLIED:\n");
    disp(poly1);
    printf("\t*\n");
    disp(poly2);
    printf("___________________________________\n");
    mult(poly1, poly2);
    return 0;
}
