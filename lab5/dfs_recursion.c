#include<stdio.h>
#include<stdlib.h>

int s,v,e;
int mat[100][100];
int visited[100] = {0};
int myarray[100] = {0};
int x = 1;

void addEdge(int x, int y)
{
    mat[x][y] = 1;
    //mat[y][x] = 1;
    
}

void Display(int v)
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

void dfs(int s)
{
	int i;
	visited[s] = 1;
	printf("%d \t",s );
	//while(1)
	//{
		for(i = 1; i <= v; i++)
		{
			if(mat[s][i] == 1 && visited[i] == 0)
			{
				dfs(i);
				myarray[x++] = i;
				
			}
		}

		//return;
	//}
	//printf("\n");
}

void Print()
{
    printf("the topological order is: \n");
    for(int i = v; i > 0; i--)
    {
        printf("%d \t",myarray[i]);
    }
    printf("\n");
}


int main()
{
    int v1, v2;
    printf("enter no. of vertices and edges: \n");
    scanf("%d %d", &v, &e);




    printf("enter the pairs: \n");
    int count = e;
    while(count > 0)
    {
        scanf("%d %d", &v1, &v2);
        addEdge(v1, v2);
        count -= 1;
    }

    Display(v);

    printf("enter the starting vertex of the dfs ");
    scanf("%d", &s);
    dfs(s);
    myarray[x++] = s;
    printf("\n");
    Print();
}