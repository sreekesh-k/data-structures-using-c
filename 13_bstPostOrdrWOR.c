#include <stdio.h>
#include <stdlib.h>

struct tree
{
    int data;
    struct tree *left;
    struct tree *right;
};

typedef struct tree tree;

struct stack
{
    tree *address;
    struct stack *next;
};

typedef struct stack stack;

tree *root = NULL;
stack *top = NULL;

void push(stack **s, tree *node)
{
    stack *t = (stack *)malloc(sizeof(stack));
    t->address = node;
    t->next = *s;
    *s = t;
}

tree *pop(stack **s)
{
    tree *t = NULL;
    if (*s != NULL)
    {
        t = (*s)->address;
        *s = (*s)->next;
    }
    return t;
}

void insert(int e)
{
    tree *t = (tree *)malloc(sizeof(tree));
    t->data = e;
    t->left = NULL;
    t->right = NULL;
    if (root == NULL)
        root = t;
    else
    {
        tree *p = NULL, *x = root;
        while (x != NULL)
        {
            p = x;
            if (e == x->data)
            {
                printf("Duplication not allowed\n");
                return;
            }
            x = e > x->data ? x->right : x->left;
        }
        if (e > p->data)
            p->right = t;
        else
            p->left = t;
    }
}

void delete(int e)
{
    tree *p = NULL, *x = root, *t;
    while (x != NULL)
    {
        if (e == x->data)
            break;
        p = x;
        x = (e > x->data) ? x->right : x->left;
    }
    if (x == NULL)
        printf("Element Not found\n");
    else
    {
        printf("Element Removed\n");
        if (x->left == NULL && x->right == NULL)
        {
            if (x == root)
                root = NULL;
            else
            {
                if (p->left == x)
                    p->left = NULL;
                else
                    p->right = NULL;
            }
        }
        else if (x->left == NULL || x->right == NULL)
        {
            if (x == root)
                root = (x->left != NULL) ? x->left : x->right;
            else
            {
                if (p->left == x)
                    p->left = (x->left != NULL) ? x->left : x->right;
                else
                    p->right = (x->left != NULL) ? x->left : x->right;
            }
        }
        else
        {
            t = x->right;
            while (t->left != NULL)
                t = t->left;
            delete (t->data);
            x->data = t->data;
        }
    }
}
void postorder()
{
    stack *s1 = NULL;
    stack *s2 = NULL;
    tree *current = root;

    if (root == NULL)
        return;

    push(&s1, root);
    while (s1 != NULL)
    {
        current = pop(&s1);
        push(&s2, current);
        if (current->left != NULL)
            push(&s1, current->left);
        if (current->right != NULL)
            push(&s1, current->right);
    }

    while (s2 != NULL)
    {
        current = pop(&s2);
        printf("%d ", current->data);
    }
}

int main()
{
    int ch;
    while (ch)
    {
        printf("___________________________________________\n");
        printf("1.Insert\t2.Delete\n3.Post-order\t4.Exit\n");
        scanf("%d", &ch);
        if (ch == 4)
            break;
        switch (ch)
        {
        case 1:
            printf("Enter Element To Insert: ");
            scanf("%d", &ch);
            insert(ch);
            break;
        case 2:
            printf("Enter Element To Delete: ");
            scanf("%d", &ch);
            delete (ch);
            break;
        case 3:
            printf("Postorder (without using recursion): ");
            postorder();
            printf("\n");
            break;
        default:
            printf("Choose 1-5 only\n");
        }
    }
    return 0;
}
