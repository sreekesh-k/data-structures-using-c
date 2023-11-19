#include <stdio.h>
#define M 100
int i, j;
void initialize(int matrix[M][M], int vertices)
{
    for (i = 0; i < vertices; ++i)
    {
        for (j = 0; j < vertices; ++j)
        {
            matrix[i][j] = 0;
        }
    }
}

void addEdge(int matrix[M][M], int vertices, int v1, int v2)
{
    if (v1 >= 0 && v1 < vertices && v2 >= 0 && v2 < vertices)
    {
        matrix[v1][v2] = 1;
        matrix[v2][v1] = 1;
    }
    else
    {
        printf("Invalid vertices\n");
    }
}

void disp(int matrix[M][M], int vertices)
{
    printf("Adjacency Matrix:\n");
    for (i = 0; i < vertices; ++i)
    {
        for (j = 0; j < vertices; ++j)
        {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}
int main()
{
    int v, e;
    printf("Enter the number of vertices: ");
    scanf("%d", &v);
    int adjacencyMatrix[M][M];
    initialize(adjacencyMatrix, v);
    printf("Enter the number of edges: ");
    scanf("%d", &e);
    printf("Enter the edges (vertex1 vertex2):\n");
    for (i = 0; i < e; ++i)
    {
        int vertex1, vertex2;
        scanf("%d %d", &vertex1, &vertex2);
        addEdge(adjacencyMatrix, v, vertex1, vertex2);
    }
    disp(adjacencyMatrix, v);
    return 0;
}
