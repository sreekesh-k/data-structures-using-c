#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int vertex;
    struct Node *next;
};
typedef struct Node Node;

void initialize(Node *adjacencyList[], int vertices)
{
    int i;
    for (i = 0; i < vertices; ++i)
    {
        adjacencyList[i] = NULL;
    }
}

void addEdge(Node *adjacencyList[], int v1, int v2)
{

    Node *newNode1 = (Node *)malloc(sizeof(Node));
    newNode1->vertex = v2;
    newNode1->next = adjacencyList[v1];
    adjacencyList[v1] = newNode1;

    Node *newNode2 = (Node *)malloc(sizeof(Node));
    newNode2->vertex = v1;
    newNode2->next = adjacencyList[v2];
    adjacencyList[v2] = newNode2;
}

void disp(Node *adjacencyList[], int vertices)
{
    int i;
    printf("Adjacency List:\n");
    for (i = 0; i < vertices; ++i)
    {
        printf("%d -> ", i);
        Node *current = adjacencyList[i];
        while (current != NULL)
        {
            printf("%d ", current->vertex);
            current = current->next;
            if (current != NULL)
            {
                printf("-> ");
            }
        }
        printf("\n");
    }
}
int main()
{

    int v, e, i;
    printf("Enter the number of vertices: ");
    scanf("%d", &v);
    Node *adjacencyList[v];
    initialize(adjacencyList, v);
    printf("Enter the number of edges: ");
    scanf("%d", &e);
    printf("Enter the edges (vertex1 vertex2):\n");
    for (i = 0; i < e; ++i)
    {
        int vertex1, vertex2;
        scanf("%d %d", &vertex1, &vertex2);
        addEdge(adjacencyList, vertex1, vertex2);
    }
    disp(adjacencyList, v);
    return 0;
}
