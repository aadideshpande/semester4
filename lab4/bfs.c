#include<stdio.h>
#include<stdlib.h>

int queue[100];
int front = 0, rear = -1;

void push(int x)
{
    queue[++rear] = x;
}

int pop()
{
    return queue[front++];
}

int** addEdge(int x, int y, int** mat)
{
    mat[x][y] = 1;
    mat[y][x] = 1;
    return mat;
}

void Display(int v, int** mat)
{
    for(int i = 1; i <= v; i++)
    {
        for(int j = 1; j <= v; j++)
        {
            printf("%d \t", mat[i][j]);
        }
        printf("\n");
    }
}

void BFS(int v, int e, int* visited, int** mat, int s)
{
    push(s);
    visited[s] = 1;
    while(front <= rear)
    {
        s = pop();
        visited[s] = 1;
        printf("%d \t ",s);
        for(int i = 1; i <= v; i++)
        {
            if(mat[s][i] == 1 && visited[i] != 1)
            {
                push(i);
            }
        }
        
    }
    printf(" \n");
}

int main()
{
    int v,e,s;
    int v1, v2;
    printf("enter no. of vertices and edges: \n");
    scanf("%d %d", &v, &e);

    int** mat = (int **)malloc( (v + 1) * sizeof(int *));
    for(int i = 1; i < v + 1; i++)
    {
        mat[i] = (int *)calloc( (v + 1),sizeof(int));
    }

    int* visited = (int *)calloc(v + 1, sizeof(int));

    printf("enter the pairs: \n");
    int count = e;
    while(count > 0)
    {
        scanf("%d %d", &v1, &v2);
        mat = addEdge(v1, v2,mat);
        count -= 1;
    }

    Display(v, mat);

    printf("enter the starting vertex of the bfs ");
    scanf("%d", &s);
    BFS(v, e, visited, mat, s);



}