#include <stdio.h>
char stack[30];
int top = -1;
void push(char e)
{
    stack[++top] = e;
}
void pop()
{
    top--;
}
void peak()
{
    printf("%c", stack[top]);
}
void string()
{
    int i;
    char e, str[30];
    printf("Enter a string\n");
    scanf("%s", str);
    for (i = 0; str[i] != '\0'; i++)
    {
        e = str[i];
        push(e);
    }
    printf("\nReversed String\n");
    for (i = 0; str[i] != '\0'; i++)
    {
        peak();
        pop();
    }
}
int main()
{
    string();
    return 0;
}
