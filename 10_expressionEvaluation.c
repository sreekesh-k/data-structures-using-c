#include <stdio.h>
#include <ctype.h>
int posnum = -1, posop = -1, result, numbers[10];
char expr[20], operators[10];

// numbers(operands)stack functions
void pushnum(int e) { numbers[++posnum] = e; }
int peeknum() { return numbers[posnum]; }
int popnum() { return numbers[posnum--]; }

// operators((+-/*)) stack functions
void pushop(char e) { operators[++posop] = e; }
char peekop() { return operators[posop]; }
char popop() { return operators[posop--]; }

void calc(char c)
{
    int temp, result;
    switch (c)
    {
    case '*':
        result = (popnum()) * (popnum());
        pushnum(result);
        popop();
        break;
    case '/':
        temp = (popnum());
        result = (popnum()) / temp;
        pushnum(result);
        popop();
        break;
    case '+':
        result = (popnum()) + (popnum());
        pushnum(result);
        popop();
        break;
    case '-':
        temp = (popnum());
        result = (popnum()) - temp;
        pushnum(result);
        popop();
        break;
    }
}

int main()
{
    int i, j;
    printf("Enter expression:");
    scanf("%s", expr);
    for (i = 0; expr[i] != '\0'; i++)
    {
        if (!isdigit(expr[i]))
        {
            switch (expr[i])
            {
            case '(':
                pushop(expr[i]);
                break;
            case '*':
                if (peekop() == '*')
                    calc(peekop());
                pushop(expr[i]);
                break;
            case '/':
                if (peekop() == '*' || peekop() == '/')
                    calc(peekop());
                pushop(expr[i]);
                break;
            case '+':
                if (peekop() == '*' || peekop() == '/' || peekop() == '+')
                    calc(peekop());
                pushop(expr[i]);
                break;
            case '-':
                if (peekop() == '*' || peekop() == '/' || peekop() == '+' || peekop() == '-')
                    calc(peekop());
                pushop(expr[i]);
                break;
            case ')':
                for (j = i; operators[j] != '('; j--)
                    calc(operators[j]);
                popop();
                break;
            }
        }
        else
            pushnum(expr[i] - '0');
    }
    // left over elements
    while (posop > -1)
        calc(peekop());
    printf("Solution: %d", peeknum());
    //(2-1)*(2+1)=3; 2-1*2+1=-1; (2-1)+1+(2*2)*3=14; Bracket Mult div Add Sub
    return 0;
}
