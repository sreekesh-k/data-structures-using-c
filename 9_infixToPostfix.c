#include <stdio.h>
#include <ctype.h>

int st = -1, pos = -1;
char stack[20], postfix[20];

int prec(char ch)
{
    switch (ch)
    {
    case '-':
        return 1;
    case '+':
        return 2;
    case '/':
        return 3;
    case '*':
        return 4;
    default:
        return 0;
    }
}

void pushstk(char e) { stack[++st] = e; }
char peekstk() { return stack[st]; }
char popstk() { return stack[st--]; }

void pushpos(char e) { postfix[++pos] = e; }
char peekpos() { return postfix[pos]; }
char poppos() { return postfix[pos--]; }

int main()
{
    char infix[20];
    printf("Enter the expression\n");
    scanf("%s", infix);

    int i, j;
    char ch;

    for (i = 0; infix[i] != '\0'; i++)
    {
        ch = infix[i];
        if (!isdigit(ch))
        {
            switch (ch)
            {
            case '(':
                pushstk(ch);
                break;
            case '*':
            case '/':
            case '+':
            case '-':
                while (st != -1 && prec(ch) <= prec(peekstk()))
                {
                    pushpos(popstk());
                }
                pushstk(ch);
                break;
            case ')':
                while (st != -1 && peekstk() != '(')
                {
                    pushpos(popstk());
                }
                if (st != -1 && peekstk() == '(')
                {
                    popstk();
                }
                break;
            }
        }
        else
        {
            pushpos(ch);
        }
    }

    while (st != -1)
    {
        pushpos(popstk());
    }

    printf("\nPostfix: %s\n", postfix);

    return 0;
}
