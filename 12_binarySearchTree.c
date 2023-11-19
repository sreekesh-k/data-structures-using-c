#include <stdio.h>
#include <stdlib.h>

struct tree
{
    int data;
    struct tree *left;
    struct tree *right;
};
typedef struct tree tree;
tree *root = NULL;
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
        printf("Element Not found\n"); // not found
    else
    {
        printf("Element Removed\n");
        if (x->left == NULL && x->right == NULL) // no child
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
        else if (x->left == NULL || x->right == NULL) // one child
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
        else // 2 child
        {
            t = x->right;
            while (t->left != NULL)
                t = t->left;
            delete (t->data);
            x->data = t->data;
        }
    }
}
void inorder(tree *r)
{
    if (r != NULL)
    {
        inorder(r->left);
        printf("%d ", r->data);
        inorder(r->right);
    }
}
void preorder(tree *r)
{
    if (r != NULL)
    {
        printf("%d ", r->data);
        preorder(r->left);
        inorder(r->right);
    }
}
void postorder(tree *r)
{
    if (r != NULL)
    {
        inorder(r->left);
        inorder(r->right);
        printf("%d ", r->data);
    }
}
int main()
{
    int ch;
    while (ch)
    {
        printf("___________________________________________\n");
        printf("1.Insert\t2.Delete\n3.Display\t4.Exit\n");
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
            printf("Inorder: ");
            inorder(root);
            printf("\n");
            printf("Preorder: ");
            preorder(root);
            printf("\n");
            printf("Postorder: ");
            postorder(root);
            printf("\n");
            break;
        default:
            printf("Choose 1-5 only\n");
        }
    }
    return 0;
}
